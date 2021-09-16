################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7_segment.c \
../Button.c \
../DIO.c \
../EXT_INT.c \
../buzzer.c \
../keypad.c \
../lcd.c \
../led.c \
../main.c 

OBJS += \
./7_segment.o \
./Button.o \
./DIO.o \
./EXT_INT.o \
./buzzer.o \
./keypad.o \
./lcd.o \
./led.o \
./main.o 

C_DEPS += \
./7_segment.d \
./Button.d \
./DIO.d \
./EXT_INT.d \
./buzzer.d \
./keypad.d \
./lcd.d \
./led.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


