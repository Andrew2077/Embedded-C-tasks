################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/adc.c \
../Drivers/src/delay.c \
../Drivers/src/gpio.c \
../Drivers/src/lcd_4bit.c 

OBJS += \
./Drivers/src/adc.o \
./Drivers/src/delay.o \
./Drivers/src/gpio.o \
./Drivers/src/lcd_4bit.o 

C_DEPS += \
./Drivers/src/adc.d \
./Drivers/src/delay.d \
./Drivers/src/gpio.d \
./Drivers/src/lcd_4bit.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/HP/workspace/ADC/Drivers/include" -I"C:/Users/HP/workspace/ADC/inc" -I"C:/Users/HP/workspace/ADC/CMSIS/device" -I"C:/Users/HP/workspace/ADC/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


