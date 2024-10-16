#include "FullAdder.h"

/**
 * @brief Constructor to initialize the carry-in value to 0.
 */
FullAdder::FullAdder() : m_usiCarryIn(0) {}

/**
 * @brief Set the inputs for the FullAdder.
 *
 * @param usiIn1 The first input value (A).
 * @param usiIn2 The second input value (B).
 * @param usiCarryIn The carry-in value from the previous addition.
 *
 * This function sets the inputs for both half-adders and propagates the
 * carry-in value to calculate the final sum and carry-out.
 */
void FullAdder::setInputs(unsigned short usiIn1, unsigned short usiIn2, unsigned short usiCarryIn)
{
    m_usiCarryIn = usiCarryIn;
    m_halfAdder1.setInputs(usiIn1, usiIn2);  // Set inputs to the first half-adder
    m_halfAdder2.setInputs(m_halfAdder1.getSum(), m_usiCarryIn);  // Pass sum to the second half-adder
    update();  // Call update to ensure outputs are set
}

/**
 * @brief Get the sum of the FullAdder operation.
 *
 * @return The sum (A ⊕ B ⊕ CarryIn).
 */
unsigned short FullAdder::getSum() const
{
    return m_halfAdder2.getSum();
}

/**
 * @brief Get the carry-out of the FullAdder operation.
 *
 * @return The carry-out (A ∧ B) ∨ (B ∧ CarryIn) ∨ (CarryIn ∧ A).
 */
unsigned short FullAdder::getCarry() const
{
    return m_halfAdder1.getCarry() | m_halfAdder2.getCarry();
}

/**
 * @brief Updates the FullAdder's outputs based on the current inputs.
 */
void FullAdder::update()
{
    // Updates are propagated through the half-adders
    m_halfAdder1.getSum();
    m_halfAdder1.getCarry();
    m_halfAdder2.getSum();
    m_halfAdder2.getCarry();
}
