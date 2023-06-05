################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.c 

OBJS += \
./Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.o 

C_DEPS += \
./Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.o: C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.c Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../Core/Inc -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/CMSIS/Core/Include" -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/Sensors/ism330dhcx-pid" -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/STM32CubeL4/cmsis_device_l4/Include" -I"C:/Users/Biblioman09/STM32CubeIDE/workspace_1.12.1/stm32ai-nanoedge-datalogger/Drivers/STM32CubeL4/stm32l4xx_hal_driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32CubeL4-2f-stm32l4xx_hal_driver-2f-Src-2f-Legacy

clean-Drivers-2f-STM32CubeL4-2f-stm32l4xx_hal_driver-2f-Src-2f-Legacy:
	-$(RM) ./Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.cyclo ./Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.d ./Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.o ./Drivers/STM32CubeL4/stm32l4xx_hal_driver/Src/Legacy/stm32l4xx_hal_can.su

.PHONY: clean-Drivers-2f-STM32CubeL4-2f-stm32l4xx_hal_driver-2f-Src-2f-Legacy

