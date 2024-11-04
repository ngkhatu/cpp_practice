cmake_minimum_required(VERSION 3.10)

project(Learncpp)




set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_executable(Learncpp main.cpp)


SET(CXXFLAGS "-Wsign-conversion")
SET(CMAKE_CXX_FLAGS  ${CXXFLAGS})




#[==[
# specify where the executable target should look for include files
target_include_directories()
target_link_libraries()
]==]

#########################################################################
#[===[ To build a new library:

# Identify Library Target(all executable files) and sources files
add_library(MathFunctions MathFunctions.cxx mysqrt.cxx)
# To make use of the new library we will add an add_subdirectory() call in the top-level CMakeLists.txt file so that the library will get built.
add_subdirectory(MathFunctions)
# new library target is linked to the executable target
target_link_libraries(Tutorial PUBLIC MathFunctions)
# specify the library's header file location. Modify the existing target_include_directories() call to add the MathFunctions subdirectory as an include directory so that the MathFunctions.h header file can be found.
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )

# Use library in code with Header
#include "MathFunctions.h"


#]===]
#########################################################################
