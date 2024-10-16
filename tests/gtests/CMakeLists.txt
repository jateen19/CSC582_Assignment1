cmake_minimum_required (VERSION 2.6)

# Google Test setup
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Include headers for all components (HalfAdder, FullAdder, FourBitAdder)
set(INC_LOGIC 
    ../../source/FourBitAdder/intern/AbstractGate.h
    ../../source/FourBitAdder/intern/LogicGates.h
    ../../source/FourBitAdder/intern/HalfAdder.h
    ../../source/FourBitAdder/intern/FullAdder.h
    ../../source/FourBitAdder/FourBitAdder.h  # FourBitAdder header
)

# Add source files for Half Adder, Full Adder, and Four Bit Adder
set(SRC_ADDERS 
    ../../source/FourBitAdder/intern/AbstractGate.cpp
    ../../source/FourBitAdder/intern/LogicGates.cpp
    ../../source/FourBitAdder/intern/HalfAdder.cpp
    ../../source/FourBitAdder/intern/FullAdder.cpp
    ../../source/FourBitAdder/intern/FourBitAdder.cpp  # FourBitAdder implementation
)

# --- Half Adder Test ---
set(SRC_HALFADDER_TEST 
    ./GTestHalfAdder.cpp  # Half Adder test file
)

add_executable(HalfAdderGTests_gtests ${SRC_HALFADDER_TEST} ${SRC_ADDERS} ${INC_LOGIC})
target_link_libraries(HalfAdderGTests_gtests ${GTEST_LIBRARIES} pthread)

# --- Full Adder Test ---
set(SRC_FULLADDER_TEST 
    ./GTestFullAdder.cpp  # Full Adder test file
)

add_executable(FullAdderGTests_gtests ${SRC_FULLADDER_TEST} ${SRC_ADDERS} ${INC_LOGIC})
target_link_libraries(FullAdderGTests_gtests ${GTEST_LIBRARIES} pthread)

# --- Four Bit Adder Test ---
set(SRC_FOURBITADDER_TEST 
    ./GTestFourBitAdder.cpp  # FourBitAdder test file
)

add_executable(FourBitAdderGTests_gtests ${SRC_FOURBITADDER_TEST} ${SRC_ADDERS} ${INC_LOGIC})
target_link_libraries(FourBitAdderGTests_gtests ${GTEST_LIBRARIES} pthread)
