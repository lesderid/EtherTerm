CodeLiteDir:=/usr/share/codelite
Objects=./Debug/up_src_input_handler.cpp.o ./Debug/up_src_link_list.cpp.o ./Debug/up_src_main.cpp.o ./Debug/up_src_menu_config.cpp.o ./Debug/up_src_menu_function.cpp.o ./Debug/up_src_menu_io.cpp.o ./Debug/up_src_menu_manager.cpp.o ./Debug/up_src_protocol.cpp.o ./Debug/up_src_renderer.cpp.o ./Debug/up_src_screen_buffer.cpp.o \
	./Debug/up_src_sequence_decoder.cpp.o ./Debug/up_src_sequence_parser.cpp.o ./Debug/up_src_session_manager.cpp.o ./Debug/up_src_surface_manager.cpp.o ./Debug/up_src_telnet_manager.cpp.o ./Debug/up_src_tinystr.cpp.o ./Debug/up_src_tinyxml.cpp.o ./Debug/up_src_tinyxmlerror.cpp.o ./Debug/up_src_tinyxmlparser.cpp.o ./Debug/up_src_window_manager.cpp.o \
	./Debug/up_src_io_service.cpp.o ./Debug/up_src_socket_handler.cpp.o ./Debug/up_src_socket_ssh.cpp.o ./Debug/up_src_socket_telnet.cpp.o ./Debug/up_src_irc_manager.cpp.o ./Debug/up_src_socket_irc.cpp.o ./Debug/up_src_SDL2_net_SDLnet.cpp.o ./Debug/up_src_SDL2_net_SDLnetselect.cpp.o ./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o ./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o


##
## Main Build Targets
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: ./Debug/EtherTerm

./Debug/EtherTerm: ./Debug/.d $(Objects)
	@mkdir -p $(@D)
	@echo "" > ./Debug/.d
	@echo $(Objects)  > "EtherTerm.txt"
	$(CXX) -o./Debug/EtherTerm @"EtherTerm.txt" -L. -lSDL2main -lSDL2 -lpthread -lssh

MakeIntermediateDirs:
	@test -d ./Debug || mkdir -p ./Debug


./Debug/.d:
	@test -d ./Debug || mkdir -p ./Debug

PreBuild:

CXXFLAGS = -O3 -std=c++11

##
## Objects
##
./Debug/up_src_input_handler.cpp.o: ../src/input_handler.cpp ./Debug/up_src_input_handler.cpp.o.d
	$(CXX)  -c "../src/input_handler.cpp" $(CXXFLAGS) -o./Debug/up_src_input_handler.cpp.o -I. -I.. -I../src
./Debug/up_src_input_handler.cpp.o.d: ../src/input_handler.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_input_handler.cpp.o -MF./Debug/up_src_input_handler.cpp.o.d -MM ../src/input_handler.cpp

./Debug/up_src_input_handler.cpp.i: ../src/input_handler.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_input_handler.cpp.i ../src/input_handler.cpp

./Debug/up_src_link_list.cpp.o: ../src/link_list.cpp ./Debug/up_src_link_list.cpp.o.d
	$(CXX)  -c "../src/link_list.cpp" $(CXXFLAGS) -o./Debug/up_src_link_list.cpp.o -I. -I.. -I../src
./Debug/up_src_link_list.cpp.o.d: ../src/link_list.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_link_list.cpp.o -MF./Debug/up_src_link_list.cpp.o.d -MM ../src/link_list.cpp

./Debug/up_src_link_list.cpp.i: ../src/link_list.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_link_list.cpp.i ../src/link_list.cpp

./Debug/up_src_main.cpp.o: ../src/main.cpp ./Debug/up_src_main.cpp.o.d
	$(CXX)  -c "../src/main.cpp" $(CXXFLAGS) -o./Debug/up_src_main.cpp.o -I. -I.. -I../src
