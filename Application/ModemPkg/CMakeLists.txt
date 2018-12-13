set(PkgName ModemPkg)

include(../common.cmake)
include_directories(../IPULogPkg/inc)

# It is recommended that GLOB is not used to pass source files to the
# add_execuitable function. Thes cpp files sould be added as required
set( ${pkg_src_list} 
		src/SierraReader.cpp 
		src/IReader.cpp
		src/SierraWriter.cpp 
		src/IWriter.cpp
		src/SierraHardwareIO.cpp 
		src/IHardware.cpp 
		src/CellularManager.cpp
		src/ICellularManager.cpp 
		src/ModemController.cpp
		src/IModemController.cpp
		src/GenericModem.cpp
		src/IModem.cpp
		src/Modem4GEU.cpp
		src/Modem3GEU.cpp
		src/ATCommandProcessor.cpp
		src/ATCommand.cpp
		src/ATResponse.cpp 
		src/ATKvgr.cpp
		src/ATKvgt.cpp
		src/ATKst.cpp
		src/ATCmee.cpp 
		src/ATE.cpp
		src/ATIpr.cpp
		src/ATCpin.cpp
		src/ATCrc.cpp
		src/ATXcallstat.cpp
		src/ATCodecinfo.cpp
		src/ATCtzu.cpp
		src/ATWextclk.cpp
		src/ATKpcmcfg.cpp
		src/ATKsrat.cpp
		src/ATCops.cpp
		src/ATCreg.cpp
		src/ATCgreg.cpp
		src/ATCsq.cpp
		src/ATCgdcont.cpp
		src/ATCgdaddr.cpp
		src/ATD.cpp
		src/ATWvr.cpp
		src/ATH.cpp
		src/ATKnetscan.cpp
		src/ATKcell.cpp
		src/ATCpof.cpp
		src/ATKsrep.cpp
		src/ATCcwa.cpp
		src/ATKgpio.cpp
		src/ATA.cpp
		src/ATKsleep.cpp
		src/ATKecho.cpp
		src/ATKnoise.cpp
		src/ATCgact.cpp
		src/ATCsca.cpp
		src/ATCcip.cpp
		src/ATCpas.cpp
		src/PBReady.cpp
		src/ATWdsi.cpp
		src/ATWdss.cpp
		src/ATCgmi.cpp
		src/ATCgmm.cpp
		src/ATCgmr.cpp
		src/ATCgsn.cpp
		src/ATKgsn.cpp )
	
set( ${pkg_test_src_list} 
		test/AllTests.cpp 
		test/IReaderTests.cpp 
		test/IWriterTests.cpp
		test/IHardwareTests.cpp 
		test/ICellularManagerTests.cpp 
		test/IModemControllerTests.cpp
		test/IModemTests.cpp
		test/Modem4GEUTests.cpp
		test/Modem3GEUTests.cpp
		test/ATCommandProcessorTests.cpp
		test/ATCommandTests.cpp
		test/ATKvgrTest.cpp
		test/ATKvgtTest.cpp
		test/ATKstTest.cpp
		test/ATCmeeTest.cpp
		test/ATIprTest.cpp
		test/ATCpinTest.cpp
		test/ATKsleepTest.cpp
		test/ATHTest.cpp
		test/ATCopsTest.cpp
		test/ATCregTest.cpp
		test/ATCgregTest.cpp
		test/ATDTest.cpp
		test/ATATest.cpp
		test/ATETest.cpp
		test/ATCrcTest.cpp
		test/ATCsqTest.cpp
		test/ATKsratTest.cpp
		test/ATCgact.cpp )

set ( ${pkg_external_dependencies} 
		IPULogPkg 
		OSUtilitiesPkg)

include(../test_bin.cmake)

