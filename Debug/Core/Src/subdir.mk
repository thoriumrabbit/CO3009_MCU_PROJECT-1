################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/fsm_automatic.c \
../Core/Src/fsm_change.c \
../Core/Src/fsm_manual.c \
../Core/Src/fsm_pedestrian.c \
../Core/Src/global.c \
../Core/Src/led_segment_control.c \
../Core/Src/main.c \
../Core/Src/melody.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/fsm_automatic.o \
./Core/Src/fsm_change.o \
./Core/Src/fsm_manual.o \
./Core/Src/fsm_pedestrian.o \
./Core/Src/global.o \
./Core/Src/led_segment_control.o \
./Core/Src/main.o \
./Core/Src/melody.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/fsm_automatic.d \
./Core/Src/fsm_change.d \
./Core/Src/fsm_manual.d \
./Core/Src/fsm_pedestrian.d \
./Core/Src/global.d \
./Core/Src/led_segment_control.d \
./Core/Src/main.d \
./Core/Src/melody.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/fsm_automatic.d ./Core/Src/fsm_automatic.o ./Core/Src/fsm_automatic.su ./Core/Src/fsm_change.d ./Core/Src/fsm_change.o ./Core/Src/fsm_change.su ./Core/Src/fsm_manual.d ./Core/Src/fsm_manual.o ./Core/Src/fsm_manual.su ./Core/Src/fsm_pedestrian.d ./Core/Src/fsm_pedestrian.o ./Core/Src/fsm_pedestrian.su ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/led_segment_control.d ./Core/Src/led_segment_control.o ./Core/Src/led_segment_control.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/melody.d ./Core/Src/melody.o ./Core/Src/melody.su ./Core/Src/software_timer.d ./Core/Src/software_timer.o ./Core/Src/software_timer.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

