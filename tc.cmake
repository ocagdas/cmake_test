#set(CMAKE_SYSTEM_NAME Linux)
#set(CMAKE_SYSTEM_PROCESSOR armv7ahf)
#set(CMAKE_SYSROOT /home/ocagdas/companies/tunstall/cmake_test/Platform/linux-devkit/sysroots/x86_64-arago-linux)
#set(CMAKE_STAGING_PREFIX /home/ocagdas/stage)
#set(CMAKE_FIND_ROOT_PATH "/home/ocagdas/companies/tunstall/cmake_test/Platform/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi")
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#set(CMAKE_SYSTEM_PREFIX_PATH ${CMAKE_FIND_ROOT_PATH}/usr/lib)
#set(CMAKE_C_COMPILER ${CMAKE_SYSROOT}/usr/bin/arm-linux-gnueabihf-gcc)
#set(CMAKE_CXX_COMPILER ${CMAKE_SYSROOT}/usr/bin/arm-linux-gnueabihf-g++)
#set(CMAKE_ASM_COMPILER ${CMAKE_SYSROOT}/usr/bin/arm-linux-gnueabihf-gcc)
#set(MAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)

#set(CMAKE_SYSROOT /opt/ti-processor-sdk-linux-am335x-evm-03.01.00.06/linux-devkitt/sysroots/x86_64-arago-linux)
set(CMAKE_FIND_ROOT_PATH Platform/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi)

set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#find_program(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

