#include "../FourBitAdder.h"
#include <sstream>
#include <algorithm>
#include <iostream>

/**
 * @brief Constructor for the FourBitAdder.
 *
 * Initializes the four FullAdder objects and connects them.
 */
FourBitAdder::FourBitAdder()
{
    // Initialize the 4 FullAdder objects
    for (int i = 0; i < 4; i++)
    {
        m_fullAdders[i] = FullAdder();
    }
    connectAdders();
}

/**
 * @brief Connects the adders to propagate carry between them.
 *
 * This method initializes each FullAdder with carry propagation logic.
 */
void FourBitAdder::connectAdders()
{
    int iCarryIn = 0;  // Initial carry is set to 0
    for (int i = 0; i < 4; i++)
    {
        m_fullAdders[i].setInputs(0, 0, iCarryIn);
        iCarryIn = m_fullAdders[i].getCarry();  // Update carry for the next FullAdder
    }
}

/**
 * @brief Adds two four-bit binary numbers and an optional carry-in.
 *
 * @param strBinaryA The first binary number represented as a string.
 * @param strBinaryB The second binary number represented as a string.
 * @param iCarry The carry-in value (0 or 1).
 * @return The resulting sum of the two binary numbers as a string.
 *
 * This function performs a bit-wise addition of two four-bit binary numbers
 * and returns the resulting sum including the carry-out bit.
 */
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
        iCarry = m_fullAdders[i].getCarry();  // Update carry for the next FullAdder

        ssResult << iSum;  // Append the sum to the result
    }

    ssResult << iCarry;  // Append the final carry bit

    std::string strResult = ssResult.str();
    std::reverse(strResult.begin(), strResult.end());  

    
    while (strResult.length() < 5)
    {
        strResult.insert(strResult.begin(), '0');
    }

    return strResult;
}
