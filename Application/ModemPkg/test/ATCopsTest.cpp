/*
 * ATCmeeTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCops.h"
#include "ATCommand.h"


TEST(ATCopsTests, ATCops_UnitTest1)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"2"};
    ATCops foo = ATCops(parameter_list);
    EXPECT_EQ("AT+COPS?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+COPS=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+COPS=2",foo.GenerateWriteCommand());
    EXPECT_EQ(120, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCOPS, foo.GetCommandType());
}

TEST(ATCopsTests, ATCops_UnitTest2)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"1"};
    ATCops foo = ATCops(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCopsTests, ATCops_UnitTest3)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list = {"dd"};
    ATCops foo = ATCops(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo.GenerateWriteCommand());
}

// Successful disconnection message.
TEST(ATCopsTests, ATCops_UnitTest4)
{
    std::vector<std::string> parameter_list = {"2"};

    ATCops foo = ATCops(parameter_list);
    std::vector<std::string> response_list = {"+COPS","2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCOPS, response_list);
    std::string response = "+COPS: 2";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

// Successful connection message.
TEST(ATCopsTests, ATCops_UnitTest5)
{
    std::vector<std::string> parameter_list = {"0"};

    ATCops foo = ATCops(parameter_list);
    std::vector<std::string> response_list = {"+COPS", "0", "0","3 UK", "2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCOPS, response_list);
    std::string response = "+COPS: 0,0,\"3 UK\",2";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
    EXPECT_EQ(expected_response.GetResponseData()[2], actual_response.GetResponseData()[2]);
    EXPECT_EQ(expected_response.GetResponseData()[3], actual_response.GetResponseData()[3]);
    EXPECT_EQ(expected_response.GetResponseData()[4], actual_response.GetResponseData()[4]);
}

