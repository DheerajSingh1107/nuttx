/****************************************************************************
 * boards/arm/stm32/motorctrl-f446re/src/stm32_bringup.c
 *
 * SPDX-License-Identifier: Apache-2.0
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <syslog.h>

#include <nuttx/board.h>
#include <nuttx/spi/spi.h>

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

#if defined(CONFIG_STM32_SPI1) || defined(CONFIG_STM32_SPI2) || \
    defined(CONFIG_STM32_SPI3)
void stm32_spidev_initialize(void);
#endif

#if defined(CONFIG_PWM) && defined(CONFIG_STM32_TIM1_PWM)
int stm32_pwm_setup(void);
#endif

#if defined(CONFIG_ADC) && (defined(CONFIG_STM32_ADC1) || \
    defined(CONFIG_STM32_ADC2) || defined(CONFIG_STM32_ADC3))
int stm32_adc_setup(void);
#endif

#ifdef CONFIG_STM32_CAN_SOCKET
int stm32_cansock_setup(void);
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int stm32_bringup(void)
{
  int ret = OK;

#if defined(CONFIG_STM32_SPI1) || defined(CONFIG_STM32_SPI2) || \
    defined(CONFIG_STM32_SPI3)
  stm32_spidev_initialize();
#endif

#if defined(CONFIG_PWM) && defined(CONFIG_STM32_TIM1_PWM)
  ret = stm32_pwm_setup();
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: stm32_pwm_setup failed: %d\n", ret);
    }
#endif

#if defined(CONFIG_ADC) && (defined(CONFIG_STM32_ADC1) || \
    defined(CONFIG_STM32_ADC2) || defined(CONFIG_STM32_ADC3))
  ret = stm32_adc_setup();
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: stm32_adc_setup failed: %d\n", ret);
    }
#endif

#ifdef CONFIG_STM32_CAN_SOCKET
  ret = stm32_cansock_setup();
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: stm32_cansock_setup failed: %d\n", ret);
    }
#endif

  syslog(LOG_INFO, "motorctrl-f446re bringup done\n");
  return ret;
}
