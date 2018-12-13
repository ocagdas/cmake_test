/*
 * ATCmeeTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATIpr.h"
#include "ATCommand.h"


TEST(ATIprTests, ATIpr_UnitTest1)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"921600"};
    ATIpr foo = ATIpr(parameter_list);
    EXPECT_EQ("AT+IPR?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+IPR=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+IPR=921600",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATIPR, foo.GetCommandType());
}

TEST(ATIprTests, ATIpr_UnitTest2)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"3"};
    ATIpr foo = ATIpr(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATIprTests, ATIpr_UnitTest3)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list = {"dd"};
    ATIpr foo = ATIpr(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATIprTests, ATIpr_UnitTest4)
{
    std::vector<std::string> parameter_list = {"921600"};

    ATIpr foo = ATIpr(parameter_list);
    std::vector<std::string> response_list = {"+IPR","921600"};
    ATResponse expected_response = ATResponse(ATResponseType::ATIPR, response_list);
    std::string response = "+IPR: 921600";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

