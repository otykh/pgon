# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/PGoN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/PGoN/PGoN_build

# Include any dependencies generated for this target.
include CMakeFiles/PGoN.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PGoN.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PGoN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PGoN.dir/flags.make

CMakeFiles/PGoN.dir/src/city.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/city.cpp.o: ../src/city.cpp
CMakeFiles/PGoN.dir/src/city.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PGoN.dir/src/city.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/city.cpp.o -MF CMakeFiles/PGoN.dir/src/city.cpp.o.d -o CMakeFiles/PGoN.dir/src/city.cpp.o -c /home/alex/PGoN/src/city.cpp

CMakeFiles/PGoN.dir/src/city.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/city.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/city.cpp > CMakeFiles/PGoN.dir/src/city.cpp.i

CMakeFiles/PGoN.dir/src/city.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/city.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/city.cpp -o CMakeFiles/PGoN.dir/src/city.cpp.s

CMakeFiles/PGoN.dir/src/colorer.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/colorer.cpp.o: ../src/colorer.cpp
CMakeFiles/PGoN.dir/src/colorer.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PGoN.dir/src/colorer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/colorer.cpp.o -MF CMakeFiles/PGoN.dir/src/colorer.cpp.o.d -o CMakeFiles/PGoN.dir/src/colorer.cpp.o -c /home/alex/PGoN/src/colorer.cpp

CMakeFiles/PGoN.dir/src/colorer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/colorer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/colorer.cpp > CMakeFiles/PGoN.dir/src/colorer.cpp.i

CMakeFiles/PGoN.dir/src/colorer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/colorer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/colorer.cpp -o CMakeFiles/PGoN.dir/src/colorer.cpp.s

CMakeFiles/PGoN.dir/src/creature.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/creature.cpp.o: ../src/creature.cpp
CMakeFiles/PGoN.dir/src/creature.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PGoN.dir/src/creature.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/creature.cpp.o -MF CMakeFiles/PGoN.dir/src/creature.cpp.o.d -o CMakeFiles/PGoN.dir/src/creature.cpp.o -c /home/alex/PGoN/src/creature.cpp

CMakeFiles/PGoN.dir/src/creature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/creature.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/creature.cpp > CMakeFiles/PGoN.dir/src/creature.cpp.i

CMakeFiles/PGoN.dir/src/creature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/creature.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/creature.cpp -o CMakeFiles/PGoN.dir/src/creature.cpp.s

CMakeFiles/PGoN.dir/src/logger.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/logger.cpp.o: ../src/logger.cpp
CMakeFiles/PGoN.dir/src/logger.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PGoN.dir/src/logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/logger.cpp.o -MF CMakeFiles/PGoN.dir/src/logger.cpp.o.d -o CMakeFiles/PGoN.dir/src/logger.cpp.o -c /home/alex/PGoN/src/logger.cpp

CMakeFiles/PGoN.dir/src/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/logger.cpp > CMakeFiles/PGoN.dir/src/logger.cpp.i

CMakeFiles/PGoN.dir/src/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/logger.cpp -o CMakeFiles/PGoN.dir/src/logger.cpp.s

CMakeFiles/PGoN.dir/src/main.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/PGoN.dir/src/main.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PGoN.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/main.cpp.o -MF CMakeFiles/PGoN.dir/src/main.cpp.o.d -o CMakeFiles/PGoN.dir/src/main.cpp.o -c /home/alex/PGoN/src/main.cpp

CMakeFiles/PGoN.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/main.cpp > CMakeFiles/PGoN.dir/src/main.cpp.i

CMakeFiles/PGoN.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/main.cpp -o CMakeFiles/PGoN.dir/src/main.cpp.s

CMakeFiles/PGoN.dir/src/object.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/object.cpp.o: ../src/object.cpp
CMakeFiles/PGoN.dir/src/object.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PGoN.dir/src/object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/object.cpp.o -MF CMakeFiles/PGoN.dir/src/object.cpp.o.d -o CMakeFiles/PGoN.dir/src/object.cpp.o -c /home/alex/PGoN/src/object.cpp

CMakeFiles/PGoN.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/object.cpp > CMakeFiles/PGoN.dir/src/object.cpp.i

