/*
 * LogicGates.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 */

#include "../../FourBitAdder/intern/LogicGates.h"

/**** AND ****/

/**
 * Constructor for concrete class AND.
 */
AND::AND(const unsigned short int id)
{
    m_strID = std::to_string(id) + "AND";
}

/**
 * Destructor for concrete class AND.
 */
AND::~AND()
{
}

void AND::update()
{
    if (m_usiIn1)
    {
        if (m_usiIn2)
        {
            m_usiOut = 1;
        }
        else
        {
            m_usiOut = 0;
        }
    }
    else
    {
        m_usiOut = 0;
    }
}

std::string AND::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}


/**** NAND ****/

/**
 * Constructor for concrete class NAND.
 */
NAND::NAND(const unsigned short int id)
{
    m_strID = std::to_string(id) + "NAND";
}

/**
 * Destructor for concrete class NAND.
 */
NAND::~NAND()
{
}

void NAND::update()
{
    if (m_usiIn1)
    {
        if (m_usiIn2)
        {
            m_usiOut = 0;
        }
        else
        {
            m_usiOut = 1;
        }
    }
    else
    {
        m_usiOut = 1;
    }
}

std::string NAND::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}

/**** OR ****/

/**
 * Constructor for concrete class OR.
 */
OR::OR(const unsigned short int id)
{
    m_strID = std::to_string(id) + "OR";
}

/**
 * Destructor for concrete class OR.
 */
OR::~OR()
{
}

void OR::update()
{
    if (m_usiIn1)
    {
       m_usiOut = 1;
    }
    else if (m_usiIn2)
    {
        m_usiOut = 1;
    }
    else
    {
    	m_usiOut = 0;
    }
}

std::string OR::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}


