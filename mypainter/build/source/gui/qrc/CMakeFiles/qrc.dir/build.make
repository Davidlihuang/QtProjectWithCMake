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

# Include any dependencies generated for this target.
include source/gui/qrc/CMakeFiles/qrc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/gui/qrc/CMakeFiles/qrc.dir/compiler_depend.make

# Include the progress variables for this target.
include source/gui/qrc/CMakeFiles/qrc.dir/progress.make

# Include the compile flags for this target's objects.
include source/gui/qrc/CMakeFiles/qrc.dir/flags.make

source/gui/qrc/qrc_form.cpp: /home/huangli/qtexample/QtProjectWithCMake/mypainter/source/gui/qrc/form.qrc
source/gui/qrc/qrc_form.cpp: source/gui/qrc/form.qrc.depends
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/huangli/qtexample/QtProjectWithCMake/mypainter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating qrc_form.cpp"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /opt/Qt5.12.12/5.12.12/gcc_64/bin/rcc --name form --output /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_form.cpp /home/huangli/qtexample/QtProjectWithCMake/mypainter/source/gui/qrc/form.qrc

source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o: source/gui/qrc/CMakeFiles/qrc.dir/flags.make
source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o: source/gui/qrc/qrc_autogen/mocs_compilation.cpp
source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o: source/gui/qrc/CMakeFiles/qrc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangli/qtexample/QtProjectWithCMake/mypainter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o -MF CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o -c /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_autogen/mocs_compilation.cpp

source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.i"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_autogen/mocs_compilation.cpp > CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.i

source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.s"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_autogen/mocs_compilation.cpp -o CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.s

source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.o: source/gui/qrc/CMakeFiles/qrc.dir/flags.make
source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.o: source/gui/qrc/qrc_form.cpp
source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.o: source/gui/qrc/CMakeFiles/qrc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangli/qtexample/QtProjectWithCMake/mypainter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.o"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.o -MF CMakeFiles/qrc.dir/qrc_form.cpp.o.d -o CMakeFiles/qrc.dir/qrc_form.cpp.o -c /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_form.cpp

source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qrc.dir/qrc_form.cpp.i"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_form.cpp > CMakeFiles/qrc.dir/qrc_form.cpp.i

source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qrc.dir/qrc_form.cpp.s"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/qrc_form.cpp -o CMakeFiles/qrc.dir/qrc_form.cpp.s

# Object files for target qrc
qrc_OBJECTS = \
"CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/qrc.dir/qrc_form.cpp.o"

# External object files for target qrc
qrc_EXTERNAL_OBJECTS =

/home/huangli/qtexample/QtProjectWithCMake/mypainter/bin/libarary/static/libqrc.a: source/gui/qrc/CMakeFiles/qrc.dir/qrc_autogen/mocs_compilation.cpp.o
/home/huangli/qtexample/QtProjectWithCMake/mypainter/bin/libarary/static/libqrc.a: source/gui/qrc/CMakeFiles/qrc.dir/qrc_form.cpp.o
/home/huangli/qtexample/QtProjectWithCMake/mypainter/bin/libarary/static/libqrc.a: source/gui/qrc/CMakeFiles/qrc.dir/build.make
/home/huangli/qtexample/QtProjectWithCMake/mypainter/bin/libarary/static/libqrc.a: source/gui/qrc/CMakeFiles/qrc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huangli/qtexample/QtProjectWithCMake/mypainter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library /home/huangli/qtexample/QtProjectWithCMake/mypainter/bin/libarary/static/libqrc.a"
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && $(CMAKE_COMMAND) -P CMakeFiles/qrc.dir/cmake_clean_target.cmake
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qrc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/gui/qrc/CMakeFiles/qrc.dir/build: /home/huangli/qtexample/QtProjectWithCMake/mypainter/bin/libarary/static/libqrc.a
.PHONY : source/gui/qrc/CMakeFiles/qrc.dir/build

source/gui/qrc/CMakeFiles/qrc.dir/clean:
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc && $(CMAKE_COMMAND) -P CMakeFiles/qrc.dir/cmake_clean.cmake
.PHONY : source/gui/qrc/CMakeFiles/qrc.dir/clean

source/gui/qrc/CMakeFiles/qrc.dir/depend: source/gui/qrc/qrc_form.cpp
	cd /home/huangli/qtexample/QtProjectWithCMake/mypainter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangli/qtexample/QtProjectWithCMake/mypainter /home/huangli/qtexample/QtProjectWithCMake/mypainter/source/gui/qrc /home/huangli/qtexample/QtProjectWithCMake/mypainter/build /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc /home/huangli/qtexample/QtProjectWithCMake/mypainter/build/source/gui/qrc/CMakeFiles/qrc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/gui/qrc/CMakeFiles/qrc.dir/depend

