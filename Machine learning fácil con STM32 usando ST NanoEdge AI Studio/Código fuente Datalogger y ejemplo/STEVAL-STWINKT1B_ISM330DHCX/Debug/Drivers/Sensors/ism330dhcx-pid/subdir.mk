################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.c 

OBJS += \
./Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.o 

C_DEPS += \
./Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.o: C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.c Drivers/Sensors/ism330dhcx-pid/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../Core/Inc -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/CMSIS/Core/Include" -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/Sensors/ism330dhcx-pid" -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/STM32CubeL4/cmsis_device_l4/Include" -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/STM32CubeL4/stm32l4xx_hal_driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Sensors-2f-ism330dhcx-2d-pid

clean-Drivers-2f-Sensors-2f-ism330dhcx-2d-pid:
	-$(RM) ./Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.cyclo ./Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.d ./Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.o ./Drivers/Sensors/ism330dhcx-pid/ism330dhcx_reg.su

.PHONY: clean-Drivers-2f-Sensors-2f-ism330dhcx-2d-pid

