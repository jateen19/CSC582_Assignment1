#ifndef FULLADDER_H
#define FULLADDER_H

#include "HalfAdder.h"

class FullAdder
{
public:
    // Constructor for FullAdder
    FullAdder();

    // Setting inputs A, B, and carry-in for the full adder
    void setInputs(unsigned short usiIn1, unsigned short usiIn2, unsigned short usiCarryIn);


    unsigned short getSum() const;

    unsigned short getCarry() const;

private:
    HalfAdder m_halfAdder1; // First half-adder
    HalfAdder m_halfAdder2; // Second half-adder
    unsigned short m_usiCarryIn; // Input carry value
};

#endif