./Debug/up_src_main.cpp.o.d: ../src/main.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_main.cpp.o -MF./Debug/up_src_main.cpp.o.d -MM ../src/main.cpp

./Debug/up_src_main.cpp.i: ../src/main.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_main.cpp.i ../src/main.cpp

./Debug/up_src_menu_config.cpp.o: ../src/menu_config.cpp ./Debug/up_src_menu_config.cpp.o.d
	$(CXX)  -c "../src/menu_config.cpp" $(CXXFLAGS) -o./Debug/up_src_menu_config.cpp.o -I. -I.. -I../src
./Debug/up_src_menu_config.cpp.o.d: ../src/menu_config.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_menu_config.cpp.o -MF./Debug/up_src_menu_config.cpp.o.d -MM ../src/menu_config.cpp

./Debug/up_src_menu_config.cpp.i: ../src/menu_config.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_menu_config.cpp.i ../src/menu_config.cpp

./Debug/up_src_menu_function.cpp.o: ../src/menu_function.cpp ./Debug/up_src_menu_function.cpp.o.d
	$(CXX)  -c "../src/menu_function.cpp" $(CXXFLAGS) -o./Debug/up_src_menu_function.cpp.o -I. -I.. -I../src
./Debug/up_src_menu_function.cpp.o.d: ../src/menu_function.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_menu_function.cpp.o -MF./Debug/up_src_menu_function.cpp.o.d -MM ../src/menu_function.cpp

./Debug/up_src_menu_function.cpp.i: ../src/menu_function.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_menu_function.cpp.i ../src/menu_function.cpp

./Debug/up_src_menu_io.cpp.o: ../src/menu_io.cpp ./Debug/up_src_menu_io.cpp.o.d
	$(CXX)  -c "../src/menu_io.cpp" $(CXXFLAGS) -o./Debug/up_src_menu_io.cpp.o -I. -I.. -I../src
./Debug/up_src_menu_io.cpp.o.d: ../src/menu_io.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_menu_io.cpp.o -MF./Debug/up_src_menu_io.cpp.o.d -MM ../src/menu_io.cpp

./Debug/up_src_menu_io.cpp.i: ../src/menu_io.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_menu_io.cpp.i ../src/menu_io.cpp

./Debug/up_src_menu_manager.cpp.o: ../src/menu_manager.cpp ./Debug/up_src_menu_manager.cpp.o.d
	$(CXX)  -c "../src/menu_manager.cpp" $(CXXFLAGS) -o./Debug/up_src_menu_manager.cpp.o -I. -I.. -I../src
./Debug/up_src_menu_manager.cpp.o.d: ../src/menu_manager.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_menu_manager.cpp.o -MF./Debug/up_src_menu_manager.cpp.o.d -MM ../src/menu_manager.cpp

./Debug/up_src_menu_manager.cpp.i: ../src/menu_manager.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_menu_manager.cpp.i ../src/menu_manager.cpp

./Debug/up_src_protocol.cpp.o: ../src/protocol.cpp ./Debug/up_src_protocol.cpp.o.d
	$(CXX)  -c "../src/protocol.cpp" $(CXXFLAGS) -o./Debug/up_src_protocol.cpp.o -I. -I.. -I../src
./Debug/up_src_protocol.cpp.o.d: ../src/protocol.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_protocol.cpp.o -MF./Debug/up_src_protocol.cpp.o.d -MM ../src/protocol.cpp

./Debug/up_src_protocol.cpp.i: ../src/protocol.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_protocol.cpp.i ../src/protocol.cpp

./Debug/up_src_renderer.cpp.o: ../src/renderer.cpp ./Debug/up_src_renderer.cpp.o.d
	$(CXX)  -c "../src/renderer.cpp" $(CXXFLAGS) -o./Debug/up_src_renderer.cpp.o -I. -I.. -I../src
./Debug/up_src_renderer.cpp.o.d: ../src/renderer.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_renderer.cpp.o -MF./Debug/up_src_renderer.cpp.o.d -MM ../src/renderer.cpp

