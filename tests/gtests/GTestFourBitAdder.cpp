#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"
#include <iostream>
#include <string>
#include <bitset>

TEST(FourBitAdderTest, testFourBitAdder)
{
    FourBitAdder fourBitAdder;

    std::cout << "Four Bit Adder Truth Table:" << std::endl;
    std::cout << "+---------+---------+---------+---------+---------+" << std::endl;
    std::cout << "|   binA  |   binB  |   Sum   |  Carry  | Expected |" << std::endl;
    std::cout << "+---------+---------+---------+---------+---------+" << std::endl;

    // Arrays containing test inputs for binary A and B
    std::string strInputBinA[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                                  "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
                                 };
    std::string strInputBinB[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                                  "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
                                 };


    for (const auto& strBinaryA : strInputBinA)
    {
        for (const auto& strBinaryB : strInputBinB)
        {
            std::string strSum = fourBitAdder.add(strBinaryA, strBinaryB, 0);
            int iCarryOut = strSum[0] - '0';
            strSum = strSum.substr(1);

            // Convert binary strings to integers for comparison
            int iIntA = std::bitset<4>(strBinaryA).to_ulong();
            int iIntB = std::bitset<4>(strBinaryB).to_ulong();
            int iIntSum = std::bitset<4>(strSum).to_ulong();
            int iExpectedSum = (iIntA + iIntB) & 0xF;


            std::cout << "|   " << strBinaryA << "   |   " << strBinaryB << "   |  " << strSum << "  |    " << iCarryOut
                      << "    |   " << iIntA << " + " << iIntB << "   |" << std::endl;


            ASSERT_EQ(iExpectedSum, iIntSum);


            int iExpectedCarry = (iIntA + iIntB) >> 4;
            ASSERT_EQ(iExpectedCarry, iCarryOut);
        }
    }

    std::cout << "+---------+---------+---------+---------+---------+" << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
