/****************************************************************************
 * boards/arm/stm32/motorctrl-f446re/src/stm32_pwm.c
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

#include <nuttx/timers/pwm.h>

#include <arch/board/board.h>

#include "stm32.h"
#include "stm32_pwm.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int stm32_pwm_setup(void)
{
#if defined(CONFIG_PWM) && defined(CONFIG_STM32_TIM1_PWM)
  struct pwm_lowerhalf_s *pwm;
  int ret;

#ifdef GPIO_TIM1_ENABLE
  /* Assert gate-driver enable so TIM1 outputs are propagated. */

  stm32_configgpio(GPIO_TIM1_ENABLE);
  stm32_gpiowrite(GPIO_TIM1_ENABLE, true);
#endif

  pwm = stm32_pwminitialize(1);
  if (pwm == NULL)
    {
      pwmerr("ERROR: stm32_pwminitialize(1) failed\n");
      return -ENODEV;
    }

  ret = pwm_register("/dev/pwm0", pwm);
  if (ret < 0)
    {
      pwmerr("ERROR: pwm_register(/dev/pwm0) failed: %d\n", ret);
      return ret;
    }

  return OK;
#else
  return -ENODEV;
#endif
}
