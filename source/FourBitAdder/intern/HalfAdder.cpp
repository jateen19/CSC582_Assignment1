#include "HalfAdder.h"

/**
 * @brief Constructor to initialize the required gates and set the initial sum and carry to zero.
 */
HalfAdder::HalfAdder() : m_andGate(1), m_orGate(1), m_nandGate(1), m_sum(0), m_carry(0) {}

/**
 * @brief Destructor for the HalfAdder class.
 */
HalfAdder::~HalfAdder() {}

/**
 * @brief Sets the inputs A and B for the HalfAdder.
 *
 * This method calculates the sum (A XOR B) and the carry (A AND B) using logic gates.
 *
 * @param usiA First input value (0 or 1).
 * @param usiB Second input value (0 or 1).
 */
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
    m_sum = m_nandGate.out();

    // Finding carry
    m_andGate.set_in1(usiA);
    m_andGate.set_in2(usiB);
    m_carry = m_andGate.out();
}

/**
 * @brief Gets the sum (A XOR B) calculated by the half-adder.
 *
 * @return The sum value (0 or 1).
 */
unsigned short int HalfAdder::getSum() const
{
    return m_sum;
}

/**
 * @brief Gets the carry (A AND B) calculated by the half-adder.
 *
 * @return The carry value (0 or 1).
 */
unsigned short int HalfAdder::getCarry() const
{
    return m_carry;
}
