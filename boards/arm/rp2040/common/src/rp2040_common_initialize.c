/****************************************************************************
 * boards/arm/rp2040/common/src/rp2040_common_initialize.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <debug.h>

#include <nuttx/board.h>
#include <arch/board/board.h>

#include "arm_internal.h"
#include "rp2040_gpio.h"
#include "rp2040_uniqueid.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rp2040_common_earlyinitialize
 *
 * Description:
 *  This is the early initialization common to all RP2040 boards.
 *  It configures the UART pins so the system console can be used.
 ****************************************************************************/

void rp2040_common_earlyinitialize(void)
{
  rp2040_gpio_initialize();

  /* Disable IE on GPIO 26-29 */

  clrbits_reg32(RP2040_PADS_BANK0_GPIO_IE, RP2040_PADS_BANK0_GPIO(26));
  clrbits_reg32(RP2040_PADS_BANK0_GPIO_IE, RP2040_PADS_BANK0_GPIO(27));
  clrbits_reg32(RP2040_PADS_BANK0_GPIO_IE, RP2040_PADS_BANK0_GPIO(28));
  clrbits_reg32(RP2040_PADS_BANK0_GPIO_IE, RP2040_PADS_BANK0_GPIO(29));

  /* Set default UART pin */

#ifdef CONFIG_RP2040_UART0
  rp2040_gpio_set_function(CONFIG_RP2040_UART0_TX_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* TX */
  rp2040_gpio_set_function(CONFIG_RP2040_UART0_RX_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* RX */
#ifdef CONFIG_SERIAL_OFLOWCONTROL
  rp2040_gpio_set_function(CONFIG_RP2040_UART0_CTS_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* CTS */
#endif
#ifdef CONFIG_SERIAL_IFLOWCONTROL
  rp2040_gpio_set_function(CONFIG_RP2040_UART0_RTS_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* RTS */
#endif
#endif

#ifdef CONFIG_RP2040_UART1
  rp2040_gpio_set_function(CONFIG_RP2040_UART1_TX_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* TX */
  rp2040_gpio_set_function(CONFIG_RP2040_UART1_RX_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* RX */
#ifdef CONFIG_SERIAL_OFLOWCONTROL
  rp2040_gpio_set_function(CONFIG_RP2040_UART1_CTS_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* CTS */
#endif
#ifdef CONFIG_SERIAL_IFLOWCONTROL
  rp2040_gpio_set_function(CONFIG_RP2040_UART1_RTS_GPIO,
                           RP2040_GPIO_FUNC_UART);      /* RTS */
#endif
#endif

#if defined(CONFIG_RP2040_CLK_GPOUT0)
  rp2040_gpio_set_function(RP2040_GPIO_PIN_CLK_GPOUT0,
                           RP2040_GPIO_FUNC_CLOCKS);
#endif
#if defined(CONFIG_RP2040_CLK_GPOUT1)
  rp2040_gpio_set_function(RP2040_GPIO_PIN_CLK_GPOUT1,
                           RP2040_GPIO_FUNC_CLOCKS);
#endif
#if defined(CONFIG_RP2040_CLK_GPOUT2)
  rp2040_gpio_set_function(RP2040_GPIO_PIN_CLK_GPOUT2,
                           RP2040_GPIO_FUNC_CLOCKS);
#endif
#if defined(CONFIG_RP2040_CLK_GPOUT3)
  rp2040_gpio_set_function(RP2040_GPIO_PIN_CLK_GPOUT3,
                           RP2040_GPIO_FUNC_CLOCKS);
#endif
}

/****************************************************************************
 * Name: rp2040_common_initialize
 *
 * Description:
 *  It configures the pin assignments that were not done in the early
 *  initialization.
 ****************************************************************************/

void rp2040_common_initialize(void)
{
#ifdef CONFIG_BOARDCTL_UNIQUEID
  rp2040_uniqueid_initialize();
#endif

  /* Set default I2C pin */

#ifdef CONFIG_RP2040_I2C0
  rp2040_gpio_set_function(CONFIG_RP2040_I2C0_SDA_GPIO,
                           RP2040_GPIO_FUNC_I2C);       /* SDA */
  rp2040_gpio_set_function(CONFIG_RP2040_I2C0_SCL_GPIO,
                           RP2040_GPIO_FUNC_I2C);       /* SCL */

  rp2040_gpio_set_pulls(CONFIG_RP2040_I2C0_SDA_GPIO, true, false);  /* Pull up */
  rp2040_gpio_set_pulls(CONFIG_RP2040_I2C0_SCL_GPIO, true, false);
#endif

#ifdef CONFIG_RP2040_I2C1
  rp2040_gpio_set_function(CONFIG_RP2040_I2C1_SDA_GPIO,
                           RP2040_GPIO_FUNC_I2C);       /* SDA */
  rp2040_gpio_set_function(CONFIG_RP2040_I2C1_SCL_GPIO,
                           RP2040_GPIO_FUNC_I2C);       /* SCL */

  rp2040_gpio_set_pulls(CONFIG_RP2040_I2C1_SDA_GPIO, true, false);  /* Pull up */
  rp2040_gpio_set_pulls(CONFIG_RP2040_I2C1_SCL_GPIO, true, false);
#endif

  /* Set default SPI pin */

#ifdef CONFIG_RP2040_SPI0
  rp2040_gpio_set_function(CONFIG_RP2040_SPI0_RX_GPIO,
                           RP2040_GPIO_FUNC_SPI);       /* RX */
  rp2040_gpio_set_function(CONFIG_RP2040_SPI0_SCK_GPIO,
                           RP2040_GPIO_FUNC_SPI);       /* SCK */
  rp2040_gpio_set_function(CONFIG_RP2040_SPI0_TX_GPIO,
                           RP2040_GPIO_FUNC_SPI);       /* TX */

  /* CSn is controlled by board-specific logic */

  rp2040_gpio_init(CONFIG_RP2040_SPI0_CS_GPIO);        /* CSn */
  rp2040_gpio_setdir(CONFIG_RP2040_SPI0_CS_GPIO, true);
  rp2040_gpio_put(CONFIG_RP2040_SPI0_CS_GPIO, true);
#endif

#ifdef CONFIG_RP2040_SPI1
  rp2040_gpio_set_function(CONFIG_RP2040_SPI1_RX_GPIO,
                           RP2040_GPIO_FUNC_SPI);       /* RX */
  rp2040_gpio_set_function(CONFIG_RP2040_SPI1_SCK_GPIO,
                           RP2040_GPIO_FUNC_SPI);       /* SCK */
  rp2040_gpio_set_function(CONFIG_RP2040_SPI1_TX_GPIO,
                           RP2040_GPIO_FUNC_SPI);       /* TX */

  /* CSn is controlled by board-specific logic */

  rp2040_gpio_init(CONFIG_RP2040_SPI1_CS_GPIO);        /* CSn */
  rp2040_gpio_setdir(CONFIG_RP2040_SPI1_CS_GPIO, true);
  rp2040_gpio_put(CONFIG_RP2040_SPI1_CS_GPIO, true);
#endif

#ifdef CONFIG_NET_W5500
  /* W5500 Reset output */

  rp2040_gpio_setdir(CONFIG_RP2040_W5500_RST_GPIO, true);
  rp2040_gpio_put(CONFIG_RP2040_W5500_RST_GPIO, false);
  rp2040_gpio_set_function(CONFIG_RP2040_W5500_RST_GPIO,
                           RP2040_GPIO_FUNC_SIO);

  /* W5500 Interrupt input */

  rp2040_gpio_init(CONFIG_RP2040_W5500_INT_GPIO);
#endif
}
