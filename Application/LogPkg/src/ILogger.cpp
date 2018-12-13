#include <iostream>

#include "LogPkgInternal.h"
#include "LoggerImpl.h"

ILogger::ILogger() {
	std::cout << "ILogger is born" << std::endl;
}

ILogger::~ILogger() {
	std::cout << "ILogger is dying" << std::endl;
}

ILogger* ILogger::Create(uint8_t typeId) {
	ILogger* createdInstance = nullptr;

	if (0 != typeId) {
		createdInstance = new LoggerImpl();
	}

	return createdInstance;
}

bool ILogger::LoggerContractFunc(uint8_t var1, uint8_t var2) {
	return (var1 == var2);
}

