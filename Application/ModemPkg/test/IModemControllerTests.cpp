/*
 * IModemControllerTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "IModemController.h"
#include "ModemController.h"

class IModemControllerTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	IModemController *foo = new ModemController();
};

TEST_F(IModemControllerTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(IModemControllerTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
