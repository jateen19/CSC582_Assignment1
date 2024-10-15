/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.
#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include "intern/FullAdder.h"
#include <string>
#include <vector>

class FourBitAdder
{
public:
    FourBitAdder();
    std::string add(const std::string& strBinaryA, const std::string& strBinaryB, int iCarry);

private:
    void connectAdders();
    FullAdder m_fullAdders[4];
};

#endif // FOURBITADDER_H

