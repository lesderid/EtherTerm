
// EtherTerm SVN: $Id$
// Source: $HeadURL$
// $LastChangedDate$
// $LastChangedRevision$
// $LastChangedBy$

#include "mainMenuState.h"
#include "menuFunction.h"
#include "inputHandler.h"
#include "terminal.h"
#include "telnetState.h"
#include "sshState.h"
#include "ansiParser.h"
#include "tinyxml.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

const std::string MainMenuState::menuID = "MENU";

// Callbacks
void MainMenuState::menuToTelnet()
{
    TheTerminal::Instance()->getStateMachine()->changeState(new TelnetState());
}

void MainMenuState::menuToSSH()
{
    TheTerminal::Instance()->getStateMachine()->changeState(new SSHState());
}
// end callbacks

void MainMenuState::update()
{
    TheTerminal::SystemConnection sysCon;
    int ret = 0;
    if(!TheInputHandler::Instance()->isGlobalShutdown())
    {
        ret = startDialDirectory();
        switch(ret)
        {
            case EOF:
                // default.
                TheTerminal::Instance()->setCurrentFont("vga8x16.bmp");
                if(TheTerminal::Instance()->didFontChange())
                    TheTerminal::Instance()->loadBitmapImage(TheTerminal::Instance()->getCurrentFont());

                MenuFunction::displayAnsiFile("outro.ans");
                SDL_Delay(1500);
                TheTerminal::Instance()->quit();
                break;

            default:
                sysCon = TheTerminal::Instance()->getSystemConnection();                                                    
                if(sysCon.protocol == "TELNET")
                {
                    TheTerminal::Instance()->setCurrentFont(sysCon.font);
                    if(TheTerminal::Instance()->didFontChange())
                        TheTerminal::Instance()->loadBitmapImage(TheTerminal::Instance()->getCurrentFont());
                    menuToTelnet();
                }
                else if(sysCon.protocol == "SSH")
                {
                    TheTerminal::Instance()->setCurrentFont(sysCon.font);
                    if(TheTerminal::Instance()->didFontChange())
                        TheTerminal::Instance()->loadBitmapImage(TheTerminal::Instance()->getCurrentFont());
                    menuToSSH();
                }
                break;
        }
    }
    else
        TheTerminal::Instance()->quit();
    // Delay in Menu Loop for Input, for CPU Usage.
    SDL_Delay(10);
}

bool MainMenuState::onEnter()
{
    TheAnsiParser::Instance()->setCursorActive(false);

    // Setup Defaults for Interface.
    directoryTopMargin = 1;
    directoryBottomMargin = 1;
    LIGHTBAR_POSITION = 0;
    std::cout << "entering MainMenuState\n";
    // Set Render to Ready so we draw menu, Once it's drawn we toggle
    // This off, so it doesn't keep looping since it's not a game
    // with animation, this saves cpu usage.
    TheTerminal::Instance()->clearSystemConnection();
    return true;
}

