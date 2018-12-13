/*
 * IModemTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "IModem.h"
#include "GenericModem.h"

class IModemTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	IModem *foo = new GenericModem();
};

TEST_F(IModemTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(IModemTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
