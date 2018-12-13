#include <iostream>

#include "ModemPkgInternal.h"
#include "ModemContImpl.h"

IModemController::IModemController() {
	std::cout << "IModemContoller is born" << std::endl;
}

IModemController::~IModemController() {
	std::cout << "IModemContoller is dying" << std::endl;
}

IModemController* IModemController::Create(uint8_t typeId, uint8_t param1) {
	IModemController* createdInstance = nullptr;

	if (0 != typeId && 0 != param1) {
		createdInstance = new ModemContImpl();
	}

	return createdInstance;
}

