#ifndef FULLADDER_H
#define FULLADDER_H

#include "HalfAdder.h"
#include "AbstractDevice.h"

/**
 * @class FullAdder
 * @brief It represents a full-adder, which performs binary addition of two bits and a carry-in.
 */
class FullAdder : public AbstractDevice
{
public:
    /**
     * @brief Constructor for FullAdder.
     *
     * Initializes the two half-adders and sets the carry-in value to zero.
     */
    FullAdder();

    /**
     * @brief Sets the inputs A, B, and carry-in for the FullAdder.
     *
     * This method calculates the sum and carry-out based on the given inputs.
     *
     * @param usiIn1 First input bit (A).
     * @param usiIn2 Second input bit (B).
     * @param usiCarryIn Carry-in value.
     */
    void setInputs(unsigned short usiIn1, unsigned short usiIn2, unsigned short usiCarryIn);

    /**
     * @brief Returns the sum (A ⊕ B ⊕ CarryIn) calculated by the FullAdder.
     *
     * @return Sum value (0 or 1).
     */
    unsigned short getSum() const override;

    /**
     * @brief Returns the carry-out (CarryOut) calculated by the FullAdder.
     *
     * @return Carry-out value (0 or 1).
     */
    unsigned short getCarry() const override;

    /**
     * @brief Updates the FullAdder's output based on its inputs.
     *
     * This method is required to satisfy the AbstractDevice interface.
     */
    void update() override;

private:
    HalfAdder m_halfAdder1;   /**< First half-adder used in the full-adder. */
    HalfAdder m_halfAdder2;   /**< Second half-adder used in the full-adder. */
    unsigned short m_usiCarryIn; /**< Input carry-in value for the full-adder. */
};

#endif
