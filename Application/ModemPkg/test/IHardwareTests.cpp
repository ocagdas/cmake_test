/*
 * IHardware.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "IHardware.h"
#include "SierraHardwareIO.h"

class IHardwarerTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	IHardware *foo = new SierraHardwareIO();
};

TEST_F(IHardwarerTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(IHardwarerTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
