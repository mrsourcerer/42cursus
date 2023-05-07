# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-src"
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-build"
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix"
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/danlopez/projects/prueba/push_swap_clion/push_swap_visualizer/build_42/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
