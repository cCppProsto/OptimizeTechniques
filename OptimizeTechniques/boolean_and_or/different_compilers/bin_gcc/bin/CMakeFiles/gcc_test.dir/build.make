# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin

# Include any dependencies generated for this target.
include CMakeFiles/gcc_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gcc_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gcc_test.dir/flags.make

CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o: CMakeFiles/gcc_test.dir/flags.make
CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o: /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o -c /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp

CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp > CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.i

CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp -o CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.s

CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.requires:

.PHONY : CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.requires

CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.provides: CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gcc_test.dir/build.make CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.provides.build
.PHONY : CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.provides

CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.provides.build: CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o


# Object files for target gcc_test
gcc_test_OBJECTS = \
"CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o"

# External object files for target gcc_test
gcc_test_EXTERNAL_OBJECTS =

gcc_test: CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o
gcc_test: CMakeFiles/gcc_test.dir/build.make
gcc_test: CMakeFiles/gcc_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gcc_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gcc_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gcc_test.dir/build: gcc_test

.PHONY : CMakeFiles/gcc_test.dir/build

CMakeFiles/gcc_test.dir/requires: CMakeFiles/gcc_test.dir/home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/main.cpp.o.requires

.PHONY : CMakeFiles/gcc_test.dir/requires

CMakeFiles/gcc_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gcc_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gcc_test.dir/clean

CMakeFiles/gcc_test.dir/depend:
	cd /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin /home/cppprosto/dev/cCppProsto/OptimizeTechniques/OptimizeTechniques/boolean_and_or/different_compilers/bin_gcc/bin/CMakeFiles/gcc_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gcc_test.dir/depend
