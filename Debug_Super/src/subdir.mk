################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bM_04_main.cpp 

OBJS += \
./src/bM_04_main.o 

CPP_DEPS += \
./src/bM_04_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -UNDEBUG -O0 -g3 -ggdb -fsanitize=address -pedantic -Wall -Wextra -c -fmessage-length=0 -Weffc++ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


