#include <iostream>

#include "ModemPkgInternal.h"
#include "ModemContImpl.h"

ModemContImpl::ModemContImpl() {
	loggerInst = logpkg::ILogger::Create(1);
	loggerInst->LogMessage("ModemContImpl is born");
}

ModemContImpl::~ModemContImpl() {
	loggerInst->LogMessage("ModemContImpl is dying");
	delete loggerInst;
}

bool ModemContImpl::ExecuteModemContractFunc(uint8_t var1, uint8_t var2) {
	return (var1 == var2);
}

