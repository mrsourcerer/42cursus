# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /snap/cmake/1288/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1288/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild

# Utility rule file for imgui-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/imgui-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/imgui-populate.dir/progress.make

CMakeFiles/imgui-populate: CMakeFiles/imgui-populate-complete

CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'imgui-populate'"
	/snap/cmake/1288/bin/cmake -E make_directory /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles
	/snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles/imgui-populate-complete
	/snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-done

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update:
.PHONY : imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'imgui-populate'"
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E echo_append
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure: imgui-populate-prefix/tmp/imgui-populate-cfgcmd.txt
imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'imgui-populate'"
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E echo_append
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-gitinfo.txt
imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'imgui-populate'"
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps && /snap/cmake/1288/bin/cmake -P /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-gitclone.cmake
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps && /snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'imgui-populate'"
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E echo_append
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'imgui-populate'"
	/snap/cmake/1288/bin/cmake -Dcfgdir= -P /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-mkdirs.cmake
	/snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'imgui-populate'"
	/snap/cmake/1288/bin/cmake -E echo_append
	/snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update:
.PHONY : imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'imgui-populate'"
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E echo_append
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-build && /snap/cmake/1288/bin/cmake -E touch /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'imgui-populate'"
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-src && /snap/cmake/1288/bin/cmake -P /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-gitupdate.cmake

imgui-populate: CMakeFiles/imgui-populate
imgui-populate: CMakeFiles/imgui-populate-complete
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update
imgui-populate: CMakeFiles/imgui-populate.dir/build.make
.PHONY : imgui-populate

# Rule to build all files generated by this target.
CMakeFiles/imgui-populate.dir/build: imgui-populate
.PHONY : CMakeFiles/imgui-populate.dir/build

CMakeFiles/imgui-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imgui-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imgui-populate.dir/clean

CMakeFiles/imgui-populate.dir/depend:
	cd /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild /home/sourcerer/projects/42cursus/prueba/push_swap_clion/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles/imgui-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imgui-populate.dir/depend

