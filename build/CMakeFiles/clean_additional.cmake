# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExxportAndImportV2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExxportAndImportV2_autogen.dir\\ParseCache.txt"
  "ExxportAndImportV2_autogen"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googlemock\\gmock_autogen"
  "_deps\\googletest-build\\googlemock\\gmock_main_autogen"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googletest\\gtest_autogen"
  "_deps\\googletest-build\\googletest\\gtest_main_autogen"
  "spdlog\\CMakeFiles\\spdlog_autogen.dir\\AutogenUsed.txt"
  "spdlog\\CMakeFiles\\spdlog_autogen.dir\\ParseCache.txt"
  "spdlog\\spdlog_autogen"
  )
endif()
