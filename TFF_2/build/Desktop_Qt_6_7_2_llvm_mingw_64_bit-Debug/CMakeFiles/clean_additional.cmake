# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ders2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ders2_autogen.dir\\ParseCache.txt"
  "Ders2_autogen"
  )
endif()
