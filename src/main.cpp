
/**
 * EtherTerm (c) 2014-2018 Michael Griffin <mrmisticismo@hotmail.com>
 * An Emulated Client Terminal in SDL 2.0 supporting Telnet and SSH and more.
 * With CP437 Character and ANSI Graphics Support.
 *
 * Linker Options: -mwindows to remove Console Debug Window (WIN32)
 *
 * EtherTerm is available under the zlib license :
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#include "interface.hpp"

#include <unistd.h>
#include <sys/types.h>

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#ifdef TARGET_OS_MAC // OSX
#include <mach-o/dyld.h>

#elif _WIN32 // Windows
#include <SDL2/SDL_Main.h>
#include <winsock2.h>
#include <windows.h>
#else
#endif

#include <SDL2_net/SDL_net.hpp>

#include <cstdio>
#include <cstring>
#include <climits>
#include <unistd.h>

#include <string>
#include <iostream>
#include <memory>

/**
 * @brief Initial Startup for SDL with Video
 * @return
 */
bool SDLStartUp()
{
    bool success = true;

    // Initialize SDL w/ Video, Skip Sound and Controllers for now.
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }

    if(SDLNet_Init()==-1)
    {
        std::cout << "SDL_Net could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        exit(2);
    }

    // Turn off, might make a toggle for this later on.
    SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");

    return success;
}

/*
 *  Main Program Entrance
 */
int main(int argc, char* argv[])
{
    bool is_headless = false;
    SDL_SetMainReady();
    /*
     * Interfaces to be added later on
     * h = headless
     * t = telnet
     * s = secure ssl/ssh
     * f = ftp
     * i = irc
     */
    int c = 0;
    while((c = getopt(argc, argv, "h")) != -1)
    {
        switch(c)
        {
            case 'h':
                // Headless Operation
                is_headless = true;
                break;

            default:
                break;
        }
    }

    // Get the Folder the Executable runs in.
    std::string realPath;
#ifdef TARGET_OS_MAC
    char currentPath[PATH_MAX];
    uint32_t size = sizeof(currentPath);
    if(_NSGetExecutablePath(currentPath, &size) != 0)
    {
        std::cout << "Unable to get Program Path!" << std::endl;
    }

    // Remove Executable
    realPath = currentPath;
    std::string::size_type position;
    position = realPath.rfind("/EtherTerm");
    if(position != std::string::npos)
        realPath.erase(position+1,realPath.size()-1);

    // remove extra './'
    position = realPath.rfind("./");
    if(position != std::string::npos)
        realPath.erase(position,2);

#elif _WIN32
    // Get the Current Program path.
    char currentPath[PATH_MAX];
    int result = GetModuleFileName(NULL, currentPath, PATH_MAX-1);
    if(result == 0)
    {
        std::cout << "Unable to get Program Path!" << std::endl;
        exit(1);
    }

    realPath = currentPath;
    std::string::size_type position = realPath.rfind("\\",realPath.size()-1);
    if(position != std::string::npos)
        realPath.erase(position+1);
#else

    char exePath[PATH_MAX] = {0};
 #ifdef __FreeBSD__
    ssize_t result = readlink("/proc/curproc/file", exePath, PATH_MAX);
 #else
    ssize_t result = readlink("/proc/self/exe", exePath, PATH_MAX);
 #endif
    if(result < 0)
    {
        std::cout << "Unable to get Program Path!" << std::endl;
        exit(1);
    }

    const char* t = " \t\n\r\f\v";
    realPath = exePath;
    realPath = realPath.erase(realPath.find_last_not_of(t) + 1);
    realPath += "/";

    // Remove Executable
    std::string::size_type position;
    position = realPath.rfind("/EtherTerm");
    if(position != std::string::npos)
        realPath.erase(position+1,realPath.size()-1);

#endif
    std::cout << "EtherTerm Working directory is: " << realPath << std::endl;

    /*
     * We want to be able to run the program headless without SDL loaded
     * For automation and testing
     */

    // Setup the interface for spawning session windows.
	// Using Smart Pointer will clear final allocation prior to full exit of system.
	{
		interface_ptr interface_spawn(new Interface(realPath));

		// Don't loaded menu system waiting for user input, just handle
		// Scripts and connections or parsing functions for testing.
		if(is_headless)
		{
			// Execute scripts / connections via command line
			// Don't startup SDL since were not using the video
			// or Waiting for Keyboard input from the window events.

			// Nothing to do right now.
			exit(0);
		}
		else
		{
			// Startup the Window System and load initial menu
			// Window with Initialization with window event processing.
			if(!SDLStartUp())
			{
				exit(-1);
			}

			// Lead into Interface spawn for session startup and management.
			interface_spawn->startup();
		}
	}

	// SDL is done.
	std::cout << "EtherTerm Shutdown completed." << std::endl;
	SDL_Quit();

    SDL_Log("User has closed the program.");

    exit(0);
}
