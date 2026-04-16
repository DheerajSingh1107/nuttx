/****************************************************************************
 * boards/arm/stm32/motorctrl-f446re/src/stm32_spi.c
 *
 * SPDX-License-Identifier: Apache-2.0
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>

#include <debug.h>

#include <nuttx/spi/spi.h>
#if defined(CONFIG_SPI_DRIVER) && defined(CONFIG_SPI_EXCHANGE)
#  include <nuttx/spi/spi_transfer.h>
#endif
#include <arch/board/board.h>

#include "chip.h"
#include "stm32.h"

#if defined(CONFIG_STM32_SPI3)

/****************************************************************************
 * Public Data
 ****************************************************************************/

struct spi_dev_s *g_spi3;

/****************************************************************************
 * Public Functions
 ****************************************************************************/

void weak_function stm32_spidev_initialize(void)
{
  g_spi3 = stm32_spibus_initialize(3);
  if (!g_spi3)
    {
      spierr("ERROR: Failed to initialize SPI3\n");
      return;
    }

#ifdef GPIO_SPI3_CS_USER
  stm32_configgpio(GPIO_SPI3_CS_USER);
#endif

#if defined(CONFIG_SPI_DRIVER) && defined(CONFIG_SPI_EXCHANGE)
  {
    int ret = spi_register(g_spi3, 3);
    if (ret < 0)
      {
        spierr("ERROR: Failed to register /dev/spi3: %d\n", ret);
      }
  }
#endif
}

void stm32_spi3select(struct spi_dev_s *dev, uint32_t devid, bool selected)
{
  spiinfo("devid: %d CS: %s\n",
          (int)devid, selected ? "assert" : "de-assert");

#ifdef GPIO_SPI3_CS_USER
  if (devid == SPIDEV_USER(0))
    {
      stm32_gpiowrite(GPIO_SPI3_CS_USER, !selected);
    }
#endif
}

uint8_t stm32_spi3status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}

#ifdef CONFIG_SPI_CMDDATA
int stm32_spi3cmddata(struct spi_dev_s *dev, uint32_t devid, bool cmd)
{
  return OK;
}
#endif

#endif /* CONFIG_STM32_SPI3 */