CMakeFiles/PGoN.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/object.cpp -o CMakeFiles/PGoN.dir/src/object.cpp.s

CMakeFiles/PGoN.dir/src/playerinput.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/playerinput.cpp.o: ../src/playerinput.cpp
CMakeFiles/PGoN.dir/src/playerinput.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PGoN.dir/src/playerinput.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/playerinput.cpp.o -MF CMakeFiles/PGoN.dir/src/playerinput.cpp.o.d -o CMakeFiles/PGoN.dir/src/playerinput.cpp.o -c /home/alex/PGoN/src/playerinput.cpp

CMakeFiles/PGoN.dir/src/playerinput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/playerinput.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/playerinput.cpp > CMakeFiles/PGoN.dir/src/playerinput.cpp.i

CMakeFiles/PGoN.dir/src/playerinput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/playerinput.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/playerinput.cpp -o CMakeFiles/PGoN.dir/src/playerinput.cpp.s

CMakeFiles/PGoN.dir/src/room.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/room.cpp.o: ../src/room.cpp
CMakeFiles/PGoN.dir/src/room.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PGoN.dir/src/room.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/room.cpp.o -MF CMakeFiles/PGoN.dir/src/room.cpp.o.d -o CMakeFiles/PGoN.dir/src/room.cpp.o -c /home/alex/PGoN/src/room.cpp

CMakeFiles/PGoN.dir/src/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/room.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/room.cpp > CMakeFiles/PGoN.dir/src/room.cpp.i

CMakeFiles/PGoN.dir/src/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/room.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/room.cpp -o CMakeFiles/PGoN.dir/src/room.cpp.s

CMakeFiles/PGoN.dir/src/world.cpp.o: CMakeFiles/PGoN.dir/flags.make
CMakeFiles/PGoN.dir/src/world.cpp.o: ../src/world.cpp
CMakeFiles/PGoN.dir/src/world.cpp.o: CMakeFiles/PGoN.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/PGoN.dir/src/world.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGoN.dir/src/world.cpp.o -MF CMakeFiles/PGoN.dir/src/world.cpp.o.d -o CMakeFiles/PGoN.dir/src/world.cpp.o -c /home/alex/PGoN/src/world.cpp

CMakeFiles/PGoN.dir/src/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGoN.dir/src/world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/PGoN/src/world.cpp > CMakeFiles/PGoN.dir/src/world.cpp.i

CMakeFiles/PGoN.dir/src/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGoN.dir/src/world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/PGoN/src/world.cpp -o CMakeFiles/PGoN.dir/src/world.cpp.s

# Object files for target PGoN
PGoN_OBJECTS = \
"CMakeFiles/PGoN.dir/src/city.cpp.o" \
"CMakeFiles/PGoN.dir/src/colorer.cpp.o" \
"CMakeFiles/PGoN.dir/src/creature.cpp.o" \
"CMakeFiles/PGoN.dir/src/logger.cpp.o" \
"CMakeFiles/PGoN.dir/src/main.cpp.o" \
"CMakeFiles/PGoN.dir/src/object.cpp.o" \
"CMakeFiles/PGoN.dir/src/playerinput.cpp.o" \
"CMakeFiles/PGoN.dir/src/room.cpp.o" \
"CMakeFiles/PGoN.dir/src/world.cpp.o"

# External object files for target PGoN
PGoN_EXTERNAL_OBJECTS =

PGoN: CMakeFiles/PGoN.dir/src/city.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/colorer.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/creature.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/logger.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/main.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/object.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/playerinput.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/room.cpp.o
PGoN: CMakeFiles/PGoN.dir/src/world.cpp.o
PGoN: CMakeFiles/PGoN.dir/build.make
PGoN: CMakeFiles/PGoN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/PGoN/PGoN_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable PGoN"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PGoN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PGoN.dir/build: PGoN
.PHONY : CMakeFiles/PGoN.dir/build

CMakeFiles/PGoN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PGoN.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PGoN.dir/clean

CMakeFiles/PGoN.dir/depend:
	cd /home/alex/PGoN/PGoN_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/PGoN /home/alex/PGoN /home/alex/PGoN/PGoN_build /home/alex/PGoN/PGoN_build /home/alex/PGoN/PGoN_build/CMakeFiles/PGoN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PGoN.dir/depend

