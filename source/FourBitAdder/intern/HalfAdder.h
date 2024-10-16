/**
 * @file HalfAdder.h
 * @brief Declaration of the HalfAdder class, representing a half-adder circuit using basic logic gates.
 *
 *
 * @author [Jateen Joharapurkar]
 * @author [Mantra Mehta]
 * @author [Vinay Kasyap]
 */



#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"
#include "AbstractDevice.h" // Include AbstractDevice header

/**
 * @class HalfAdder
 * @brief A class representing a half-adder circuit using basic logic gates.
 *
 * The HalfAdder class simulates the behavior of a half-adder, which performs
 * binary addition on two input bits and produces a sum and a carry bit.
 */
class HalfAdder : public AbstractDevice {
public:
    HalfAdder();
    ~HalfAdder();

    /**
     * @brief Sets the input values for the half-adder.
     *
     * @param usiA The first input bit (A).
     * @param usiB The second input bit (B).
     */
    void setInputs(const unsigned short int usiA, const unsigned short int usiB);

    unsigned short int getSum() const override; // Override getSum from AbstractDevice

    unsigned short int getCarry() const override; // Override getCarry from AbstractDevice

protected:
    void update() override; // Override update method from AbstractDevice

private:
    AND m_andGate; ///< AND gate for carry calculation
    OR m_orGate; ///< OR gate for sum calculation (XOR functionality)
    NAND m_nandGate; ///< NAND gate used for XOR calculation

    unsigned short int m_sum; ///< Holds the result of the sum
    unsigned short int m_carry; ///< Holds the result of the carry
};

#endif  
