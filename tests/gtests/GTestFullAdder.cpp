#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/FullAdder.h"
#include <iostream>

TEST(FullAdderTest, testFullAdderSum)
{
    FullAdder fullAdder;

    std::cout << "Truth Table for Full Adder" << std::endl;
    std::cout << "+-------+--------+----------+----------+--------+" << std::endl;
    std::cout << "|   A   |   B    | CarryIn  |  Sum  | CarryOut  |" << std::endl;
    std::cout << "+-------+--------+----------+----------+--------+" << std::endl;

    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                fullAdder.setInputs(a, b, c);

                int sum = fullAdder.getSum();
                int carryOut = fullAdder.getCarry();

                std::cout << "|   " << a << "   |   " << b << "   |   " << c << "   |    " << sum << "  |    " << carryOut << "    |" << std::endl;
                ASSERT_EQ((a ^ b) ^ c, sum); // Sum = A XOR B XOR CarryIn
                ASSERT_EQ((a & b) | (b & c) | (c & a), carryOut);

            }
        }
    }
    std::cout << "+-------+------+-----------+----------+--------+--------+" << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
