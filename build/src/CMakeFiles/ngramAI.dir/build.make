# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tonyx\Documents\ngramAI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tonyx\Documents\ngramAI\build

# Include any dependencies generated for this target.
include src/CMakeFiles/ngramAI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/ngramAI.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ngramAI.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ngramAI.dir/flags.make

src/CMakeFiles/ngramAI.dir/codegen:
.PHONY : src/CMakeFiles/ngramAI.dir/codegen

src/CMakeFiles/ngramAI.dir/main.cpp.obj: src/CMakeFiles/ngramAI.dir/flags.make
src/CMakeFiles/ngramAI.dir/main.cpp.obj: C:/Users/tonyx/Documents/ngramAI/src/main.cpp
src/CMakeFiles/ngramAI.dir/main.cpp.obj: src/CMakeFiles/ngramAI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tonyx\Documents\ngramAI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ngramAI.dir/main.cpp.obj"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ngramAI.dir/main.cpp.obj -MF CMakeFiles\ngramAI.dir\main.cpp.obj.d -o CMakeFiles\ngramAI.dir\main.cpp.obj -c C:\Users\tonyx\Documents\ngramAI\src\main.cpp

src/CMakeFiles/ngramAI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ngramAI.dir/main.cpp.i"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tonyx\Documents\ngramAI\src\main.cpp > CMakeFiles\ngramAI.dir\main.cpp.i

src/CMakeFiles/ngramAI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ngramAI.dir/main.cpp.s"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tonyx\Documents\ngramAI\src\main.cpp -o CMakeFiles\ngramAI.dir\main.cpp.s

src/CMakeFiles/ngramAI.dir/utils.cpp.obj: src/CMakeFiles/ngramAI.dir/flags.make
src/CMakeFiles/ngramAI.dir/utils.cpp.obj: C:/Users/tonyx/Documents/ngramAI/src/utils.cpp
src/CMakeFiles/ngramAI.dir/utils.cpp.obj: src/CMakeFiles/ngramAI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tonyx\Documents\ngramAI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ngramAI.dir/utils.cpp.obj"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ngramAI.dir/utils.cpp.obj -MF CMakeFiles\ngramAI.dir\utils.cpp.obj.d -o CMakeFiles\ngramAI.dir\utils.cpp.obj -c C:\Users\tonyx\Documents\ngramAI\src\utils.cpp

src/CMakeFiles/ngramAI.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ngramAI.dir/utils.cpp.i"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tonyx\Documents\ngramAI\src\utils.cpp > CMakeFiles\ngramAI.dir\utils.cpp.i

src/CMakeFiles/ngramAI.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ngramAI.dir/utils.cpp.s"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tonyx\Documents\ngramAI\src\utils.cpp -o CMakeFiles\ngramAI.dir\utils.cpp.s

# Object files for target ngramAI
ngramAI_OBJECTS = \
"CMakeFiles/ngramAI.dir/main.cpp.obj" \
"CMakeFiles/ngramAI.dir/utils.cpp.obj"

# External object files for target ngramAI
ngramAI_EXTERNAL_OBJECTS =

src/ngramAI.exe: src/CMakeFiles/ngramAI.dir/main.cpp.obj
src/ngramAI.exe: src/CMakeFiles/ngramAI.dir/utils.cpp.obj
src/ngramAI.exe: src/CMakeFiles/ngramAI.dir/build.make
src/ngramAI.exe: src/CMakeFiles/ngramAI.dir/linkLibs.rsp
src/ngramAI.exe: src/CMakeFiles/ngramAI.dir/objects1.rsp
src/ngramAI.exe: src/CMakeFiles/ngramAI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\tonyx\Documents\ngramAI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ngramAI.exe"
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ngramAI.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ngramAI.dir/build: src/ngramAI.exe
.PHONY : src/CMakeFiles/ngramAI.dir/build

src/CMakeFiles/ngramAI.dir/clean:
	cd /d C:\Users\tonyx\Documents\ngramAI\build\src && $(CMAKE_COMMAND) -P CMakeFiles\ngramAI.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/ngramAI.dir/clean

src/CMakeFiles/ngramAI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tonyx\Documents\ngramAI C:\Users\tonyx\Documents\ngramAI\src C:\Users\tonyx\Documents\ngramAI\build C:\Users\tonyx\Documents\ngramAI\build\src C:\Users\tonyx\Documents\ngramAI\build\src\CMakeFiles\ngramAI.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/ngramAI.dir/depend

