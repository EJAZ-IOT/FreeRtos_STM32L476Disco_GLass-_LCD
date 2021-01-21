################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Src/stm32l476g_discovery_glass_lcd.c 

OBJS += \
./Drivers/BSP/Src/stm32l476g_discovery_glass_lcd.o 

C_DEPS += \
./Drivers/BSP/Src/stm32l476g_discovery_glass_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Src/stm32l476g_discovery_glass_lcd.o: ../Drivers/BSP/Src/stm32l476g_discovery_glass_lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"C:/Users/Gauti/STM32CubeIDE/workspace_1.5.1/INOCHI_TASK01/Drivers/BSP/Src" -I"C:/Users/Gauti/STM32CubeIDE/workspace_1.5.1/INOCHI_TASK01/Drivers/BSP/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Src/stm32l476g_discovery_glass_lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

