/*
 * ATCgact.cpp
 *
 *  Created on: 26 Sep 2018
 *      Author: tunstall
 */


#include <iostream>
#include "gtest/gtest.h"
#include "ATCgact.h"
#include "ATCommand.h"

TEST(ATCgactTests, ATCgact_GenerateTest)
{
    //all functions should be good
    std::vector<std::string> parameter_list = {"1","0"};
    ATCgact foo = ATCgact(parameter_list);
    EXPECT_EQ("AT+CGACT?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+CGACT=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CGACT=1",foo.GenerateWriteCommand());
    EXPECT_EQ(60, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCGACT, foo.GetCommandType());
}


TEST(ATCgactTests, ATCgact_OutOfRange)
{
    //all functions should be good
    std::vector<std::string> parameter_list = {"4","0"};
    ATCgact foo = ATCgact(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCgactTests, ATCgact_NonInteger)
{
    //all functions should be good
    std::vector<std::string> parameter_list = {"EQ","2"};
    ATCgact foo = ATCgact(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo.GenerateWriteCommand());
}

TEST(ATCgactTests, ATCgact_ParseTest)
{
    std::vector<std::string> parameter_list = {"1","2"};

    ATCgact foo = ATCgact(parameter_list);
    std::vector<std::string> response_list = {"+CGACT","1","2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCGACT, response_list);
    std::string response = "+CGACT: 1,2";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}




