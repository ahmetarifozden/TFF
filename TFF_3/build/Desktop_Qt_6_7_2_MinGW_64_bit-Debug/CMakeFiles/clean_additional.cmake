# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ders_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ders_autogen.dir\\ParseCache.txt"
  "ders_autogen"
  )
endif()