./Debug/up_src_renderer.cpp.i: ../src/renderer.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_renderer.cpp.i ../src/renderer.cpp

./Debug/up_src_screen_buffer.cpp.o: ../src/screen_buffer.cpp ./Debug/up_src_screen_buffer.cpp.o.d
	$(CXX)  -c "../src/screen_buffer.cpp" $(CXXFLAGS) -o./Debug/up_src_screen_buffer.cpp.o -I. -I.. -I../src
./Debug/up_src_screen_buffer.cpp.o.d: ../src/screen_buffer.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_screen_buffer.cpp.o -MF./Debug/up_src_screen_buffer.cpp.o.d -MM ../src/screen_buffer.cpp

./Debug/up_src_screen_buffer.cpp.i: ../src/screen_buffer.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_screen_buffer.cpp.i ../src/screen_buffer.cpp

./Debug/up_src_sequence_decoder.cpp.o: ../src/sequence_decoder.cpp ./Debug/up_src_sequence_decoder.cpp.o.d
	$(CXX)  -c "../src/sequence_decoder.cpp" $(CXXFLAGS) -o./Debug/up_src_sequence_decoder.cpp.o -I. -I.. -I../src
./Debug/up_src_sequence_decoder.cpp.o.d: ../src/sequence_decoder.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_sequence_decoder.cpp.o -MF./Debug/up_src_sequence_decoder.cpp.o.d -MM ../src/sequence_decoder.cpp

./Debug/up_src_sequence_decoder.cpp.i: ../src/sequence_decoder.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_sequence_decoder.cpp.i ../src/sequence_decoder.cpp

./Debug/up_src_sequence_parser.cpp.o: ../src/sequence_parser.cpp ./Debug/up_src_sequence_parser.cpp.o.d
	$(CXX)  -c "../src/sequence_parser.cpp" $(CXXFLAGS) -o./Debug/up_src_sequence_parser.cpp.o -I. -I.. -I../src
./Debug/up_src_sequence_parser.cpp.o.d: ../src/sequence_parser.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_sequence_parser.cpp.o -MF./Debug/up_src_sequence_parser.cpp.o.d -MM ../src/sequence_parser.cpp

./Debug/up_src_sequence_parser.cpp.i: ../src/sequence_parser.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_sequence_parser.cpp.i ../src/sequence_parser.cpp

./Debug/up_src_session_manager.cpp.o: ../src/session_manager.cpp ./Debug/up_src_session_manager.cpp.o.d
	$(CXX)  -c "../src/session_manager.cpp" $(CXXFLAGS) -o./Debug/up_src_session_manager.cpp.o -I. -I.. -I../src
./Debug/up_src_session_manager.cpp.o.d: ../src/session_manager.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_session_manager.cpp.o -MF./Debug/up_src_session_manager.cpp.o.d -MM ../src/session_manager.cpp

./Debug/up_src_session_manager.cpp.i: ../src/session_manager.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_session_manager.cpp.i ../src/session_manager.cpp

./Debug/up_src_surface_manager.cpp.o: ../src/surface_manager.cpp ./Debug/up_src_surface_manager.cpp.o.d
	$(CXX)  -c "../src/surface_manager.cpp" $(CXXFLAGS) -o./Debug/up_src_surface_manager.cpp.o -I. -I.. -I../src
./Debug/up_src_surface_manager.cpp.o.d: ../src/surface_manager.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_surface_manager.cpp.o -MF./Debug/up_src_surface_manager.cpp.o.d -MM ../src/surface_manager.cpp

./Debug/up_src_surface_manager.cpp.i: ../src/surface_manager.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_surface_manager.cpp.i ../src/surface_manager.cpp

./Debug/up_src_telnet_manager.cpp.o: ../src/telnet_manager.cpp ./Debug/up_src_telnet_manager.cpp.o.d
	$(CXX)  -c "../src/telnet_manager.cpp" $(CXXFLAGS) -o./Debug/up_src_telnet_manager.cpp.o -I. -I.. -I../src
