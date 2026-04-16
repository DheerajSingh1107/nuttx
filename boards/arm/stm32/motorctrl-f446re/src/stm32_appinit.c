/****************************************************************************
 * boards/arm/stm32/motorctrl-f446re/src/stm32_appinit.c
 *
 * SPDX-License-Identifier: Apache-2.0
 ****************************************************************************/

#include <nuttx/config.h>

#include <nuttx/board.h>

int stm32_bringup(void);

int board_app_initialize(uintptr_t arg)
{
  UNUSED(arg);

#ifdef CONFIG_BOARD_LATE_INITIALIZE
  /* Board initialization already performed by board_late_initialize(). */

  return 0;
#else
  return stm32_bringup();
#endif
}
