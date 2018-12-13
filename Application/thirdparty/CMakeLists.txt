set(GOOGLETEST_DIR "${CMAKE_CURRENT_LIST_DIR}/googletest" CACHE PATH "path to gtest")
include(ExternalProject)
set(GOOGLETEST_NAME GTest)
ExternalProject_Add(${GOOGLETEST_NAME}
  SOURCE_DIR $ENV{GOOGLETEST_DIR}
  CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=/home/ocagdas/companies/tunstall/cmake_test/Application/thirdparty/googletest/libs/x86_64")
ExternalProject_Get_Property(${GOOGLETEST_NAME} INSTALL_DIR)

set(GTEST_ROOT ${INSTALL_DIR})
find_package(GTest)
if(NOT GTEST_LIBRARY)
  message(WARNING "gtest not found, call make first to build it and cmake again afterwards")
  return()
endif()

message(STATUS "rest of the build")
