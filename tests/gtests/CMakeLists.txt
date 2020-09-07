cmake_minimum_required (VERSION 2.6)

#https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
#https://github.com/google/googletest/blob/master/googletest/docs/primer.md

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INC_LOGIC 
../../source/FourBitAdder/intern/AbstractGate.h
../../source/FourBitAdder/intern/LogicGates.h
)

set(SRC_LOGIC 
./GTestLogicGates.cpp
)

add_executable(LogicGatesGTests_gtests ${SRC_LOGIC} ${INC_LOGIC})
target_link_libraries(LogicGatesGTests_gtests proj1_FourBitAdder ${GTEST_LIBRARIES} pthread)

# add cmake script for other unittests