/*
 * Modem4GEUTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "Modem4GEU.h"

class Modem4GEUTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	Modem4GEU *foo = new Modem4GEU();
};

TEST_F(Modem4GEUTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(Modem4GEUTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
