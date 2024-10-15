#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"

class HalfAdder {
public:
    HalfAdder();
    ~HalfAdder();

    // Set inputs A and B for the half adder
    void setInputs(const unsigned short int usiA, const unsigned short int usiB);

    // Get the calculated sum (A ⊕ B)
    unsigned short int getSum() const;

    // Get the calculated carry (A ∧ B)
    unsigned short int getCarry() const;

private:
    AND m_andGate;   // For calculating the carry
    OR m_orGate;     // Used with NAND to calculate XOR (sum)
    NAND m_nandGate; // Used with OR to calculate XOR (sum)

    unsigned short int m_sum;   // Holds the result of the sum
    unsigned short int m_carry; // Holds the result of the carry
};

#endif  // HALFADDER_H
