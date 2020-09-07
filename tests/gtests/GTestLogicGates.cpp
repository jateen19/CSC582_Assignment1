#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/LogicGates.h"

TEST(ANDConstructorTest, test001) {

    // create an object
	AND and1(1);

	// check that the object is constructed correctly
	unsigned short int in1 = and1.in1();
	ASSERT_EQ(in1, 0);
	unsigned short int in2 = and1.in2();
	ASSERT_EQ(in2, 0);
	unsigned short int out = and1.out();
	ASSERT_EQ(0, out);
}

TEST(NANDConstructorTest, test002) {

    // create an object
	NAND nand1(1);

	// check that the object is constructed correctly
	unsigned short int in1 = nand1.in1();
	ASSERT_EQ(in1, 0);
	unsigned short int in2 = nand1.in2();
	ASSERT_EQ(in2, 0);
	unsigned short int out = nand1.out();
	ASSERT_EQ(0, out);
}

TEST(ORConstructorTest, test003) {

    // create an object
	OR or1(1);

	// check that the object is constructed correctly
	unsigned short int in1 = or1.in1();
	ASSERT_EQ(in1, 0);
	unsigned short int in2 = or1.in2();
	ASSERT_EQ(in2, 0);
	unsigned short int out = or1.out();
	ASSERT_EQ(0, out);
}

TEST(ORTruthTableTest, test004) {
    // create an object
	OR or1(1);

    const unsigned short int bits[2] = {0, 1};

    for (int idx = 0; idx < 2; idx++) {
    	for (int idx2 = 0; idx2 < 2; idx2++) {
    		or1.set_in1(bits[idx]); or1.set_in2(bits[idx2]);
    		ASSERT_EQ(bits[idx] | bits[idx2], or1.out() );
    	}
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