./Debug/up_src_telnet_manager.cpp.o.d: ../src/telnet_manager.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_telnet_manager.cpp.o -MF./Debug/up_src_telnet_manager.cpp.o.d -MM ../src/telnet_manager.cpp

./Debug/up_src_telnet_manager.cpp.i: ../src/telnet_manager.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_telnet_manager.cpp.i ../src/telnet_manager.cpp

./Debug/up_src_tinystr.cpp.o: ../src/tinystr.cpp ./Debug/up_src_tinystr.cpp.o.d
	$(CXX)  -c "../src/tinystr.cpp" $(CXXFLAGS) -o./Debug/up_src_tinystr.cpp.o -I. -I.. -I../src
./Debug/up_src_tinystr.cpp.o.d: ../src/tinystr.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_tinystr.cpp.o -MF./Debug/up_src_tinystr.cpp.o.d -MM ../src/tinystr.cpp

./Debug/up_src_tinystr.cpp.i: ../src/tinystr.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_tinystr.cpp.i ../src/tinystr.cpp

./Debug/up_src_tinyxml.cpp.o: ../src/tinyxml.cpp ./Debug/up_src_tinyxml.cpp.o.d
	$(CXX)  -c "../src/tinyxml.cpp" $(CXXFLAGS) -o./Debug/up_src_tinyxml.cpp.o -I. -I.. -I../src
./Debug/up_src_tinyxml.cpp.o.d: ../src/tinyxml.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_tinyxml.cpp.o -MF./Debug/up_src_tinyxml.cpp.o.d -MM ../src/tinyxml.cpp

./Debug/up_src_tinyxml.cpp.i: ../src/tinyxml.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_tinyxml.cpp.i ../src/tinyxml.cpp

./Debug/up_src_tinyxmlerror.cpp.o: ../src/tinyxmlerror.cpp ./Debug/up_src_tinyxmlerror.cpp.o.d
	$(CXX)  -c "../src/tinyxmlerror.cpp" $(CXXFLAGS) -o./Debug/up_src_tinyxmlerror.cpp.o -I. -I.. -I../src
./Debug/up_src_tinyxmlerror.cpp.o.d: ../src/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_tinyxmlerror.cpp.o -MF./Debug/up_src_tinyxmlerror.cpp.o.d -MM ../src/tinyxmlerror.cpp

./Debug/up_src_tinyxmlerror.cpp.i: ../src/tinyxmlerror.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_tinyxmlerror.cpp.i ../src/tinyxmlerror.cpp

./Debug/up_src_tinyxmlparser.cpp.o: ../src/tinyxmlparser.cpp ./Debug/up_src_tinyxmlparser.cpp.o.d
	$(CXX)  -c "../src/tinyxmlparser.cpp" $(CXXFLAGS) -o./Debug/up_src_tinyxmlparser.cpp.o -I. -I.. -I../src
./Debug/up_src_tinyxmlparser.cpp.o.d: ../src/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_tinyxmlparser.cpp.o -MF./Debug/up_src_tinyxmlparser.cpp.o.d -MM ../src/tinyxmlparser.cpp

./Debug/up_src_tinyxmlparser.cpp.i: ../src/tinyxmlparser.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_tinyxmlparser.cpp.i ../src/tinyxmlparser.cpp

./Debug/up_src_window_manager.cpp.o: ../src/window_manager.cpp ./Debug/up_src_window_manager.cpp.o.d
	$(CXX)  -c "../src/window_manager.cpp" $(CXXFLAGS) -o./Debug/up_src_window_manager.cpp.o -I. -I.. -I../src
./Debug/up_src_window_manager.cpp.o.d: ../src/window_manager.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_window_manager.cpp.o -MF./Debug/up_src_window_manager.cpp.o.d -MM ../src/window_manager.cpp

