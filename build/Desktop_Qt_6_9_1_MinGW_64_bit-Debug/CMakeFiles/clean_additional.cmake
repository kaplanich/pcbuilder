# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\pcbuilder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\pcbuilder_autogen.dir\\ParseCache.txt"
  "pcbuilder_autogen"
  )
endif()
