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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wanluanlee/Documents/floorplanner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wanluanlee/Documents/floorplanner/build

# Include any dependencies generated for this target.
include sp/CMakeFiles/sp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sp/CMakeFiles/sp.dir/compiler_depend.make

# Include the progress variables for this target.
include sp/CMakeFiles/sp.dir/progress.make

# Include the compile flags for this target's objects.
include sp/CMakeFiles/sp.dir/flags.make

sp/CMakeFiles/sp.dir/circuit.cpp.o: sp/CMakeFiles/sp.dir/flags.make
sp/CMakeFiles/sp.dir/circuit.cpp.o: ../sp/circuit.cpp
sp/CMakeFiles/sp.dir/circuit.cpp.o: sp/CMakeFiles/sp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanluanlee/Documents/floorplanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sp/CMakeFiles/sp.dir/circuit.cpp.o"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sp/CMakeFiles/sp.dir/circuit.cpp.o -MF CMakeFiles/sp.dir/circuit.cpp.o.d -o CMakeFiles/sp.dir/circuit.cpp.o -c /home/wanluanlee/Documents/floorplanner/sp/circuit.cpp

sp/CMakeFiles/sp.dir/circuit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sp.dir/circuit.cpp.i"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanluanlee/Documents/floorplanner/sp/circuit.cpp > CMakeFiles/sp.dir/circuit.cpp.i

sp/CMakeFiles/sp.dir/circuit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sp.dir/circuit.cpp.s"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanluanlee/Documents/floorplanner/sp/circuit.cpp -o CMakeFiles/sp.dir/circuit.cpp.s

sp/CMakeFiles/sp.dir/block.cpp.o: sp/CMakeFiles/sp.dir/flags.make
sp/CMakeFiles/sp.dir/block.cpp.o: ../sp/block.cpp
sp/CMakeFiles/sp.dir/block.cpp.o: sp/CMakeFiles/sp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanluanlee/Documents/floorplanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sp/CMakeFiles/sp.dir/block.cpp.o"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sp/CMakeFiles/sp.dir/block.cpp.o -MF CMakeFiles/sp.dir/block.cpp.o.d -o CMakeFiles/sp.dir/block.cpp.o -c /home/wanluanlee/Documents/floorplanner/sp/block.cpp

sp/CMakeFiles/sp.dir/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sp.dir/block.cpp.i"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanluanlee/Documents/floorplanner/sp/block.cpp > CMakeFiles/sp.dir/block.cpp.i

sp/CMakeFiles/sp.dir/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sp.dir/block.cpp.s"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanluanlee/Documents/floorplanner/sp/block.cpp -o CMakeFiles/sp.dir/block.cpp.s

sp/CMakeFiles/sp.dir/net.cpp.o: sp/CMakeFiles/sp.dir/flags.make
sp/CMakeFiles/sp.dir/net.cpp.o: ../sp/net.cpp
sp/CMakeFiles/sp.dir/net.cpp.o: sp/CMakeFiles/sp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanluanlee/Documents/floorplanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object sp/CMakeFiles/sp.dir/net.cpp.o"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sp/CMakeFiles/sp.dir/net.cpp.o -MF CMakeFiles/sp.dir/net.cpp.o.d -o CMakeFiles/sp.dir/net.cpp.o -c /home/wanluanlee/Documents/floorplanner/sp/net.cpp

sp/CMakeFiles/sp.dir/net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sp.dir/net.cpp.i"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanluanlee/Documents/floorplanner/sp/net.cpp > CMakeFiles/sp.dir/net.cpp.i

sp/CMakeFiles/sp.dir/net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sp.dir/net.cpp.s"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanluanlee/Documents/floorplanner/sp/net.cpp -o CMakeFiles/sp.dir/net.cpp.s

sp/CMakeFiles/sp.dir/terminal.cpp.o: sp/CMakeFiles/sp.dir/flags.make
sp/CMakeFiles/sp.dir/terminal.cpp.o: ../sp/terminal.cpp
sp/CMakeFiles/sp.dir/terminal.cpp.o: sp/CMakeFiles/sp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanluanlee/Documents/floorplanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object sp/CMakeFiles/sp.dir/terminal.cpp.o"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sp/CMakeFiles/sp.dir/terminal.cpp.o -MF CMakeFiles/sp.dir/terminal.cpp.o.d -o CMakeFiles/sp.dir/terminal.cpp.o -c /home/wanluanlee/Documents/floorplanner/sp/terminal.cpp

