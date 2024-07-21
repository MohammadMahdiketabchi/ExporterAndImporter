cmake_minimum_required(VERSION 3.14)

project(ExxportAndImportV2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\QT\\6.7.2\\mingw_64\\bin")
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt_5\\5.15.2\\mingw81_64\\bin")
set(CMAKE_PREFIX_PATH "C:\\Qt\\QT\\6.7.2\\mingw_64\\lib\\cmake")
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt_5\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql)
add_subdirectory(spdlog)
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#add_subdirectory(googletest)
#set(GTEST_ROOT "E:\\New Folder2\\ExxportAndImportV2\\googletest\\googletest")
#find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(ExxportAndImportV2
  main.cpp
  BaseTable.h
  Group_table.cpp
  User_Table.cpp
  DetailPersonalInfo.cpp
  Table_Factory.h
  Group_table.h
  User_Table.h
  DetailPersonalInfo.h
  application.h application.cpp
  dataaccessobject.h dataaccessobject.cpp
  logger.h logger.cpp
  daotest.cpp
  grouptable_test.cpp
  usertable_test.cpp
  detailpersonalinfo_test.cpp
  application_test.cpp

)
target_link_libraries(ExxportAndImportV2 Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql spdlog::spdlog gtest_main)

include(GNUInstallDirs)
install(TARGETS ExxportAndImportV2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
