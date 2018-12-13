#if !defined(_COMMON_STARTUP_H_)
#define _COMMON_STARTUP_H_

#include <iostream>

#include "LogPkg/LogPkgApi.h"
#include "ModemPkg/ModemPkgApi.h"
#include "ThreadingPkg/ThreadingPkgApi.h"

namespace toyproj {
	void CommonStartup(const std::string& startupMsg) {
		logpkg::ILogger* logInst = logpkg::ILogger::Create(1);
		modempkg::IModemController* modemContInst = modempkg::IModemController::Create(1, 1);
		
		threadingpkg::DummyThreadingFunc();

		if (logInst) {
			logInst->LogMessage(startupMsg);

			delete logInst;
		}

		if (modemContInst) {
			delete modemContInst;
		}
	};
}

#endif //_COMMON_STARTUP_H_
