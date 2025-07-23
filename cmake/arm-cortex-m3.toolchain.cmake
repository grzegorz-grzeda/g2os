# stm32.toolchain - CMake toolchain file for ARM GCC (arm-none-eabi)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify the cross compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy CACHE INTERNAL "")
set(CMAKE_SIZE_UTIL arm-none-eabi-size CACHE INTERNAL "")

# Set compiler flags (adjust as needed for your STM32 device)
set(CMAKE_C_FLAGS "-mcpu=cortex-m3 -mthumb -Wall")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-m3 -mthumb -Wall")
set(CMAKE_ASM_FLAGS "-mcpu=cortex-m3 -mthumb")

# Optionally set linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m3 -mthumb -specs=nosys.specs")

# Optionally set the path to the toolchain if not in PATH
# set(CMAKE_FIND_ROOT_PATH /path/to/arm-none-eabi)

# Prevent CMake from searching for programs on the host system
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)