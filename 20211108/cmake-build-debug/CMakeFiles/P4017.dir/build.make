# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Projects/20211108

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Projects/20211108/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P4017.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P4017.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P4017.dir/flags.make

CMakeFiles/P4017.dir/P4017.cpp.o: CMakeFiles/P4017.dir/flags.make
CMakeFiles/P4017.dir/P4017.cpp.o: ../P4017.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/20211108/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P4017.dir/P4017.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P4017.dir/P4017.cpp.o -c /mnt/d/Projects/20211108/P4017.cpp

CMakeFiles/P4017.dir/P4017.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4017.dir/P4017.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/20211108/P4017.cpp > CMakeFiles/P4017.dir/P4017.cpp.i

CMakeFiles/P4017.dir/P4017.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4017.dir/P4017.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/20211108/P4017.cpp -o CMakeFiles/P4017.dir/P4017.cpp.s

# Object files for target P4017
P4017_OBJECTS = \
"CMakeFiles/P4017.dir/P4017.cpp.o"

# External object files for target P4017
P4017_EXTERNAL_OBJECTS =

P4017: CMakeFiles/P4017.dir/P4017.cpp.o
P4017: CMakeFiles/P4017.dir/build.make
P4017: CMakeFiles/P4017.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/20211108/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P4017"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P4017.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P4017.dir/build: P4017

.PHONY : CMakeFiles/P4017.dir/build

CMakeFiles/P4017.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P4017.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P4017.dir/clean

CMakeFiles/P4017.dir/depend:
	cd /mnt/d/Projects/20211108/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/20211108 /mnt/d/Projects/20211108 /mnt/d/Projects/20211108/cmake-build-debug /mnt/d/Projects/20211108/cmake-build-debug /mnt/d/Projects/20211108/cmake-build-debug/CMakeFiles/P4017.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P4017.dir/depend
