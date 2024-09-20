# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TFF_SON_1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TFF_SON_1_autogen.dir\\ParseCache.txt"
  "TFF_SON_1_autogen"
  )
endif()
