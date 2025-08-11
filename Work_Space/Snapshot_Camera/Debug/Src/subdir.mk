################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/external_switch.c \
../Src/exti.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim.c \
../Src/uart.c 

OBJS += \
./Src/external_switch.o \
./Src/exti.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim.o \
./Src/uart.o 

C_DEPS += \
./Src/external_switch.d \
./Src/exti.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DSTM32F446xx -c -I../Inc -I"C:/Users/domin/Desktop/Embedded_Projects/ArduCam_Snapshot_Camera/F4_chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/domin/Desktop/Embedded_Projects/ArduCam_Snapshot_Camera/F4_chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

