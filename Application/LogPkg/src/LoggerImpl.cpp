#include <iostream>

#include "LogPkgInternal.h"
#include "LoggerImpl.h"

LoggerImpl::LoggerImpl() {
	LogMessage("LoggerImpl is born");
}

LoggerImpl::~LoggerImpl() {
	LogMessage("LoggerImpl is dying");
}

bool LoggerImpl::LoggerContractFunc(uint8_t var1, uint8_t var2) {
	return (var1 == var2);
}

void LoggerImpl::LogMessage(const std::string& message) {
	std::cout << __FUNCTION__ << " : " << message.c_str() << std::endl;
}

