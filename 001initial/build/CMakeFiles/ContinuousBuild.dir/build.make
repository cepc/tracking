# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /projects/ilc/soft/v01-17-06/CMake/2.8.5/bin/cmake

# The command to remove a file.
RM = /projects/ilc/soft/v01-17-06/CMake/2.8.5/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /projects/ilc/soft/v01-17-06/CMake/2.8.5/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhaomr/workdir/cepc/Tracking/001initial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhaomr/workdir/cepc/Tracking/001initial/build

# Utility rule file for ContinuousBuild.

CMakeFiles/ContinuousBuild:
	/projects/ilc/soft/v01-17-06/CMake/2.8.5/bin/ctest -D ContinuousBuild

ContinuousBuild: CMakeFiles/ContinuousBuild
ContinuousBuild: CMakeFiles/ContinuousBuild.dir/build.make
.PHONY : ContinuousBuild

# Rule to build all files generated by this target.
CMakeFiles/ContinuousBuild.dir/build: ContinuousBuild
.PHONY : CMakeFiles/ContinuousBuild.dir/build

CMakeFiles/ContinuousBuild.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousBuild.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousBuild.dir/clean

CMakeFiles/ContinuousBuild.dir/depend:
	cd /home/zhaomr/workdir/cepc/Tracking/001initial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhaomr/workdir/cepc/Tracking/001initial /home/zhaomr/workdir/cepc/Tracking/001initial /home/zhaomr/workdir/cepc/Tracking/001initial/build /home/zhaomr/workdir/cepc/Tracking/001initial/build /home/zhaomr/workdir/cepc/Tracking/001initial/build/CMakeFiles/ContinuousBuild.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousBuild.dir/depend

