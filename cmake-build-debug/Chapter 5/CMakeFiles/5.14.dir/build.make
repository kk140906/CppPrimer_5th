# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\Desktop\C++ Primer Exercise"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\Desktop\C++ Primer Exercise\cmake-build-debug"

# Include any dependencies generated for this target.
include Chapter\ 5/CMakeFiles/5.14.dir/depend.make

# Include the progress variables for this target.
include Chapter\ 5/CMakeFiles/5.14.dir/progress.make

# Include the compile flags for this target's objects.
include Chapter\ 5/CMakeFiles/5.14.dir/flags.make

Chapter\ 5/CMakeFiles/5.14.dir/5.14.cpp.obj: Chapter\ 5/CMakeFiles/5.14.dir/flags.make
Chapter\ 5/CMakeFiles/5.14.dir/5.14.cpp.obj: ../Chapter\ 5/5.14.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Desktop\C++ Primer Exercise\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Chapter 5/CMakeFiles/5.14.dir/5.14.cpp.obj"
	cd /d F:\Desktop\C__PRI~1\CMAKE-~1\CHAPTE~2 && D:\MinGW64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\5.14.dir\5.14.cpp.obj -c "F:\Desktop\C++ Primer Exercise\Chapter 5\5.14.cpp"

Chapter\ 5/CMakeFiles/5.14.dir/5.14.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5.14.dir/5.14.cpp.i"
	cd /d F:\Desktop\C__PRI~1\CMAKE-~1\CHAPTE~2 && D:\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Desktop\C++ Primer Exercise\Chapter 5\5.14.cpp" > CMakeFiles\5.14.dir\5.14.cpp.i

Chapter\ 5/CMakeFiles/5.14.dir/5.14.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5.14.dir/5.14.cpp.s"
	cd /d F:\Desktop\C__PRI~1\CMAKE-~1\CHAPTE~2 && D:\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\Desktop\C++ Primer Exercise\Chapter 5\5.14.cpp" -o CMakeFiles\5.14.dir\5.14.cpp.s

# Object files for target 5.14
5_14_OBJECTS = \
"CMakeFiles/5.14.dir/5.14.cpp.obj"

# External object files for target 5.14
5_14_EXTERNAL_OBJECTS =

Chapter\ 5/5.14.exe: Chapter\ 5/CMakeFiles/5.14.dir/5.14.cpp.obj
Chapter\ 5/5.14.exe: Chapter\ 5/CMakeFiles/5.14.dir/build.make
Chapter\ 5/5.14.exe: Chapter\ 5/CMakeFiles/5.14.dir/linklibs.rsp
Chapter\ 5/5.14.exe: Chapter\ 5/CMakeFiles/5.14.dir/objects1.rsp
Chapter\ 5/5.14.exe: Chapter\ 5/CMakeFiles/5.14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\Desktop\C++ Primer Exercise\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5.14.exe"
	cd /d F:\Desktop\C__PRI~1\CMAKE-~1\CHAPTE~2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5.14.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Chapter\ 5/CMakeFiles/5.14.dir/build: Chapter\ 5/5.14.exe

.PHONY : Chapter\ 5/CMakeFiles/5.14.dir/build

Chapter\ 5/CMakeFiles/5.14.dir/clean:
	cd /d F:\Desktop\C__PRI~1\CMAKE-~1\CHAPTE~2 && $(CMAKE_COMMAND) -P CMakeFiles\5.14.dir\cmake_clean.cmake
.PHONY : Chapter\ 5/CMakeFiles/5.14.dir/clean

Chapter\ 5/CMakeFiles/5.14.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\Desktop\C++ Primer Exercise" "F:\Desktop\C++ Primer Exercise\Chapter 5" "F:\Desktop\C++ Primer Exercise\cmake-build-debug" "F:\Desktop\C++ Primer Exercise\cmake-build-debug\Chapter 5" "F:\Desktop\C++ Primer Exercise\cmake-build-debug\Chapter 5\CMakeFiles\5.14.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : Chapter\ 5/CMakeFiles/5.14.dir/depend

