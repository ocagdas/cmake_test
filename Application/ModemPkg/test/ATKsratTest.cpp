/*
 * ATKsrat.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATKsrat.h"
#include "ATCommand.h"

void GoodAndBadCommand(std::vector<std::string> validValues, ModemTypes modemType);

TEST(ATKsratTests, ATKsrat_AllPossibleValues)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"1"};
    ATKsrat foo = ATKsrat(parameter_list);
    EXPECT_EQ("AT+KSRAT?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KSRAT=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+KSRAT=1",foo.GenerateWriteCommand());
    for (int i = 1; i <= 9; i++)
    {
        std::vector<std::string> parameter_list = {std::to_string(i)};
        ATKsrat foo = ATKsrat(parameter_list);
        EXPECT_EQ("AT+KSRAT=" + std::to_string(i),foo.GenerateWriteCommand());
    }
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATKSRAT, foo.GetCommandType());
}

// Tests for the  different types of modem.
TEST(ATKsratTests, ATKsrat_RestrictedModemValues)
{
    GoodAndBadCommand({"2", "5", "6", "7"}, ModemTypes::HL7650);
    GoodAndBadCommand({"2", "5", "6", "7"}, ModemTypes::HL7688);
    GoodAndBadCommand({"1", "5", "8", "9"}, ModemTypes::HL7692);
    GoodAndBadCommand({"1", "2", "3", "4"}, ModemTypes::HL8548);
}

// Test all possible combinations.
void GoodAndBadCommand(std::vector<std::string> validValues, ModemTypes modemType)
{
    for (int i = 1; i<= 9; i++)
    {
        std::vector<std::string> parameter_list = {std::to_string(i)};
        ATKsrat foo = ATKsrat(parameter_list);
        foo.UpdatePossibleRadioTechnologies(modemType);
        // Search through the possible string values and see if it is a valid response.
        std::vector<std::string>::iterator it;
        it = find(validValues.begin(), validValues.end(), std::to_string(i));
        if (it != validValues.end())
        {
            EXPECT_EQ("AT+KSRAT=" + std::to_string(i), foo.GenerateWriteCommand());
        }
        else
        {
            EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
        }
    }
}

TEST(ATKsratTests, ATKsrat_InvalidValue)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"10"};
    ATKsrat foo = ATKsrat(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKsratTests, ATKsrat_MissingValue)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list;
    ATKsrat foo = ATKsrat(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKsratTests, ATKsrat_UnitTest4)
{
    std::vector<std::string> parameter_list = {"4"};

    ATKsrat foo = ATKsrat(parameter_list);
    std::vector<std::string> response_list = {"+KSRAT", "4"};
    ATResponse expected_response = ATResponse(ATResponseType::ATKSRAT, response_list);
    std::string response = "+KSRAT: 4";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

