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
CMAKE_SOURCE_DIR = /home/nelio/Codigos/SPC/Divisao_da_Nlogonia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Divisao_da_Nlogonia.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Divisao_da_Nlogonia.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Divisao_da_Nlogonia.dir/flags.make

CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o: CMakeFiles/Divisao_da_Nlogonia.dir/flags.make
CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o -c /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/main.cpp

CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/main.cpp > CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.i

CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/main.cpp -o CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.s

CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.requires

CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.provides: CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Divisao_da_Nlogonia.dir/build.make CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.provides

CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.provides.build: CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o


# Object files for target Divisao_da_Nlogonia
Divisao_da_Nlogonia_OBJECTS = \
"CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o"

# External object files for target Divisao_da_Nlogonia
Divisao_da_Nlogonia_EXTERNAL_OBJECTS =

Divisao_da_Nlogonia: CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o
Divisao_da_Nlogonia: CMakeFiles/Divisao_da_Nlogonia.dir/build.make
Divisao_da_Nlogonia: CMakeFiles/Divisao_da_Nlogonia.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Divisao_da_Nlogonia"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Divisao_da_Nlogonia.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Divisao_da_Nlogonia.dir/build: Divisao_da_Nlogonia

.PHONY : CMakeFiles/Divisao_da_Nlogonia.dir/build

CMakeFiles/Divisao_da_Nlogonia.dir/requires: CMakeFiles/Divisao_da_Nlogonia.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Divisao_da_Nlogonia.dir/requires

CMakeFiles/Divisao_da_Nlogonia.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Divisao_da_Nlogonia.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Divisao_da_Nlogonia.dir/clean

CMakeFiles/Divisao_da_Nlogonia.dir/depend:
	cd /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nelio/Codigos/SPC/Divisao_da_Nlogonia /home/nelio/Codigos/SPC/Divisao_da_Nlogonia /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug /home/nelio/Codigos/SPC/Divisao_da_Nlogonia/cmake-build-debug/CMakeFiles/Divisao_da_Nlogonia.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Divisao_da_Nlogonia.dir/depend
