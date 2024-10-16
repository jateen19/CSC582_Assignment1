/**
 * @file FourBitAdder.h
 * @brief Declaration of the FourBitAdder class, which adds two four-bit binary numbers using four FullAdder instances.
 *
 * @author [Jateen Joharapurkar]
 * @author [Mantra Mehta]
 * @author [Vinay Kasyap]
 */

#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include "intern/FullAdder.h"
#include <string>
#include <vector>

/**
 * @class FourBitAdder
 * @brief A class that represents a four-bit adder using four FullAdder instances.
 *
 * This class adds two four-bit binary numbers and returns their sum
 * along with the carry-out bit.
 */
class FourBitAdder
{
public:
    /**
     * @brief Constructor for the FourBitAdder.
     *
     * Initializes the four FullAdder instances and connects them together.
     */
    FourBitAdder();

    /**
     * @brief Adds two four-bit binary numbers along with an optional carry-in.
     *
     * @param strBinaryA The first four-bit binary number as a string
     * @param strBinaryB The second four-bit binary number as a string
     * @param iCarry The carry-in value (0 or 1).
     * @return The resulting sum as a string, including the carry-out bit.
     */
    std::string add(const std::string& strBinaryA, const std::string& strBinaryB, int iCarry);

private:
    /**
     * @brief Connects the adders together to propagate the carry-out.
     */
    void connectAdders();

    FullAdder m_fullAdders[4]; /**< Array of four FullAdder instances for each bit position. */
};

#endif
