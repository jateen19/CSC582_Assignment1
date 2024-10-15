/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.

#include "../FourBitAdder.h"
#include <sstream>
#include <algorithm>
#include <iostream>

FourBitAdder::FourBitAdder()
{
    // Initialize the 4 FullAdder objects
    for (int i = 0; i < 4; i++)
    {
        m_fullAdders[i] = FullAdder();
    }
    connectAdders();
}

void FourBitAdder::connectAdders()
{
    int iCarryIn = 0;  // Initial carry is set to 0
    for (int i = 0; i < 4; i++)
    {

        m_fullAdders[i].setInputs(0, 0, iCarryIn);
        iCarryIn = m_fullAdders[i].getCarry();  // Here we update carry for the next FullAdder
    }
}

std::string FourBitAdder::add(const std::string& strBinaryA, const std::string& strBinaryB, int iCarry)
{
    std::stringstream ssResult;

    // Bit-wise addition from least significant to most significant bit
    for (int i = strBinaryA.length() - 1; i >= 0; i--)
    {
        int iBitA = strBinaryA[i] - '0';
        int iBitB = strBinaryB[i] - '0';

        // Setting the inputs to the current FullAdder
        m_fullAdders[i].setInputs(iBitA, iBitB, iCarry);
        int iSum = m_fullAdders[i].getSum();
        iCarry = m_fullAdders[i].getCarry();  // Here we update carry for the next FullAdder

        ssResult << iSum;  // Appending sum to result
    }

    ssResult << iCarry;  // Appending the final carry bit

    std::string strResult = ssResult.str();
    std::reverse(strResult.begin(), strResult.end());  // Reversing the result to ensure correct order


    while (strResult.length() < 5)
    {
        strResult.insert(strResult.begin(), '0');
    }

    return strResult;
}
