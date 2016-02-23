################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/C\ Assignment\ 8A.c 

OBJS += \
./src/C\ Assignment\ 8A.o 

C_DEPS += \
./src/C\ Assignment\ 8A.d 


# Each subdirectory must supply rules for building sources it contributes
src/C\ Assignment\ 8A.o: ../src/C\ Assignment\ 8A.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/C Assignment 8A.d" -MT"src/C\ Assignment\ 8A.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


