#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"

/**
 * @class HalfAdder
 * @brief A class representing a half-adder circuit using basic logic gates.
 *
 * The HalfAdder class simulates the behavior of a half-adder, which performs
 * binary addition on two input bits and produces a sum and a carry bit.
 */

class HalfAdder {
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


    unsigned short int getSum() const;


    unsigned short int getCarry() const;

private:
    AND m_andGate;
    OR m_orGate;
    NAND m_nandGate;

    unsigned short int m_sum;
    unsigned short int m_carry;
};

#endif
