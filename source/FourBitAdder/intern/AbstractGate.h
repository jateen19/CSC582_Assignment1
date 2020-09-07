/**
 * AbstractGate.h
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 */

#ifndef _ABSTRACTGATE_H_
#define _ABSTRACTGATE_H_

#include <string>

class AbstractGate
{
public:
    /**
     * Constructor for AbstractGate.
     * Does not allow for parameters, uses initializers for pins.
     */
    AbstractGate() : m_usiIn1(0), m_usiIn2(0), m_usiOut(0) {}

    /**
     * Virtual destructor for AbstractGate.
     */
    virtual ~AbstractGate() {}

    /*
     * Accessors
     */
    const unsigned short int out() const;
    const unsigned short int in1() const;
    const unsigned short int in2() const;

    /*
     * Setters
     */
    void set_in1(const unsigned short int);
    void set_in2(const unsigned short int);

protected:
    /**   Hungarian notation: http://web.mst.edu/~cpp/common/hungarian.html
     *    https://stackoverflow.com/questions/841075/best-c-code-formatter-beautifier
     *    http://astyle.sourceforge.net/astyle.html#_Quick_Start
     */
    unsigned short int m_usiIn1; /**< input pin one */
    unsigned short int m_usiIn2; /**< input pin two */
    unsigned short int m_usiOut; /**< output pin three */

    virtual void update() = 0;
    virtual std::string repr();
};

#endif /* _ABSTRACTGATE_H_ */
