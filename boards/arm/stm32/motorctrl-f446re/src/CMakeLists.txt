set(SRCS stm32_boot.c stm32_bringup.c)

if(CONFIG_BOARDCTL)
  list(APPEND SRCS stm32_appinit.c)
endif()

if(CONFIG_STM32_SPI)
  list(APPEND SRCS stm32_spi.c)
endif()

if(CONFIG_PWM AND CONFIG_STM32_TIM1_PWM)
  list(APPEND SRCS stm32_pwm.c)
endif()

if(CONFIG_ADC AND (CONFIG_STM32_ADC1 OR CONFIG_STM32_ADC2 OR CONFIG_STM32_ADC3))
  list(APPEND SRCS stm32_adc.c)
endif()

if(CONFIG_STM32_CAN_SOCKET)
  list(APPEND SRCS stm32_cansock.c)
endif()

target_sources(board PRIVATE ${SRCS})

set_property(GLOBAL PROPERTY LD_SCRIPT "${NUTTX_BOARD_DIR}/scripts/f446re.ld")
