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
include CMakeFiles/P3916.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P3916.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P3916.dir/flags.make

CMakeFiles/P3916.dir/P3916.cpp.o: CMakeFiles/P3916.dir/flags.make
CMakeFiles/P3916.dir/P3916.cpp.o: ../P3916.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/20211108/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P3916.dir/P3916.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P3916.dir/P3916.cpp.o -c /mnt/d/Projects/20211108/P3916.cpp

CMakeFiles/P3916.dir/P3916.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P3916.dir/P3916.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/20211108/P3916.cpp > CMakeFiles/P3916.dir/P3916.cpp.i

CMakeFiles/P3916.dir/P3916.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P3916.dir/P3916.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/20211108/P3916.cpp -o CMakeFiles/P3916.dir/P3916.cpp.s

# Object files for target P3916
P3916_OBJECTS = \
"CMakeFiles/P3916.dir/P3916.cpp.o"

# External object files for target P3916
P3916_EXTERNAL_OBJECTS =

P3916: CMakeFiles/P3916.dir/P3916.cpp.o
P3916: CMakeFiles/P3916.dir/build.make
P3916: CMakeFiles/P3916.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/20211108/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P3916"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P3916.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P3916.dir/build: P3916

.PHONY : CMakeFiles/P3916.dir/build

CMakeFiles/P3916.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P3916.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P3916.dir/clean

CMakeFiles/P3916.dir/depend:
	cd /mnt/d/Projects/20211108/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/20211108 /mnt/d/Projects/20211108 /mnt/d/Projects/20211108/cmake-build-debug /mnt/d/Projects/20211108/cmake-build-debug /mnt/d/Projects/20211108/cmake-build-debug/CMakeFiles/P3916.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P3916.dir/depend

