/*
 * AllTests.cpp
 *
 *  Created on: Aug 29, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"

int main (int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

