# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/huangli/qtexample/QtProjectWithCMake/mypainter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huangli/qtexample/QtProjectWithCMake/mypainter/build

# Utility rule file for qrc_autogen.

# Include any custom commands dependencies for this target.
include source/gui/qrc/CMakeFiles/qrc_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include source/gui/qrc/CMakeFiles/qrc_autogen.dir/progress.make

source/gui/qrc/CMakeFiles/qrc_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/huangli/qtexample/QtProjectWithCMake/mypainter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target qrc"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/local/bin/cmake -E cmake_autogen /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/CMakeFiles/qrc_autogen.dir/AutogenInfo.json Debug

qrc_autogen: source/gui/qrc/CMakeFiles/qrc_autogen
qrc_autogen: source/gui/qrc/CMakeFiles/qrc_autogen.dir/build.make
.PHONY : qrc_autogen

# Rule to build all files generated by this target.
source/gui/qrc/CMakeFiles/qrc_autogen.dir/build: qrc_autogen
.PHONY : source/gui/qrc/CMakeFiles/qrc_autogen.dir/build

source/gui/qrc/CMakeFiles/qrc_autogen.dir/clean:
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && $(CMAKE_COMMAND) -P CMakeFiles/qrc_autogen.dir/cmake_clean.cmake
.PHONY : source/gui/qrc/CMakeFiles/qrc_autogen.dir/clean

source/gui/qrc/CMakeFiles/qrc_autogen.dir/depend:
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangli/qtexample/QtProjectWithCMake/mypainter /home/huangli/qtexample/QtProjectWithCMake/mypainter/source/gui/qrc /home/huangli/qtexample/QtProjectWithCMake/mypainter/build /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/CMakeFiles/qrc_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/gui/qrc/CMakeFiles/qrc_autogen.dir/depend
