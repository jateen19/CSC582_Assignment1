/*
 * AbstractGate.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 */

#include "../../FourBitAdder/intern/AbstractGate.h"


/**
 * Sets pin #1.
 * @param unsigned int pin #1
 * @return None.
 */
void AbstractGate::set_in1(const unsigned short int val)
{
    m_usiIn1 = val;
    update();
}

/**
 * Sets pin #2.
 * @param unsigned int pin #1
 * @return None.
 */
void AbstractGate::set_in2(const unsigned short int val)
{
    m_usiIn2 = val;
    update();
}

/**
 * Access pin out.
 * @param void no comments.
 * @return the pin value.
 */
const unsigned short int AbstractGate::out() const
{
    return m_usiOut;
}

/**
 * Function name, description here.
 * @param type comments.
 * @param type comments.
 * @return type comments.
 */
const unsigned short int AbstractGate::in1() const
{
    return m_usiIn1;
}


/**
 * Function name, description here.
 * @param type comments.
 * @param type comments.
 * @return type comments.
 */
const unsigned short int AbstractGate::in2() const
{
    return m_usiIn2;
}

/**
 * Function name, description here.
 * @param type comments.
 * @param type comments.
 * @return type comments.
 */
std::string AbstractGate::repr()
{
    return "in1: " + std::to_string(m_usiIn1) + "\n\tin2: " + std::to_string(m_usiIn2)
           + "\n\t\tout: " + std::to_string(m_usiOut);
}



