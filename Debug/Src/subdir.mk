################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/audio.c \
../Src/display.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/ws2811.c 

OBJS += \
./Src/audio.o \
./Src/display.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/ws2811.o 

C_DEPS += \
./Src/audio.d \
./Src/display.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/ws2811.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"E:/Programy/STMicroelectronics/STM32Cube/Projects/SmartDoor/Inc" -I"E:/Programy/STMicroelectronics/STM32Cube/Projects/SmartDoor/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/Programy/STMicroelectronics/STM32Cube/Projects/SmartDoor/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"E:/Programy/STMicroelectronics/STM32Cube/Projects/SmartDoor/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/Programy/STMicroelectronics/STM32Cube/Projects/SmartDoor/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


