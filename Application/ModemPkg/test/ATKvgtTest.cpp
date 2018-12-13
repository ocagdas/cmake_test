/*
 * ATKvgtTest.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATKvgt.h"
#include "ATCommand.h"

TEST(ATKvgtTests, ATKvgtUnitTest1)
{
    std::vector<std::string> parameter_list = {"6"};
    ATKvgt foo = ATKvgt(parameter_list);
    EXPECT_EQ("AT+KVGT?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KVGT=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+KVGT=6",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATKVGT, foo.GetCommandType());
}

TEST(ATKvgtTests, ATKvgtUnitTest2)
{
    std::vector<std::string> parameter_list = {"22"};
    ATKvgt foo = ATKvgt(parameter_list);
    EXPECT_EQ("AT+KVGT?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KVGT=?",foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKvgtTests, ATKvgtUnitTest3)
{
    std::vector<std::string> parameter_list = {"7"};
    ATKvgt foo = ATKvgt(parameter_list);
    EXPECT_EQ("AT+KVGT?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KVGT=?",foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKvgtTests, ATKvgtUnitTest4)
{
    std::vector<std::string> parameter_list = {"2"};
    ATKvgt foo = ATKvgt(parameter_list);
    std::vector<std::string> response_list = {"+KVGT","2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATKVGT, response_list);
    std::string response = "+KVGT: 2";
    ATResponse actual_response = foo.ParseCommand(response);
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);

}


