/*
 * Modem3GEUTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "Modem3GEU.h"

class Modem3GEUTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	Modem3GEU foo;
};

TEST_F(Modem3GEUTests, UnitTest1)
{
	ASSERT_TRUE(foo.foo());
}

TEST_F(Modem3GEUTests, UnitTest2)
{
	EXPECT_EQ(true, foo.foo());
}
