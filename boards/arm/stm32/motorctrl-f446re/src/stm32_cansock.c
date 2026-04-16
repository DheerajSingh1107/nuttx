/****************************************************************************
 * boards/arm/stm32/motorctrl-f446re/src/stm32_cansock.c
 *
 * SPDX-License-Identifier: Apache-2.0
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <debug.h>

#include "stm32_can.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#if !defined(CONFIG_STM32_CAN1) && !defined(CONFIG_STM32_CAN2)
#  error "No CAN is enable. Please enable at least one CAN device"
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int stm32_cansock_setup(void)
{
  int ret = OK;

  UNUSED(ret);

#ifdef CONFIG_STM32_CAN1
  ret = stm32_cansockinitialize(1);
  if (ret < 0)
    {
      canerr("ERROR: Failed to initialize CAN socket 1: %d\n", ret);
      goto errout;
    }
#endif

#ifdef CONFIG_STM32_CAN2
  ret = stm32_cansockinitialize(2);
  if (ret < 0)
    {
      canerr("ERROR: Failed to initialize CAN socket 2: %d\n", ret);
      goto errout;
    }
#endif

errout:
  return ret;
}
