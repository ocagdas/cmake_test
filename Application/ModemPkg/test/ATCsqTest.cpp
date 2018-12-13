/*
 * ATCsqTest.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCsq.h"
#include "ATCommand.h"


TEST(ATCsqTests, ATCsq_ReadWriteTestSuccess)
{
	//all functions should be good
    std::vector<std::string> parameter_list;
    ATCsq foo = ATCsq(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND ,foo.GenerateReadCommand());
    EXPECT_EQ("AT+CSQ=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CSQ",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCSQ, foo.GetCommandType());
}

TEST(ATCsqTests, ATCsq_MissingAndBadCommand)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list = {"1"};
    ATCsq foo = ATCsq(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
    parameter_list = {"dd"};
    ATCsq foo2 = ATCsq(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo2.GenerateWriteCommand());
}

// Simple reporting
TEST(ATCsqTests, ATCsq_SimpleURCReporting)
{
    std::vector<std::string> parameter_list;

    ATCsq foo = ATCsq(parameter_list);
    std::vector<std::string> response_list = {"+CSQ", "9", "99"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCSQ, response_list);
    std::string response = "+CSQ: 9,99";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
    EXPECT_EQ(expected_response.GetResponseData()[2], actual_response.GetResponseData()[2]);
}


