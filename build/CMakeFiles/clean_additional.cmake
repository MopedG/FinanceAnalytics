# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FinanceAnalytics_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FinanceAnalytics_autogen.dir\\ParseCache.txt"
  "FinanceAnalytics_autogen"
  )
endif()
