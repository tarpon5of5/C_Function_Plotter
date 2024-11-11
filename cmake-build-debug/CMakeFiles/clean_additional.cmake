# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/C_Function_Plotter_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/C_Function_Plotter_autogen.dir/ParseCache.txt"
  "C_Function_Plotter_autogen"
  )
endif()
