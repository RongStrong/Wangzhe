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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sisyphus/Documents/cse221/Wangzhe/CPU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CpuOp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CpuOp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CpuOp.dir/flags.make

CMakeFiles/CpuOp.dir/CpuOp.cpp.o: CMakeFiles/CpuOp.dir/flags.make
CMakeFiles/CpuOp.dir/CpuOp.cpp.o: ../CpuOp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CpuOp.dir/CpuOp.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CpuOp.dir/CpuOp.cpp.o -c /Users/sisyphus/Documents/cse221/Wangzhe/CPU/CpuOp.cpp

CMakeFiles/CpuOp.dir/CpuOp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CpuOp.dir/CpuOp.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sisyphus/Documents/cse221/Wangzhe/CPU/CpuOp.cpp > CMakeFiles/CpuOp.dir/CpuOp.cpp.i

CMakeFiles/CpuOp.dir/CpuOp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CpuOp.dir/CpuOp.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sisyphus/Documents/cse221/Wangzhe/CPU/CpuOp.cpp -o CMakeFiles/CpuOp.dir/CpuOp.cpp.s

CMakeFiles/CpuOp.dir/CpuOp.cpp.o.requires:

.PHONY : CMakeFiles/CpuOp.dir/CpuOp.cpp.o.requires

CMakeFiles/CpuOp.dir/CpuOp.cpp.o.provides: CMakeFiles/CpuOp.dir/CpuOp.cpp.o.requires
	$(MAKE) -f CMakeFiles/CpuOp.dir/build.make CMakeFiles/CpuOp.dir/CpuOp.cpp.o.provides.build
.PHONY : CMakeFiles/CpuOp.dir/CpuOp.cpp.o.provides

CMakeFiles/CpuOp.dir/CpuOp.cpp.o.provides.build: CMakeFiles/CpuOp.dir/CpuOp.cpp.o


CMakeFiles/CpuOp.dir/test.cpp.o: CMakeFiles/CpuOp.dir/flags.make
CMakeFiles/CpuOp.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CpuOp.dir/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CpuOp.dir/test.cpp.o -c /Users/sisyphus/Documents/cse221/Wangzhe/CPU/test.cpp

CMakeFiles/CpuOp.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CpuOp.dir/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sisyphus/Documents/cse221/Wangzhe/CPU/test.cpp > CMakeFiles/CpuOp.dir/test.cpp.i

CMakeFiles/CpuOp.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CpuOp.dir/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sisyphus/Documents/cse221/Wangzhe/CPU/test.cpp -o CMakeFiles/CpuOp.dir/test.cpp.s

CMakeFiles/CpuOp.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/CpuOp.dir/test.cpp.o.requires

CMakeFiles/CpuOp.dir/test.cpp.o.provides: CMakeFiles/CpuOp.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/CpuOp.dir/build.make CMakeFiles/CpuOp.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/CpuOp.dir/test.cpp.o.provides

CMakeFiles/CpuOp.dir/test.cpp.o.provides.build: CMakeFiles/CpuOp.dir/test.cpp.o


# Object files for target CpuOp
CpuOp_OBJECTS = \
"CMakeFiles/CpuOp.dir/CpuOp.cpp.o" \
"CMakeFiles/CpuOp.dir/test.cpp.o"

# External object files for target CpuOp
CpuOp_EXTERNAL_OBJECTS =

CpuOp: CMakeFiles/CpuOp.dir/CpuOp.cpp.o
CpuOp: CMakeFiles/CpuOp.dir/test.cpp.o
CpuOp: CMakeFiles/CpuOp.dir/build.make
CpuOp: CMakeFiles/CpuOp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CpuOp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CpuOp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CpuOp.dir/build: CpuOp

.PHONY : CMakeFiles/CpuOp.dir/build

CMakeFiles/CpuOp.dir/requires: CMakeFiles/CpuOp.dir/CpuOp.cpp.o.requires
CMakeFiles/CpuOp.dir/requires: CMakeFiles/CpuOp.dir/test.cpp.o.requires

.PHONY : CMakeFiles/CpuOp.dir/requires

CMakeFiles/CpuOp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CpuOp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CpuOp.dir/clean

CMakeFiles/CpuOp.dir/depend:
	cd /Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sisyphus/Documents/cse221/Wangzhe/CPU /Users/sisyphus/Documents/cse221/Wangzhe/CPU /Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug /Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug /Users/sisyphus/Documents/cse221/Wangzhe/CPU/cmake-build-debug/CMakeFiles/CpuOp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CpuOp.dir/depend