bool MainMenuState::onExit()
{
    // reset the input handler
    TheInputHandler::Instance()->reset();
    // Clear Dialing directory
    systemConnection.clear();
    std::vector<TheTerminal::SystemConnection>().swap(systemConnection);
    std::cout << "exiting MainMenuState\n";
    return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
{

}

/**
 * Start of Dial-directory INI Class
 */
bool MainMenuState_INI::ddirectory_exists()
{
    std::cout << "ddirectory_exists()" << std::endl;
    TOP_MARGIN = 0;
    BOTTOM_MARGIN = 0;

    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif

    path += INI_NAME;
    FILE *stream;
    stream = fopen(path.c_str(),"rb+");
    if(stream == nullptr)
    {
        printf("Error unable to read dialdirectory.ini, check permissions!");
        return false;
    }
    fclose(stream);
    return true;
}

/**
 * Create INI File
 */
void MainMenuState_INI::ddirectory_create()
{
    //std::cout << "ddirectory_create()" << std::endl;
    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif
    path += INI_NAME;
    std::ofstream outStream2;
    outStream2.open(path.c_str(), std::ofstream::out | std::ofstream::trunc);
    if(!outStream2.is_open())
    {
        printf("\nError Creating: %s \n", path.c_str());
        return;
    }
    outStream2 << " * Generated By Program. " << std::endl;
    outStream2.close();
    return;
}

/**
 * Parse Helper
 */
void MainMenuState_INI::ddirectory_chkpar(std::string &data)
{
    //std::cout << "ddirectory_chkpar()" << std::endl;
    std::string temp1;
    std::string::size_type st1 = 0;
    std::string::size_type st2 = 0;
    std::string::size_type  ct = 0;

    st1 = data.find('"', 0);
    st2 = data.find('"', st1+1);
    ++st1;
    temp1 = data.substr(st1,st2);
    ct = st2 - st1;
    if(temp1.length() > ct)
        temp1.erase(ct,temp1.length());
    data = temp1;
}

/**
 * Get INI Values
 */
void MainMenuState_INI::ddirectory_check(std::string cfgdata)
{
    //std::cout << "ddirectory_check()" << std::endl;
    std::string::size_type id1 = 0;
    std::string temp = cfgdata;

    if(temp[0] == '#')
        return;
    else if(temp.find("set TOP ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        id1 = atoi(temp.c_str());
        TOP_MARGIN = id1;
    }
    else if(temp.find("set BOT ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        id1 = atoi(temp.c_str());
        BOTTOM_MARGIN = id1;
    }
    else if(temp.find("set THEME_NAME ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        THEME_NAME = temp;
    }
    else if(temp.find("set FONT_SET ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        FONT_SET = temp;
    }
    else if(temp.find("set ANSI_FILE ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        ANSI_FILE = temp;
    }
    else if(temp.find("set MENU_PROMPT ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        MENU_PROMPT_TEXT = temp;
    }
    else if(temp.find("set PAGENUM ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        PAGE_NUMBER = temp;
    }
    else if(temp.find("set PAGETOTAL ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        PAGE_TOTAL = temp;
    }
    else if(temp.find("set MOREMSG_ON ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        MORE_MESSAGE_ON = temp;
    }
    else if(temp.find("set MOREMSG_WORD_ON ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        MORE_MESSAGE_TEXT_ON = temp;
    }
    else if(temp.find("set MOREMSG_OFF ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        MORE_MESSAGE_OFF = temp;
    }
    else if(temp.find("set MOREMSG_WORD_OFF ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        MORE_MESSAGE_TEXT_OFF = temp;
    }
    else if(temp.find("set TEXT_COLOR ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        TEXT_COLOR = temp;
    }
    else if(temp.find("set MAX_AREAS ", 0) != std::string::npos)
    {
        ddirectory_chkpar(temp);
        MAX_SYSTEMS = temp;
    }
}

/**
 * Read / Parse INI File
 */
bool MainMenuState_INI::ddirectory_parse(int index)
{
    //std::cout << "ddirectory_parse()" << std::endl;
    if(!ddirectory_exists())
    {
        printf("Error unable to parse dialdirectory.ini, check permissions!");
    }
    //ddirectory_create();
    char name[1024]  = {0};
    char name2[1024] = {0};

    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif

    // Set for Theme, check index number for themes,.
    sprintf(name, "%s%s",path.c_str(),INI_NAME);
    sprintf(name2,"%s%s%i.ini",path.c_str(),INI_NAME,index);
    if(index != 0) strcpy(name,name2);
    // Check if Theme Exists, if not return FALSE.

    std::cout << "Read dialdirectory.ini: " << name << std::endl;

    FILE *stream;
    stream = fopen(name,"rb+");
    if(stream == nullptr)
    {
        // File is not Present
        return false;
    }
    fclose(stream);

    std::ifstream inStream;
    inStream.open(name);
    if(!inStream.is_open())
    {
        printf("Unable to open configuration file: %s\n", name);
        return false;
    }

    std::string cfgdata;
    for(;;)
    {
        std::getline(inStream,cfgdata,'\n');
        ddirectory_check(cfgdata);
        if(inStream.eof()) break;
    }
    inStream.close();
    return true;
}

/**
 * Reads in ANSI file into Buffer Only
 */
void MainMenuState::readinAnsi(std::string FileName, std::string &buff)
{
    std::cout << "readinAnsi()" << std::endl;
    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif

    path += FileName;
    path += ".ans";
    FILE *fp;

    std::cout << "Load ANSI: " << path << std::endl;

    int sequence = 0;
    if((fp = fopen(path.c_str(), "r+")) ==  nullptr)
    {
        std::cout << "ANSI not found: " << path << std::endl;
        return;
    }
    do
    {
        sequence = getc(fp);
        if(sequence != EOF)
            buff += (char)sequence;
    }
    while(sequence != EOF);
    fclose(fp);
}

/**
 * Dial-directory - Parse ANSI Template
 */
void MainMenuState::parseHeader(std::string FileName)
{
    std::cout << "parseHeader()" << std::endl;
    std::cout << "sFONT_SET: " << FONT_SET << std::endl;

    // Set the font type for the menu being displayed.
    TheTerminal::Instance()->setCurrentFont(FONT_SET);

    // Test if font changed, if so, then re-load it.
    if(TheTerminal::Instance()->didFontChange())
        TheTerminal::Instance()->loadBitmapImage(TheTerminal::Instance()->getCurrentFont());

    TheAnsiParser::Instance()->reset();
    MenuFunction::displayAnsiFile(FileName);
}

/**
 * Dial-directory - Setup Reading INI File and init Theme
 */
void MainMenuState::setupList()
{
    sprintf(INI_NAME,"%s",(char *)"dialdirectory.ini");
    ddirectory_parse();
    directoryTopMargin = TOP_MARGIN;
    directoryBottomMargin = BOTTOM_MARGIN;
}

/**
 * Dial-directory - Change ANSI Template Theme
 */
bool MainMenuState::changeTheme(int index)
{
    if(!ddirectory_parse(index))
    {
        // Theme Doesn't Exist.
        return false;
    }
    _linkList.topMargin = TOP_MARGIN;
    _linkList.bottomMargin = BOTTOM_MARGIN;
    return true;
}

/**
 * Build Phone-book with List of Systems
 * This function creates 4 versions of each line,
 * one for default, default selected, new, then new selected.
 * This doesn't mark which are new or to be used.
 */
std::vector< list_bar > MainMenuState::buildDialList()
{
    list_bar                 _lightbar;
    std::vector<list_bar>    result;

    int sequence = 0;
    std::string stringBuilder = "";

    FILE               *inStream;
    long index          = 1;
    char mciCode[3]     = {0};
    char temp2[100]     = {0};
    int  padding        = 0;
    bool isRightPadding = false;
    bool isLeftPadding  = false;

    std::string currnetScreen  = "";
    std::string ansiScreen1 = "";
    std::string ansiScreen2 = "";

    // Pre-fetch ANSI light bar themes
    // These ANSI are used as the light bars to be displayed,
    // We rotate between 2 ANSI light bars.
    // 1. Un-selected Systems
    // 4. Current System Selected
    //
    // We cache array with all four choices so we can
    // easily switch between them in the listing.
    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif
    path += "ddirectorymid1.ans";
    if((inStream = fopen(path.c_str(), "r+")) ==  nullptr)
    {
        std::cout << "unable to read " <<  "ddirectorymid1.ans" << std::endl;
        return result;
    }
    while(sequence != EOF)
    {
        sequence = getc(inStream);
        if(sequence != EOF) ansiScreen1 += sequence;
    }
    fclose(inStream);
    sequence = '\0';

    path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif

    path += "ddirectorymid2.ans";
    if((inStream = fopen(path.c_str(), "r+")) ==  nullptr)
    {
        std::cout << "unable to read " <<  "ddirectorymid2.ans" << std::endl;
        return result;
    }
    while(sequence != EOF)
    {
        sequence = getc(inStream);
        if(sequence != EOF) ansiScreen2 += sequence;
    }
    fclose(inStream);

    unsigned long maxSystems    = 0;
    unsigned long currentSystem = 0;
    maxSystems = systemConnection.size();
    std::cout << "systemConnection.size(): " << systemConnection.size() << std::endl;

    int counter = 0;
    while(currentSystem < maxSystems)
    {
        if(currentSystem == maxSystems) break;
        stringBuilder.erase();
        for(int ansiCount = 0; ansiCount < 2; ansiCount++)
        {
            switch(ansiCount)
            {
                case 0:
                    currnetScreen = ansiScreen2;
                    break; // Display High-light None.  ON

                case 1:
                    currnetScreen = ansiScreen1;
                    break; // Display Low-light None    OFF

                default:
                    break;
            }
            counter = 0;
            sequence = 0;
            // Parse MCI Codes per each light bar ANSI file
            do
            {
                memset(&mciCode,0,sizeof(mciCode));
                sequence = currnetScreen[counter];
                if(sequence == '\0') break;
                // Check for Spacing MCI Code
                switch(sequence)
                {
                    case '{' : // Left Justify
                        mciCode[0] = currnetScreen[++counter];
                        mciCode[1] = currnetScreen[++counter];
                        padding = atoi(mciCode);
                        if(padding != 0)
                        {
                            isLeftPadding = true;
                        }
                        else
                        {
                            stringBuilder += sequence;
                            stringBuilder += mciCode;
                        }
                        break;

                    case '}' : // Right Justify
                        mciCode[0] = currnetScreen[++counter];
                        mciCode[1] = currnetScreen[++counter];
                        padding = atoi(mciCode);
                        if(padding != 0)
                        {
                            isRightPadding = true;
                        }
                        else
                        {
                            stringBuilder += sequence;
                            stringBuilder += mciCode;
                        }
                        break;

                    case '|' : // Pipe Codes
                        mciCode[0] = currnetScreen[++counter];
                        mciCode[1] = currnetScreen[++counter];
                        if(strcmp(mciCode,"##") == 0)
                        {
                            sprintf(temp2,"%lu", currentSystem+1);
                            if(isLeftPadding)
                            {                                
                                MenuFunction::leftSpacing(temp2,padding);
                                std::string stringReplace = temp2;
                                std::replace(
                                    stringReplace.begin(), stringReplace.end(), ' ', '.');
                                isLeftPadding = false;
                                stringBuilder += stringReplace;
                            }
                            else if(isRightPadding)
                            {                                
                                MenuFunction::rightSpacing(temp2,padding);
                                std::string stringReplace = temp2;
                                std::replace(
                                    stringReplace.begin(), stringReplace.end(), ' ', '.');
                                isRightPadding = false;
                                stringBuilder += stringReplace;
                            }                            
                        }
                        else if(strcmp(mciCode,"NA") == 0)
                        {
                            sprintf(temp2,"%s",systemConnection[currentSystem].name.c_str());
                            if(isLeftPadding)
                            {
                                MenuFunction::leftSpacing(temp2,padding);
                                isLeftPadding = false;
                            }
                            else if(isRightPadding)
                            {
                                MenuFunction::rightSpacing(temp2,padding);
                                isRightPadding = false;
                            }
                            stringBuilder += temp2;
                        }
                        else if(strcmp(mciCode,"FO") == 0)
                        {
                            // FIXME Temp - Translate File-name to Description
                            // Will add to the xml once it's ready.
                            if(systemConnection[currentSystem].font == "vga8x16.bmp")
                                sprintf(temp2,"%s",(char *)"IBM-PC CP437 VGA  8x16");
                            else if(systemConnection[currentSystem].font == "topazPlus-8x16.bmp")
                                sprintf(temp2,"%s",(char *)"AMIGA Topaz+ 1200 8x16");

                            //sprintf(temp2,"%s",systemConnection[currentSystem].font.c_str());
                            if(isLeftPadding)
                            {
                                MenuFunction::leftSpacing(temp2,padding);
                                isLeftPadding = false;
                            }
                            else if(isRightPadding)
                            {
                                MenuFunction::rightSpacing(temp2,padding);
                                isRightPadding = false;
                            }
                            stringBuilder += temp2;
                        }
                        else if(strcmp(mciCode,"PO") == 0)
                        {
                            sprintf(temp2,"%i",
                                systemConnection[currentSystem].port);
                            if(isLeftPadding)
                            {
                                MenuFunction::leftSpacing(temp2,padding);
                                isLeftPadding = false;
                            }
                            else if(isRightPadding)
                            {
                                MenuFunction::rightSpacing(temp2,padding);
                                isRightPadding = false;
                            }
                            stringBuilder += temp2;
                        }
                        else if(strcmp(mciCode,"PR") == 0)
                        {
                            sprintf(temp2,"%s",
                                systemConnection[currentSystem].protocol.c_str());
                            if(isLeftPadding)
                            {
                                MenuFunction::leftSpacing(temp2,padding);
                                isLeftPadding = false;
                            }
                            else if(isRightPadding)
                            {
                                MenuFunction::rightSpacing(temp2,padding);
                                isRightPadding = false;
                            }
                            stringBuilder += temp2;
                        }                        
                        else if(strcmp(mciCode,"KM") == 0)
                        {
                            sprintf(temp2,"%s",(char *)
                                systemConnection[currentSystem].keyMap.c_str());
                            if(isLeftPadding)
                            {
                                MenuFunction::leftSpacing(temp2,padding);
                                isLeftPadding = false;
                            }
                            else if(isRightPadding)
                            {
                                MenuFunction::rightSpacing(temp2,padding);
                                isRightPadding = false;
                            }
                            stringBuilder += temp2;
                        }
                        else
                        {
                            stringBuilder += sequence;
                            stringBuilder += mciCode;
                        }
                        break;

                    case '\n' :
                        //  stringBuilder += '\r';
                        break;

                    default :
                        stringBuilder += sequence;
                        break;
                }
                ++counter;
            }
            while(sequence != '\0');

            stringBuilder += "\r";
            switch(ansiCount)
            {
                case 0:
                    _lightbar.ansiString2 = stringBuilder;
                    break; // Display High-light None.  ON
                case 1:
                    _lightbar.ansiString1 = stringBuilder;
                    break; // Display Low-light None    OFF

                default:
                    break;
            }
            stringBuilder.erase();
        } // End of (4) Look for each string.
        result.push_back(_lightbar);
        stringBuilder.erase();
        ++currentSystem;
        ++index;
    }
    return result;
}

/*
 * Read All Systems in Dialing Directory
 */
bool MainMenuState::readDialDirectory()
{
    TheTerminal::SystemConnection sysconn;
    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif
    path += "dialdirectory.xml";
    TiXmlDocument doc(path.c_str());
    if(!doc.LoadFile()) return false;
    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    // If vector already populated then clear to refresh it.
    if(systemConnection.size() >0)
    {
        systemConnection.clear();
        std::vector<TheTerminal::SystemConnection>().swap(systemConnection);
    }
    // block: EtherTerm
    {
        std::cout << "readDialDirectory - FirstChildElement" << std::endl;
        pElem=hDoc.FirstChildElement().Element();
        // should always have a valid root but handle gracefully if it does
        if(!pElem)
        {
            std::cout << "readDialDirectory - EtherTerm Element not found!" << std::endl;
            return false;
        }
        std::cout << "Root Value: " << pElem->Value() << std::endl;
        // save this for later
        hRoot=TiXmlHandle(pElem);
    }
    // block: Phone-book
    {
        //std::cout << "readDialDirectory - Phonebook" << std::endl;
        pElem=hRoot.FirstChild("Phonebook").Element();
        std::cout << "Phonebook Version: " << pElem->Attribute("version") << std::endl;
    }
    // block: BBS
    {
        //std::cout << "readDialDirectory - BBS" << std::endl;
        pElem=hRoot.FirstChild("Phonebook").FirstChild().Element();
        for(; pElem; pElem=pElem->NextSiblingElement())
        {
            sysconn.name = pElem->Attribute("name");
            sysconn.ip = pElem->Attribute("ip");
            pElem->QueryIntAttribute("port", &sysconn.port);
            sysconn.protocol = pElem->Attribute("protocol");
            sysconn.login = pElem->Attribute("login");
            sysconn.password = pElem->Attribute("password");
            sysconn.font = pElem->Attribute("font");
            sysconn.keyMap = pElem->Attribute("keyMap");
            // Add to Vector so we can parse in building the dialing directory.
            systemConnection.push_back(sysconn);
        }
    }
    std::cout << "readDialDirectory - Done" << std::endl;
    return true;
}

/*
 * Create a new initial dialing directory.
 */
void MainMenuState::createDialDirectory()
{
    // Create Default Phone Book.
    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif
    path += "dialdirectory.xml";

    TiXmlDocument doc;
    TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "", "");
    doc.LinkEndChild(decl);

    TiXmlElement * element = new TiXmlElement("EtherTerm");
    doc.LinkEndChild(element);

    TiXmlElement * element2 = new TiXmlElement("Phonebook");
    element->LinkEndChild(element2);
    element2->SetAttribute("version", "1.0");

    TiXmlElement * element3 = new TiXmlElement("BBS");
    element2->LinkEndChild(element3);

    element3->SetAttribute("name", "Haunting The Chapel");
    element3->SetAttribute("ip", "htc.zapto.org");
    element3->SetAttribute("port", "23");
    element3->SetAttribute("protocol", "TELNET");
    element3->SetAttribute("login", "");
    element3->SetAttribute("password", "");
    element3->SetAttribute("font", "vga8x16.bmp");
    element3->SetAttribute("keyMap", "ANSI");

    TiXmlElement *element4 = new TiXmlElement("BBS");
    element2->LinkEndChild(element4);

    element4->SetAttribute("name", "1984");
    element4->SetAttribute("ip", "1984.ws");
    element4->SetAttribute("port", "23");
    element4->SetAttribute("protocol", "TELNET");
    element4->SetAttribute("login", "");
    element4->SetAttribute("password", "");
    element4->SetAttribute("font", "vga8x16.bmp");
    element4->SetAttribute("keyMap", "VT100");
    doc.SaveFile(path.c_str());
}

/*
 * Write All connections to the dialing directory
 */
void MainMenuState::writeDialDirectory()
{
    // Create Default Phone Book.
    std::string path = TheTerminal::Instance()->getProgramPath();
#ifdef _WIN32
    path += "assets\\";
#else
    path += "assets/";
#endif
    path += "dialdirectory.xml";

    TiXmlDocument doc;
    TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "", "");
    doc.LinkEndChild(decl);

    TiXmlElement *root = new TiXmlElement("EtherTerm");
    doc.LinkEndChild(root);

    TiXmlElement *phonebook = new TiXmlElement("Phonebook");
    root->LinkEndChild(phonebook);
    phonebook->SetAttribute("version", "1.0");

    // Loop and write out all System Connections
    for (auto &it : systemConnection)
    {
        TiXmlElement *system = new TiXmlElement("BBS");
        phonebook->LinkEndChild(system);

        system->SetAttribute("name", it.name);
        system->SetAttribute("ip", it.ip);
        system->SetAttribute("port", it.port);
        system->SetAttribute("protocol", it.protocol);
        system->SetAttribute("login", it.login);
        system->SetAttribute("password", it.password);
        system->SetAttribute("font", it.font);
        system->SetAttribute("keyMap", it.keyMap);
    }

    doc.SaveFile(path.c_str());
}



/**
 * Title Scan - Start Interface
 */
int MainMenuState::startDialDirectory()
{
    int  currentPage  = 0;
    int  boxsize      = 0;

    // Reading in dial-directory.ini values.
    setupList();
    std::cout << "ANSI File: "<< ANSI_FILE << std::endl;

    _linkList.topMargin = directoryTopMargin;
    _linkList.bottomMargin = directoryBottomMargin;

    // Build Title Scan into Vector List
    std::vector<list_bar> result;
    std::string inputSequence;

    // Read-in or Crete Dialing Directory.
    if(!readDialDirectory())
    {
        createDialDirectory();
        if(!readDialDirectory())
        {
            cout << "Error: unable to create and rea dialdirectory.xml" << std::endl;
            return -1;
        }
    }
    result = buildDialList();
    // populate list with vector class
    _linkList.getVectorList(result);

    std::string outputBuffer;
    char outBuffer[1024]= {0};
    char mString[10]= {0};
    char rBuffer[1024]= {0};
    unsigned char ch = '\0';
    std::string tmp;

    // To Start out, keep this static later on for next call.
    LIGHTBAR_POSITION = 0;

    // Loop Light bar Interface.
    do
    {
        parseHeader(ANSI_FILE);

        // Jump to Current Page
        boxsize = _linkList.bottomMargin - _linkList.topMargin;
        currentPage = LIGHTBAR_POSITION / boxsize;

        //  Make sure we have areas.
        if(result.size() > 0)
        {
            //std::cout << "box_start_vector(currentPage, LIGHTBAR_POSITION);" << std::endl;
            _linkList.drawVectorList(currentPage, LIGHTBAR_POSITION);
        }
        else
        {
            // No Systems, return.
            return EOF;
        }

        _linkList.totalLines = result.size();
        do
        {
            outputBuffer.erase();
            outputBuffer = "|16"; // Clear Color Bleeding, reset background to black.

            // Show Current/Total Pages in Dialing Directory
            sprintf(outBuffer,"%s%.3d",(char *)PAGE_NUMBER.c_str(),_linkList.currentPage+1);
            outputBuffer += outBuffer;
            sprintf(outBuffer,"%s%.3d",(char *)PAGE_TOTAL.c_str(),_linkList.totalPages);
            outputBuffer += outBuffer;

            // # of Systems in Dialing Directory
            sprintf(outBuffer,"%s%.3d",(char *)MAX_SYSTEMS.c_str(),_linkList.totalLines);
            outputBuffer += outBuffer;
            MenuFunction::sequenceToAnsi((char *)outputBuffer.c_str());

            _menuFunction._curmenu.clear();
            _menuFunction._curmenu = MENU_PROMPT_TEXT;
JMPINPUT1:
            _menuFunction.menuStart();
            _menuFunction.menuProcess(mString, LIGHTBAR_POSITION);
            //std::cout << "mString: " << mString << std::endl;

             // Get Command Key returned from Menu
            ch = mString[1];

            if(mString[0] == '!')
            {
                switch(toupper(ch))
                {
                    case 'U': // Page Up
                        if(currentPage != 0)
                        {
                            --currentPage;
                            // reset Bar to first Listing on each Page.
                            LIGHTBAR_POSITION = currentPage * boxsize;
                            _linkList.drawVectorList(currentPage,LIGHTBAR_POSITION);
                        }
                        else
                            goto JMPINPUT1;
                        break;

                    case 'D': // Page Down
                        if(currentPage+1 != _linkList.totalPages)
                        {
                            ++currentPage;
                            // reset Bar to first Listing on each Page.
                            LIGHTBAR_POSITION = currentPage * boxsize;
                            _linkList.drawVectorList(currentPage,LIGHTBAR_POSITION);
                        }
                        else
                            goto JMPINPUT1;
                        break;

                        // hit ENTER
                    case 'E': // Selected Current System to Dial
                        _linkList.clearVectorList();
                        std::vector<list_bar>() . swap(result); // Free Vector Up.
                        // Pass the selected system to the TERM Instance so we can
                        // Pull it inside the TelnetState.
                        TheTerminal::Instance()->setSystemConnection(systemConnection[LIGHTBAR_POSITION]);
                        return LIGHTBAR_POSITION;

                    case '+': // Next Message - Move Down

                        if(LIGHTBAR_POSITION+1 >= _linkList.listing.size() || _linkList.listing.size() == 0)
                            goto JMPINPUT1;
                        //std::cout << "Move to next bar." << std::endl;
                        ++LIGHTBAR_POSITION;
                        //Calculate if we go down, ++Current Area, are we on next page or not.
                        // Because 0 Based, need to add +1
                        // Test if we moved to next page.
                        if((signed)LIGHTBAR_POSITION+1 < (boxsize*(currentPage+1))+1)
                        {
                            // Low-light Current, then Highlight Next.
                            sprintf(rBuffer, "\x1b[%i;%iH|16%s",
                                _linkList.currentSelection, 1, (char *)_linkList.listing[LIGHTBAR_POSITION-1].ansiString1.c_str());

                            outputBuffer += rBuffer;
                            _linkList.currentSelection += 1;

                            sprintf(rBuffer, "\x1b[%i;%iH|16%s",
                                _linkList.currentSelection, 1, (char *)_linkList.listing[LIGHTBAR_POSITION].ansiString2.c_str());

                            outputBuffer += rBuffer;
                            MenuFunction::sequenceToAnsi((char *)outputBuffer.c_str());
                            outputBuffer.erase();
                            goto JMPINPUT1; //Not moving down a page.
                        }
                        else
                        {
                            // Move to next Page!
                            ++currentPage;
                            _linkList.drawVectorList(currentPage,LIGHTBAR_POSITION);
                            break;
                        }
                    case '-': // Previous Message - Move Up

                        // Skipping to JMPINPUT bypasses redraws, much faster!
                        if(LIGHTBAR_POSITION > 0 && _linkList.listing.size() != 0)
                            --LIGHTBAR_POSITION;
                        else
                            goto JMPINPUT1;

                        //Calculate if we go down, --Current Area, are we on next page or not.
                        // Because 0 Based, need to add +1
                        // Test if we moved to next page.
                        if((signed)LIGHTBAR_POSITION+1 > (boxsize*(currentPage)))
                        {
                            // Still on Same Page
                            // Low-light Current, then Highlight Next.
                            sprintf(rBuffer, "\x1b[%i;%iH|16%s", _linkList.currentSelection, 1, (char *)_linkList.listing[LIGHTBAR_POSITION+1].ansiString1.c_str());
                            outputBuffer = rBuffer;
                            _linkList.currentSelection -= 1;

                            sprintf(rBuffer, "\x1b[%i;%iH|16%s", _linkList.currentSelection, 1, (char *)_linkList.listing[LIGHTBAR_POSITION].ansiString2.c_str());
                            outputBuffer += rBuffer;
                            MenuFunction::sequenceToAnsi((char *)outputBuffer.c_str());
                            outputBuffer.erase();
                            goto JMPINPUT1; //Not moving down a page.
                        }
                        else
                        {
                            // Move to next Page!
                            --currentPage;
                            _linkList.drawVectorList(currentPage,LIGHTBAR_POSITION);
                        }
                        break;

                    case 'Q': // Quit Received, Hard Exit.
                        _linkList.clearVectorList();
                        std::vector<list_bar>() . swap(result); // Free Vector Up.
                        return EOF;

                    case '?': // Directory Help
  //                    ansiPrintf(sANSI_HELP); // Display ANSI Help file,
                        //getkey(true);
                        parseHeader(ANSI_FILE); // Re-display Display ANSI
                        _linkList.drawVectorList(currentPage,LIGHTBAR_POSITION);
                        break;

                    case 'A': // About
                        parseHeader((char *)"about.ans"); // Re-display Display ANSI
                        // Wait for input:
                        //std::cout << "Menu Bars Input Loop" << std::endl;
                        MenuFunction::getKey();
                        parseHeader((char *)"about2.ans"); // Re-display Display ANSI
                        MenuFunction::getKey();
                        // If Global Exit, return right away.
                        if(TheInputHandler::Instance()->isGlobalShutdown())
                        {
                            _linkList.clearVectorList();
                            std::vector<list_bar>() . swap(result); // Free Vector Up.
                            return EOF;
                        }
                        parseHeader((char *)"et2.ans"); // Re-display Display ANSI
                        _linkList.drawVectorList(currentPage,LIGHTBAR_POSITION);
                        break;
                        // Pass through, any functionally that should
                        // Be handled in Reader.
                        // to the Message Reader. ie post ,reply, delete...

                    default :
                        _linkList.clearVectorList();
                        std::vector<list_bar>() . swap(result); // Free Vector Up.
                        break;
                        // Don't exit, just return with pass through command.
                        //return (char)toupper(ch);
                }
            }
        }
        while(!TheInputHandler::Instance()->isGlobalShutdown());   // End do
    }
    while(!TheInputHandler::Instance()->isGlobalShutdown());   // End do
    return -1;
}