./Debug/up_src_window_manager.cpp.i: ../src/window_manager.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_window_manager.cpp.i ../src/window_manager.cpp

./Debug/up_src_io_service.cpp.o: ../src/io_service.cpp ./Debug/up_src_io_service.cpp.o.d
	$(CXX)  -c "../src/io_service.cpp" $(CXXFLAGS) -o./Debug/up_src_io_service.cpp.o -I. -I.. -I../src
./Debug/up_src_io_service.cpp.o.d: ../src/io_service.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_io_service.cpp.o -MF./Debug/up_src_io_service.cpp.o.d -MM ../src/io_service.cpp

./Debug/up_src_io_service.cpp.i: ../src/io_service.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_io_service.cpp.i ../src/io_service.cpp

./Debug/up_src_socket_handler.cpp.o: ../src/socket_handler.cpp ./Debug/up_src_socket_handler.cpp.o.d
	$(CXX)  -c "../src/socket_handler.cpp" $(CXXFLAGS) -o./Debug/up_src_socket_handler.cpp.o -I. -I.. -I../src
./Debug/up_src_socket_handler.cpp.o.d: ../src/socket_handler.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_socket_handler.cpp.o -MF./Debug/up_src_socket_handler.cpp.o.d -MM ../src/socket_handler.cpp

./Debug/up_src_socket_handler.cpp.i: ../src/socket_handler.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_socket_handler.cpp.i ../src/socket_handler.cpp

./Debug/up_src_socket_ssh.cpp.o: ../src/socket_ssh.cpp ./Debug/up_src_socket_ssh.cpp.o.d
	$(CXX)  -c "../src/socket_ssh.cpp" $(CXXFLAGS) -o./Debug/up_src_socket_ssh.cpp.o -I. -I.. -I../src
./Debug/up_src_socket_ssh.cpp.o.d: ../src/socket_ssh.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_socket_ssh.cpp.o -MF./Debug/up_src_socket_ssh.cpp.o.d -MM ../src/socket_ssh.cpp

./Debug/up_src_socket_ssh.cpp.i: ../src/socket_ssh.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_socket_ssh.cpp.i ../src/socket_ssh.cpp

./Debug/up_src_socket_telnet.cpp.o: ../src/socket_telnet.cpp ./Debug/up_src_socket_telnet.cpp.o.d
	$(CXX)  -c "../src/socket_telnet.cpp" $(CXXFLAGS) -o./Debug/up_src_socket_telnet.cpp.o -I. -I.. -I../src
./Debug/up_src_socket_telnet.cpp.o.d: ../src/socket_telnet.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_socket_telnet.cpp.o -MF./Debug/up_src_socket_telnet.cpp.o.d -MM ../src/socket_telnet.cpp

./Debug/up_src_socket_telnet.cpp.i: ../src/socket_telnet.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_socket_telnet.cpp.i ../src/socket_telnet.cpp

./Debug/up_src_irc_manager.cpp.o: ../src/irc_manager.cpp ./Debug/up_src_irc_manager.cpp.o.d
	$(CXX)  -c "../src/irc_manager.cpp" $(CXXFLAGS) -o./Debug/up_src_irc_manager.cpp.o -I. -I.. -I../src
./Debug/up_src_irc_manager.cpp.o.d: ../src/irc_manager.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_irc_manager.cpp.o -MF./Debug/up_src_irc_manager.cpp.o.d -MM ../src/irc_manager.cpp

./Debug/up_src_irc_manager.cpp.i: ../src/irc_manager.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_irc_manager.cpp.i ../src/irc_manager.cpp

./Debug/up_src_socket_irc.cpp.o: ../src/socket_irc.cpp ./Debug/up_src_socket_irc.cpp.o.d
	$(CXX)  -c "../src/socket_irc.cpp" $(CXXFLAGS) -o./Debug/up_src_socket_irc.cpp.o -I. -I.. -I../src