sp/CMakeFiles/sp.dir/terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sp.dir/terminal.cpp.i"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanluanlee/Documents/floorplanner/sp/terminal.cpp > CMakeFiles/sp.dir/terminal.cpp.i

sp/CMakeFiles/sp.dir/terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sp.dir/terminal.cpp.s"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanluanlee/Documents/floorplanner/sp/terminal.cpp -o CMakeFiles/sp.dir/terminal.cpp.s

sp/CMakeFiles/sp.dir/sequence_pair.cpp.o: sp/CMakeFiles/sp.dir/flags.make
sp/CMakeFiles/sp.dir/sequence_pair.cpp.o: ../sp/sequence_pair.cpp
sp/CMakeFiles/sp.dir/sequence_pair.cpp.o: sp/CMakeFiles/sp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanluanlee/Documents/floorplanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object sp/CMakeFiles/sp.dir/sequence_pair.cpp.o"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sp/CMakeFiles/sp.dir/sequence_pair.cpp.o -MF CMakeFiles/sp.dir/sequence_pair.cpp.o.d -o CMakeFiles/sp.dir/sequence_pair.cpp.o -c /home/wanluanlee/Documents/floorplanner/sp/sequence_pair.cpp

sp/CMakeFiles/sp.dir/sequence_pair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sp.dir/sequence_pair.cpp.i"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanluanlee/Documents/floorplanner/sp/sequence_pair.cpp > CMakeFiles/sp.dir/sequence_pair.cpp.i

sp/CMakeFiles/sp.dir/sequence_pair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sp.dir/sequence_pair.cpp.s"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanluanlee/Documents/floorplanner/sp/sequence_pair.cpp -o CMakeFiles/sp.dir/sequence_pair.cpp.s

# Object files for target sp
sp_OBJECTS = \
"CMakeFiles/sp.dir/circuit.cpp.o" \
"CMakeFiles/sp.dir/block.cpp.o" \
"CMakeFiles/sp.dir/net.cpp.o" \
"CMakeFiles/sp.dir/terminal.cpp.o" \
"CMakeFiles/sp.dir/sequence_pair.cpp.o"

# External object files for target sp
sp_EXTERNAL_OBJECTS =

sp/libsp.a: sp/CMakeFiles/sp.dir/circuit.cpp.o
sp/libsp.a: sp/CMakeFiles/sp.dir/block.cpp.o
sp/libsp.a: sp/CMakeFiles/sp.dir/net.cpp.o
sp/libsp.a: sp/CMakeFiles/sp.dir/terminal.cpp.o
sp/libsp.a: sp/CMakeFiles/sp.dir/sequence_pair.cpp.o
sp/libsp.a: sp/CMakeFiles/sp.dir/build.make
sp/libsp.a: sp/CMakeFiles/sp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wanluanlee/Documents/floorplanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libsp.a"
	cd /home/wanluanlee/Documents/floorplanner/build/sp && $(CMAKE_COMMAND) -P CMakeFiles/sp.dir/cmake_clean_target.cmake
	cd /home/wanluanlee/Documents/floorplanner/build/sp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sp/CMakeFiles/sp.dir/build: sp/libsp.a
.PHONY : sp/CMakeFiles/sp.dir/build

sp/CMakeFiles/sp.dir/clean:
	cd /home/wanluanlee/Documents/floorplanner/build/sp && $(CMAKE_COMMAND) -P CMakeFiles/sp.dir/cmake_clean.cmake
.PHONY : sp/CMakeFiles/sp.dir/clean

sp/CMakeFiles/sp.dir/depend:
	cd /home/wanluanlee/Documents/floorplanner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanluanlee/Documents/floorplanner /home/wanluanlee/Documents/floorplanner/sp /home/wanluanlee/Documents/floorplanner/build /home/wanluanlee/Documents/floorplanner/build/sp /home/wanluanlee/Documents/floorplanner/build/sp/CMakeFiles/sp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sp/CMakeFiles/sp.dir/depend

