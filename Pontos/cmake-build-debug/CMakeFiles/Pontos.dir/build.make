# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/nelio/Downloads/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/nelio/Downloads/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nelio/Codigos/SPC/Pontos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nelio/Codigos/SPC/Pontos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pontos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pontos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pontos.dir/flags.make

CMakeFiles/Pontos.dir/main.cpp.o: CMakeFiles/Pontos.dir/flags.make
CMakeFiles/Pontos.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nelio/Codigos/SPC/Pontos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pontos.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pontos.dir/main.cpp.o -c /home/nelio/Codigos/SPC/Pontos/main.cpp

CMakeFiles/Pontos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pontos.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nelio/Codigos/SPC/Pontos/main.cpp > CMakeFiles/Pontos.dir/main.cpp.i

CMakeFiles/Pontos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pontos.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nelio/Codigos/SPC/Pontos/main.cpp -o CMakeFiles/Pontos.dir/main.cpp.s

CMakeFiles/Pontos.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Pontos.dir/main.cpp.o.requires

CMakeFiles/Pontos.dir/main.cpp.o.provides: CMakeFiles/Pontos.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Pontos.dir/build.make CMakeFiles/Pontos.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Pontos.dir/main.cpp.o.provides

CMakeFiles/Pontos.dir/main.cpp.o.provides.build: CMakeFiles/Pontos.dir/main.cpp.o


# Object files for target Pontos
Pontos_OBJECTS = \
"CMakeFiles/Pontos.dir/main.cpp.o"

# External object files for target Pontos
Pontos_EXTERNAL_OBJECTS =

Pontos: CMakeFiles/Pontos.dir/main.cpp.o
Pontos: CMakeFiles/Pontos.dir/build.make
Pontos: CMakeFiles/Pontos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nelio/Codigos/SPC/Pontos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pontos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pontos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pontos.dir/build: Pontos

.PHONY : CMakeFiles/Pontos.dir/build

CMakeFiles/Pontos.dir/requires: CMakeFiles/Pontos.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Pontos.dir/requires

CMakeFiles/Pontos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pontos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pontos.dir/clean

CMakeFiles/Pontos.dir/depend:
	cd /home/nelio/Codigos/SPC/Pontos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nelio/Codigos/SPC/Pontos /home/nelio/Codigos/SPC/Pontos /home/nelio/Codigos/SPC/Pontos/cmake-build-debug /home/nelio/Codigos/SPC/Pontos/cmake-build-debug /home/nelio/Codigos/SPC/Pontos/cmake-build-debug/CMakeFiles/Pontos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pontos.dir/depend

