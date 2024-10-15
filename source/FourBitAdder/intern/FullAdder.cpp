#include "FullAdder.h"

// Constructor to initialize carry-in value
FullAdder::FullAdder() : m_usiCarryIn(0) {}

// Set the inputs for the full adder
void FullAdder::setInputs(unsigned short usiIn1, unsigned short usiIn2, unsigned short usiCarryIn)
{
    m_usiCarryIn = usiCarryIn;
    m_halfAdder1.setInputs(usiIn1, usiIn2);
    m_halfAdder2.setInputs(m_halfAdder1.getSum(), m_usiCarryIn);
}


unsigned short FullAdder::getSum() const
{
    return m_halfAdder2.getSum();
}

unsigned short FullAdder::getCarry() const
{
    return m_halfAdder1.getCarry() | m_halfAdder2.getCarry();
}
