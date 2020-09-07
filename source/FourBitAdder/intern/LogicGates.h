/*
 * LogicGates.h
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 */

#ifndef _LOGICGATES_H_
#define _LOGICGATES_H_

#include <string>
#include "../../FourBitAdder/intern/AbstractGate.h"

class AND: public AbstractGate
{
public:
    /**
     * Constructor for concrete class AND.
     */
    AND(const unsigned short int);
    virtual ~AND();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class NAND: public AbstractGate
{
public:
    NAND(const unsigned short int);
    virtual ~NAND();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class OR: public AbstractGate
{
public:
    OR(const unsigned short int);
    virtual ~OR();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

#endif /* _LOGICGATES_H_ */
