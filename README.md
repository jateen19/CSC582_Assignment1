# Four-Bit Adder Circuit Simulation

## Project Overview
This project simulates a four-bit binary adder circuit using object-oriented programming principles in C++. The system consists of logic gates (AND, OR, NAND) and implements the following components:
- **Half Adder**: Simulates a basic half-adder.
- **Full Adder**: Cascades two half-adders to handle carry bits.
- **Four-Bit Adder**: Combines four full-adders to perform binary addition on four-bit numbers.

The project includes unit tests using **Google Test** to verify the correctness of the circuit logic and generated Doxygen documentation to explain the structure of the code.

## Authors
- Jateen Joharapurkar
- Mantra Mehta
- Vinay Kasyap

## Key Components
1. **HalfAdder**: Simulates the half-adder circuit logic.
2. **FullAdder**: Combines two half-adders to create a full-adder with carry-in and carry-out functionality.
3. **FourBitAdder**: Simulates a four-bit adder circuit using four full-adders.
4. **AbstractDevice**: An abstract class enforcing the updating of output pins when inputs are set.

## Getting Started

### Prerequisites
- C++ Compiler
- CMake
- Google Test 
- Doxygen (for generating documentation)

### Building the Project
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/CSC582_Assignment1.git
    ```
2. Navigate to the project directory and create a build folder:
    ```bash
    cd CSC582_Assignment1
    mkdir build
    cd build
    ```
3. Run CMake to configure the build system:
    ```bash
    cmake ..
    ```
4. Build the project:
    ```bash
    make
    ```

### Running Tests
To run the tests using Google Test:
```bash
./tests/gtests/<gtest_executable_name>
