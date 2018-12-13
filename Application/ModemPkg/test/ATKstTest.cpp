/*
 * ATKstTest.cpp
 *
 *  Created on: 18 Sep 2018
 *      Author: tunstall
 */


#include <iostream>
#include "gtest/gtest.h"
#include "ATKst.h"
#include "ATCommand.h"

TEST (ATKsttests,ATKstTestValidParam)
{
    std::vector<std::string> parameter_list = {"6"};
    ATKst foo = ATKst(parameter_list);
    EXPECT_EQ("AT+KST?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KST=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+KST=6",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATKST, foo.GetCommandType());
}

TEST (ATKsttests,ATKstTestInvalidParam) //parameter too large test
{
    std::vector<std::string> parameter_list = {"21"};
    ATKst foo = ATKst(parameter_list);
    EXPECT_EQ("AT+KST?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KST=?",foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST (ATKsttests,ATKstTestEmptyParam) //empty parameter list
{
    std::vector<std::string> parameter_list = {};
    ATKst foo = ATKst(parameter_list);
    EXPECT_EQ("AT+KST?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KST=?",foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

