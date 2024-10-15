#include "HalfAdder.h"

// Constructor to initialize the gates and set the initial sum and carry to zero
HalfAdder::HalfAdder() : m_andGate(1), m_orGate(1), m_nandGate(1), m_sum(0), m_carry(0) {}

HalfAdder::~HalfAdder() {}


// A and B are inputs, sum is A XOR B while carry is A AND B
void HalfAdder::setInputs(const unsigned short int usiA, const unsigned short int usiB)
{

    // Use NAND on inputs A and B
    m_nandGate.set_in1(usiA);
    m_nandGate.set_in2(usiB);
    unsigned short int usiNand1 = m_nandGate.out();

    // Use NAND on A and output of first NAND gate
    m_nandGate.set_in1(usiA);
    m_nandGate.set_in2(usiNand1);
    unsigned short int usiNand2 = m_nandGate.out();

    // Use NAND on B and output of first NAND gate
    m_nandGate.set_in1(usiNand1);
    m_nandGate.set_in2(usiB);
    unsigned short int usiNand3 = m_nandGate.out();

    // XOR (sum) is the NAND of the outputs from above two
    m_nandGate.set_in1(usiNand2);
    m_nandGate.set_in2(usiNand3);
    m_sum = m_nandGate.out();  // Sum is the XOR of A and B

    // Finding carry
    m_andGate.set_in1(usiA);
    m_andGate.set_in2(usiB);
    m_carry = m_andGate.out();  // Carry is A AND B
}


unsigned short int HalfAdder::getSum() const
{
    return m_sum;
}


unsigned short int HalfAdder::getCarry() const
{
    return m_carry;
}
