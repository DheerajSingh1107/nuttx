/****************************************************************************
 * boards/arm/stm32/motorctrl-f446re/src/stm32_adc.c
 *
 * SPDX-License-Identifier: Apache-2.0
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <errno.h>
#include <stdbool.h>

#include <debug.h>

#include <nuttx/analog/adc.h>
#include "stm32_adc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_ADC

#ifdef CONFIG_STM32_ADC1
#  define ADC1_NCHANNELS 1
static const uint8_t g_adc1_chanlist[ADC1_NCHANNELS] =
{
  10 /* PC0 */
};

static const uint32_t g_adc1_pinlist[ADC1_NCHANNELS] =
{
  GPIO_ADC1_IN10
};
#endif

#ifdef CONFIG_STM32_ADC2
#  define ADC2_NCHANNELS 1
static const uint8_t g_adc2_chanlist[ADC2_NCHANNELS] =
{
  5 /* PA5 */
};

static const uint32_t g_adc2_pinlist[ADC2_NCHANNELS] =
{
  GPIO_ADC2_IN5
};
#endif

#ifdef CONFIG_STM32_ADC3
#  define ADC3_NCHANNELS 1
static const uint8_t g_adc3_chanlist[ADC3_NCHANNELS] =
{
  12 /* PC2 */
};

static const uint32_t g_adc3_pinlist[ADC3_NCHANNELS] =
{
  GPIO_ADC3_IN12
};
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int stm32_adc_setup(void)
{
  static bool initialized = false;
  struct adc_dev_s *adc;
  int ret;
  int i;

  if (initialized)
    {
      return OK;
    }

#ifdef CONFIG_STM32_ADC1
  for (i = 0; i < ADC1_NCHANNELS; i++)
    {
      stm32_configgpio(g_adc1_pinlist[i]);
    }

  adc = stm32_adcinitialize(1, g_adc1_chanlist, ADC1_NCHANNELS);
  if (adc == NULL)
    {
      aerr("ERROR: Failed to get ADC1 interface\n");
      return -ENODEV;
    }

  ret = adc_register("/dev/adc0", adc);
  if (ret < 0)
    {
      aerr("ERROR: adc_register /dev/adc0 failed: %d\n", ret);
      return ret;
    }
#endif

#ifdef CONFIG_STM32_ADC2
  for (i = 0; i < ADC2_NCHANNELS; i++)
    {
      stm32_configgpio(g_adc2_pinlist[i]);
    }

  adc = stm32_adcinitialize(2, g_adc2_chanlist, ADC2_NCHANNELS);
  if (adc == NULL)
    {
      aerr("ERROR: Failed to get ADC2 interface\n");
      return -ENODEV;
    }

  ret = adc_register("/dev/adc1", adc);
  if (ret < 0)
    {
      aerr("ERROR: adc_register /dev/adc1 failed: %d\n", ret);
      return ret;
    }
#endif

#ifdef CONFIG_STM32_ADC3
  for (i = 0; i < ADC3_NCHANNELS; i++)
    {
      stm32_configgpio(g_adc3_pinlist[i]);
    }

  adc = stm32_adcinitialize(3, g_adc3_chanlist, ADC3_NCHANNELS);
  if (adc == NULL)
    {
      aerr("ERROR: Failed to get ADC3 interface\n");
      return -ENODEV;
    }

  ret = adc_register("/dev/adc2", adc);
  if (ret < 0)
    {
      aerr("ERROR: adc_register /dev/adc2 failed: %d\n", ret);
      return ret;
    }
#endif

  initialized = true;
  return OK;
}

#endif /* CONFIG_ADC */
