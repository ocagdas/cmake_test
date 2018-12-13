/*
 * ATCgregTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCgreg.h"
#include "ATCommand.h"


TEST(ATCgregTests, ATCgreg_ReadWriteTestSuccess)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"2"};
    ATCgreg foo = ATCgreg(parameter_list);
    EXPECT_EQ("AT+CGREG?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+CGREG=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CGREG=2",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCGREG, foo.GetCommandType());
}

TEST(ATCgregTests, ATCgreg_ParameterOutOfRange)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"3"};
    ATCgreg foo = ATCgreg(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCgregTests, ATCgreg_MissingAndBadCommand)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list;
    ATCgreg foo = ATCgreg(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
    parameter_list = {"dd"};
    ATCgreg foo2 = ATCgreg(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo2.GenerateWriteCommand());
}

// Simple URC reporting
TEST(ATCgregTests, ATCgreg_SimpleURCReporting)
{
    std::vector<std::string> parameter_list = {"1"};

    ATCgreg foo = ATCgreg(parameter_list);
    std::vector<std::string> response_list = {"+CGREG", "2", "0"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCGREG, response_list);
    std::string response = "+CGREG: 2,0";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

// Successful connection message.
TEST(ATCgregTests, ATCgreg_LongURCReporting)
{
    std::vector<std::string> parameter_list = {"2"};

    ATCgreg foo = ATCgreg(parameter_list);
    std::vector<std::string> response_list = {"+CGREG", "5", "0065", "00960BA1", "6", "65"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCGREG, response_list);
    std::string response = "+CGREG: 5,\"0065\",\"00960BA1\",6,\"65\"";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
    EXPECT_EQ(expected_response.GetResponseData()[2], actual_response.GetResponseData()[2]);
    EXPECT_EQ(expected_response.GetResponseData()[3], actual_response.GetResponseData()[3]);
    EXPECT_EQ(expected_response.GetResponseData()[4], actual_response.GetResponseData()[4]);
    EXPECT_EQ(expected_response.GetResponseData()[5], actual_response.GetResponseData()[5]);
}

