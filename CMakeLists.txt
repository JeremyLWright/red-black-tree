cmake_minimum_required (VERSION 2.6)

project(red_black_tree)

find_package(GTest)
find_package(Doxygen)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(BaseCode)
#doxygen confg
add_custom_target(doxygen
${DOXYGEN_EXECUTABLE}
${CMAKE_CURRENT_SOURCE_DIR}/config.doxygen)
#cleanup documentation on "make clean"
set_property(DIRECTORY APPEND PROPERTY
ADDITIONAL_MAKE_CLEAN_FILES
../docs)
#add doxygen as dependency to doc-target
get_target_property(DOC_TARGET doc TYPE)
if(NOT DOC_TARGET)
add_custom_target(doc)
endif()
add_dependencies(doc doxygen)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_RELEASE "-O0 -ansi -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -pedantic -ansi -Wall")
file(GLOB PROJECT_SOURCE_FILES "BaseCode/*.cpp")

# Build the executable
add_executable(main main.cpp ${PROJECT_SOURCE_FILES})


if(GTEST_FOUND)
    file(GLOB TEST_SOURCE_FILES "Tests/*.cpp")
    add_custom_target(test COMMAND test_${PROJECT_NAME} DEPENDS test_${PROJECT_NAME})
    add_executable(test_${PROJECT_NAME} ${TEST_SOURCE_FILES})
    add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCE_FILES})
    target_link_libraries(test_${PROJECT_NAME} ${PROJECT_NAME})
    target_link_libraries(test_${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
endif(GTEST_FOUND) 