./Debug/up_src_socket_irc.cpp.o.d: ../src/socket_irc.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_socket_irc.cpp.o -MF./Debug/up_src_socket_irc.cpp.o.d -MM ../src/socket_irc.cpp

./Debug/up_src_socket_irc.cpp.i: ../src/socket_irc.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_socket_irc.cpp.i ../src/socket_irc.cpp

./Debug/up_src_SDL2_net_SDLnet.cpp.o: ../src/SDL2_net/SDLnet.cpp ./Debug/up_src_SDL2_net_SDLnet.cpp.o.d
	$(CXX)  -c "../src/SDL2_net/SDLnet.cpp" $(CXXFLAGS) -o./Debug/up_src_SDL2_net_SDLnet.cpp.o -I. -I.. -I../src
./Debug/up_src_SDL2_net_SDLnet.cpp.o.d: ../src/SDL2_net/SDLnet.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_SDL2_net_SDLnet.cpp.o -MF./Debug/up_src_SDL2_net_SDLnet.cpp.o.d -MM ../src/SDL2_net/SDLnet.cpp

./Debug/up_src_SDL2_net_SDLnet.cpp.i: ../src/SDL2_net/SDLnet.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_SDL2_net_SDLnet.cpp.i ../src/SDL2_net/SDLnet.cpp

./Debug/up_src_SDL2_net_SDLnetselect.cpp.o: ../src/SDL2_net/SDLnetselect.cpp ./Debug/up_src_SDL2_net_SDLnetselect.cpp.o.d
	$(CXX)  -c "../src/SDL2_net/SDLnetselect.cpp" $(CXXFLAGS) -o./Debug/up_src_SDL2_net_SDLnetselect.cpp.o -I. -I.. -I../src
./Debug/up_src_SDL2_net_SDLnetselect.cpp.o.d: ../src/SDL2_net/SDLnetselect.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_SDL2_net_SDLnetselect.cpp.o -MF./Debug/up_src_SDL2_net_SDLnetselect.cpp.o.d -MM ../src/SDL2_net/SDLnetselect.cpp

./Debug/up_src_SDL2_net_SDLnetselect.cpp.i: ../src/SDL2_net/SDLnetselect.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_SDL2_net_SDLnetselect.cpp.i ../src/SDL2_net/SDLnetselect.cpp

./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o: ../src/SDL2_net/SDLnetTCP.cpp ./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o.d
	$(CXX)  -c "../src/SDL2_net/SDLnetTCP.cpp" $(CXXFLAGS) -o./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o -I. -I.. -I../src
./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o.d: ../src/SDL2_net/SDLnetTCP.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o -MF./Debug/up_src_SDL2_net_SDLnetTCP.cpp.o.d -MM ../src/SDL2_net/SDLnetTCP.cpp

./Debug/up_src_SDL2_net_SDLnetTCP.cpp.i: ../src/SDL2_net/SDLnetTCP.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_SDL2_net_SDLnetTCP.cpp.i ../src/SDL2_net/SDLnetTCP.cpp

./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o: ../src/SDL2_net/SDLnetUDP.cpp ./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o.d
	$(CXX)  -c "../src/SDL2_net/SDLnetUDP.cpp" $(CXXFLAGS) -o./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o -I. -I.. -I../src
./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o.d: ../src/SDL2_net/SDLnetUDP.cpp
	@$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -MG -MP -MT./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o -MF./Debug/up_src_SDL2_net_SDLnetUDP.cpp.o.d -MM ../src/SDL2_net/SDLnetUDP.cpp

./Debug/up_src_SDL2_net_SDLnetUDP.cpp.i: ../src/SDL2_net/SDLnetUDP.cpp
	$(CXX) $(CXXFLAGS)  -I. -I.. -I../src -E -o ./Debug/up_src_SDL2_net_SDLnetUDP.cpp.i ../src/SDL2_net/SDLnetUDP.cpp


-include ./Debug/*.o.d
clean:
	$(RM) -r ./Debug/


