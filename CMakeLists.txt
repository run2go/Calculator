cmake_minimum_required(VERSION 3.14)
project(Calculator C CXX)

include(FetchContent)
## Fetch third party libraries
# wx widgtes
set(wxWidgets_USE_STATIC 1) # link wxwidget statically 
set(wxBUILD_SHARED OFF) 	 # ^

include(FetchContent)
FetchContent_Declare(
   wxWidgets
   GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
   GIT_TAG v3.2.1
) # Download & add wxwidgets to content list

FetchContent_GetProperties(wxwidgets)
if(NOT wxwidgets_POPULATED)
   FetchContent_Populate(wxwidgets) # Make wxwidgets available
   add_subdirectory(${wxwidgets_SOURCE_DIR} ${wxwidgets_BUILD_DIR}) # Add wxwidgets project directory to project tree
endif()

## C++ Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## Headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(.)

## Source
file(GLOB_RECURSE source_list "src/*.cpp" "src/*.h" "src/*.hpp") # recursively get all files matching the pattern
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_list}) # add source files to vs source list tree

#app
add_executable(Calculator WIN32 ${source_list} Calculator.rc) # generate binary
target_include_directories(Calculator PRIVATE ${wxWidgets_SOURCE_DIR}/include) # add wxwidgets include to search path
target_link_libraries(Calculator PRIVATE wx::base wx::core) # link against wxwidget libaries.
#set_property(TARGET Calculator PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
