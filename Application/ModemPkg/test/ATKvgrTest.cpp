/*
 * ATKvgrTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "ATKvgr.h"
#include "ATCommand.h"

TEST(ATKvgrTest, ATKvgrUnitTest1)
{
    std::vector<std::string> parameter_list = {"6"};
    ATKvgr foo = ATKvgr(parameter_list);
    EXPECT_EQ("AT+KVGR?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KVGR=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+KVGR=6",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATKVGR, foo.GetCommandType());
}

TEST(ATKvgrTest, ATKvgrUnitTest2)
{
    std::vector<std::string> parameter_list = {"22"};
    ATKvgr foo = ATKvgr(parameter_list);
    EXPECT_EQ("AT+KVGR?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KVGR=?",foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKvgrTest, ATKvgrUnitTest3)
{
    std::vector<std::string> parameter_list = {"7"};
    ATKvgr foo = ATKvgr(parameter_list);
    EXPECT_EQ("AT+KVGR?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KVGR=?",foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKvgrTest, ATKvgrUnitTest4)
{
    std::vector<std::string> parameter_list = {"2"};
    ATKvgr foo = ATKvgr(parameter_list);
    std::vector<std::string> response_list = {"+KVGR","2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATKVGR, response_list);
    std::string response = "+KVGR: 2";
    ATResponse actual_response = foo.ParseCommand(response);
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}


