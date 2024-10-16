/**
 * @file AbstractDevice.h
 * @brief Declaration of the AbstractDevice class, serving as a base class for all logic circuits in the system.
 *
 * @author [Jateen Joharapurkar]
 * @author [Mantra Mehta]
 * @author [Vinay Kasyap]
 */


#ifndef ABSTRACTDEVICE_H
#define ABSTRACTDEVICE_H

/**
 * @class AbstractDevice
 * @brief A base class for all devices (circuits) in the system.
 *
 * The AbstractDevice class enforces the updating of output pins whenever the input pins are modified.
 * Derived classes must implement the update() method to perform their specific logic operations.
 */
class AbstractDevice {
public:
    /**
     * @brief Default constructor for AbstractDevice.
     */
    AbstractDevice() : m_usiIn1(0), m_usiIn2(0), m_usiOut(0) {}

    /**
     * @brief Virtual destructor for AbstractDevice.
     */
    virtual ~AbstractDevice() {}

    /**
     * @brief Sets the input pins for the device.
     *
     * This method sets the input pins and triggers the update() method to recalculate the outputs.
     *
     * @param usiIn1 The value for input pin 1 (0 or 1).
     * @param usiIn2 The value for input pin 2 (0 or 1).
     */
    void setInputs(const unsigned short int usiIn1, const unsigned short int usiIn2) {
        m_usiIn1 = usiIn1;
        m_usiIn2 = usiIn2;
        update(); // Trigger recalculation of outputs
    }

    /**
     * @brief Gets the output value from the device.
     *
     * @return The output value (0 or 1).
     */
    virtual unsigned short int getSum() const = 0;

    /**
     * @brief Gets the carry output value from the device.
     *
     * @return The carry value (0 or 1).
     */
    virtual unsigned short int getCarry() const = 0;

protected:
    /**
     * @brief Recalculates the output values based on the current inputs.
     *
     * This method must be implemented in derived classes to define the specific behavior
     * of each device (e.g., HalfAdder, FullAdder).
     */
    virtual void update() = 0;

protected:
    unsigned short int m_usiIn1;  ///< Input pin 1
    unsigned short int m_usiIn2;  ///< Input pin 2
    unsigned short int m_usiOut;  ///< Output pin
};

#endif // ABSTRACTDEVICE_H
