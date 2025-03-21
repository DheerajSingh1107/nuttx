/****************************************************************************
 * arch/arm/src/cxd56xx/cxd56_powermgr.h
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

#ifndef __ARCH_ARM_SRC_CXD56XX_POWERMGR_H
#define __ARCH_ARM_SRC_CXD56XX_POWERMGR_H

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define CXD56_PM_SET_CPUID(wrd0, cpuid) ((((cpuid) & 0xF) << 28) |\
                                          ((wrd0) & 0x0FFFFFFF))
#define CXD56_PM_SET_PROTO(msg, proto)    ((((proto) & 0xF) << 24) |\
                                            ((msg) & 0xF0FFFFFF))

#define CXD56_PM_FIFO_PROTO_PM  (10)

#define CXD56_PM_FIFO_MSG_ID_BOOT_INDE     (0)
#define CXD56_PM_FIFO_MSG_ID_FREQLOCK      (1)
#define CXD56_PM_FIFO_MSG_ID_CLK_CHG_START (2)
#define CXD56_PM_FIFO_MSG_ID_CLK_CHG_END   (3)
#define CXD56_PM_FIFO_MSG_ID_GET_CLK       (4)
#define CXD56_PM_FIFO_MSG_ID_HOT_SLEEP     (5)
#define CXD56_PM_FIFO_MSG_ID_RESUME        (6)

#define CXD56_PM_SYS_CPU  (0)
#define CXD56_PM_SYS_APP  (2)

#define CXD56_PM_TASK_PRIO (200)
#define CXD56_PM_TASK_STACKSIZE (1024)
#define CXD56_PM_MESSAGE_PRIO (1)

#define CXD56_PM_INTERNAL_MGS_CLK_CHG_START (0)
#define CXD56_PM_INTERNAL_MGS_CLK_CHG_END   (1)
#define CXD56_PM_INTERNAL_MGS_HOT_SLEEP     (2)

#define CXD56_PM_CALLBACK_ID_CLK_CHG_START (0)
#define CXD56_PM_CALLBACK_ID_CLK_CHG_END   (1)
#define CXD56_PM_CALLBACK_ID_HOT_SLEEP     (2)
#define CXD56_PM_CALLBACK_ID_HOT_BOOT      (3)

#define PM_CPUFREQLOCK_FLAG_INITIALIZED (0x8000)

/* Data corresponding to a clock tree */

/* Power DOMAIN */

#define PM_DOMAIN_SELF_CPU              (0x00000000ul)
#define PM_DOMAIN_SYSIOP                (0x20000000ul)
#define PM_DOMAIN_HOSTIF                (0x40000000ul)
#define PM_DOMAIN_PMU                   (0x60000000ul)
#define PM_DOMAIN_SCU                   (0x80000000ul)
#define PM_DOMAIN_APP                   (0xA0000000ul)
#define PM_DOMAIN_GPS                   (0xC0000000ul)
#define PM_DOMAIN_MASK                  (0xE0000000ul)
#define PM_DOMAIN_PLUS                  (0x20000000ul)

/* Clock Tree Bit Data */

/* SYSIOP */

#define PM_CLOCK_SYS_CTRL_SEL_B         (0x00010000ul) /* 16: */
#define PM_CLOCK_SYSPLL_DIV_B           (0x00008000ul) /* 15: CKSEL_ROOT.SWCTL_CLK_SEL_RFPLL1 */
#define PM_CLOCK_SYS_CPU_SEL_B          (0x00002000ul) /* 13:CKSEL_ROOT.SWCTL_CLK_SEL */
#define PM_CLOCK_SYS_CPU_DIV_B          (0x00001000ul) /* 12:CKDIV_CPU_DSP_BUS.CK_M0 */
#define PM_CLOCK_SYS_AHB_DIV_B          (0x00000800ul) /* 11:CKDIV_CPU_DSP_BUS.CK_AHB */
#define PM_CLOCK_SYS_APB_DIV_B          (0x00000400ul) /* 10:CKDIV_CPU_DSP_BUS.CK_APB */
#define PM_CLOCK_SYS_COMIF_DIV_B        (0x00000200ul) /* 9;CKDIV_COM.CK_COM */
#define PM_CLOCK_SYS_UART1_SEL_B        (0x00000100ul) /* 8:CKSEL_SYSIOP_SUB.SEL_UART1 */
#define PM_CLOCK_SYS_SFC_DIV_B          (0x00000080ul) /* 7:CKDIV_CPU_DSP_BUS.SFC_HCLK_LOW */
#define PM_CLOCK_PMU_RTC_PCLK_SEL_B     (0x00000040ul) /* 6:CKSEL_PMU.SEL_RTC_PCLK */

/* HOSTIF */

#define PM_CLOCK_HIF_SEL_B              (0x00000040ul) /* CKSEL_SYSIOP.SEL_HOST */
#define PM_CLOCK_HIF_DIV_B              (0x00000020ul) /* CKDIV_HOSTIFC.CK_HOSTIFC */
#define PM_CLOCK_HIF_SEL2_B             (0x00000004ul) /* CKSEL_SYSIOP.SEL_HOST2 */
#define PM_CLOCK_HIF_UART0_SEL_B        (0x00000002ul) /* CKSEL_SYSIOP.SEL_UART0 */
#define PM_CLOCK_HIF_I2C_SEL_B          (0x00000001ul) /* CKSEL_SYSIOP.SEL_I2CS */

/* SCU */

#define PM_CLOCK_SCU_XOSC_DIV_B         (0x00000010ul) /* CKSEL_SCU.SEL_SCU_XTAL */
#define PM_CLOCK_SCU_SEL_B              (0x00000004ul) /* CKSEL_SCU.SEL_SCU */
#define PM_CLOCK_SCU_32K_SEL_B          (0x00000008ul) /* CKSEL_SCU.SEL_SCU_32K */
#define PM_CLOCK_SCU_HPADC_SEL_B        (0x00000002ul) /* CKDIV_SCU.SCU_U32KH */
#define PM_CLOCK_SCU_LPADC_DIV_B        (0x00000001ul) /* CKDIV_SCU.SCU_U32KL */

/* APP */

#define PM_CLOCK_APP_SYSPLL_DIV_B       (0x00004000ul) /* APP_CKSEL.SWCTL_CLK_SEL_SP */
#define PM_CLOCK_APP_CPU_SEL_B          (0x00000400ul) /* APP_CKSEL.SWCTL_CLK_SEL */
#define PM_CLOCK_APP_AUD_MCLK_DIV_B     (0x00000200ul) /* APP_DIV.AU_MCLK */
#define PM_CLOCK_APP_AUD_MCLK_SEL_B     (0x00000100ul) /* APP_CKSEL.AU_MCLK */
#define PM_CLOCK_APP_AHB_GEAR_B         (0x00000080ul) /* GEAR_AHB */
#define PM_CLOCK_APP_UART_GEAR_B        (0x00000040ul) /* GEAR_IMG_UART */
#define PM_CLOCK_APP_SPI_GEAR_B         (0x00000020ul) /* GEAR_IMG_SPI */
#define PM_CLOCK_APP_WSPI_GEAR_B        (0x00000008ul) /* GEAR_IMG_WSPI */
#define PM_CLOCK_APP_SDIO_GEAR_B        (0x00000004ul) /* GEAR_PER_SDIO */
#define PM_CLOCK_APP_USB_GEAR_B         (0x00000002ul) /* GEAR_PER_USB */
#define PM_CLOCK_APP_VSYNC_GEAR_B       (0x00000001ul) /* GEAR_M_IMG_VENB/GEAR_N_IMG_VENB */
#define PM_CLOCK_APP_VSYNC_GEAR_N       (0x00020000ul) /* GEAR_N_IMG_VENB */

/* GPS */

#define PM_CLOCK_GPS_PLL_SEL_B          (0x00004000ul) /* CKSEL_ROOT.SEL_RF_PLL_0 */
#define PM_CLOCK_GPS_ACQ_SEL_B          (0x00000200ul) /* CKSEL_GNSS_BB.SEL_ACQ */
#define PM_CLOCK_GPS_ITP_TRK_SEL_B      (0x00000080ul) /* CKDIV_ITP.ITP_TRK */
#define PM_CLOCK_GPS_BB_MODE_SEL_B      (0x00000400ul) /* CKSEL_GNSS_BB.GNSS_MODE */
#define PM_CLOCK_GPS_LOGGER_SEL_B       (0x00000040ul) /* CKSEL_GNSS_BB.SEL_LOG */
#define PM_CLOCK_GPS_ITB_FFT_SEL_B      (0x00000020ul) /* CKSEL_GNSS_BB.SEL_ITB_FFT */
#define PM_CLOCK_GPS_BB_SEL_B           (0x00000100ul) /* CKSEL_GNSS_BB.SEL_GNSS_BB */
#define PM_CLOCK_GPS_PPS_SEL_B          (0x00000004ul) /* CKSEL_GNSS_BB.SEL_PPS */
#define PM_CLOCK_GPS_CPU_DIV_B          (0x00000002ul) /* GNSS_DIV.CPU */
#define PM_CLOCK_GPS_AHB_DIV_B          (0x00000001ul) /* GNSS_DIV.AHB */

/* PMU */

#define PM_CLOCK_PMU_SEL_B              (0x00000004ul) /* CKSEL_ROOT.PMU_SWCTL_CLK_SEL */
#define PM_CLOCK_PMU_PWCTL_SEL_B        (0x00000002ul) /* CKSEL_ROOT.SWCTL_CLK_SEL_RO_RTC */
#define PM_CLOCK_PMU_PWCTL_DIV_B        (0x00000001ul) /* CKDIV_PMU.PMUA */

#define PM_CLOCK_DOMAIN_MASK            ( PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B |\
                                          PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_CPU_DIV_B |\
                                          PM_CLOCK_SYS_AHB_DIV_B)

/* Clock Tree Data */

/* Target_id bit field */

/* |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14
 *                                |13|12|11|10|09|08|07|06|05|04|03|02|01|00|
 */

/* | Domain |              Domain another bit field                       | */

/****************************************************************************
 * Base Define
 ****************************************************************************/

/* SYSIOP */

#define PM_CLOCK_SYS_CTRL_SEL     (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B)
#define PM_CLOCK_SYSPLL_DIV       (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B)
#define PM_CLOCK_SYS_CPU_SEL      (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B)
#define PM_CLOCK_SYS_CPU_DIV      (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_CPU_DIV_B)
#define PM_CLOCK_SYS_AHB_DIV      (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_CPU_DIV_B | PM_CLOCK_SYS_AHB_DIV_B)
#define PM_CLOCK_SYS_APB_DIV      (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_CPU_DIV_B | PM_CLOCK_SYS_AHB_DIV_B | PM_CLOCK_SYS_APB_DIV_B)
#define PM_CLOCK_SYS_COMIF_DIV    (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_COMIF_DIV_B)
#define PM_CLOCK_SYS_UART1_SEL    (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_COMIF_DIV_B | PM_CLOCK_SYS_UART1_SEL_B)
#define PM_CLOCK_SYS_SFC_DIV      (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_SFC_DIV_B)
#define PM_CLOCK_PMU_RTC_PCLK_SEL (PM_DOMAIN_SYSIOP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_SYS_CPU_DIV_B| PM_CLOCK_SYS_AHB_DIV_B | PM_CLOCK_SYS_APB_DIV_B | PM_CLOCK_PMU_RTC_PCLK_SEL_B)

/* HOSTIF */

#define PM_CLOCK_HIF_SEL        (PM_DOMAIN_HOSTIF | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_HIF_SEL_B)
#define PM_CLOCK_HIF_DIV        (PM_DOMAIN_HOSTIF | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_HIF_SEL_B | PM_CLOCK_HIF_DIV_B)
#define PM_CLOCK_HIF_SEL2       (PM_DOMAIN_HOSTIF | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_HIF_SEL_B | PM_CLOCK_HIF_DIV_B | PM_CLOCK_SCU_XOSC_DIV_B | PM_CLOCK_HIF_SEL2_B)
#define PM_CLOCK_HIF_UART0_SEL  (PM_DOMAIN_HOSTIF | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_HIF_SEL_B | PM_CLOCK_HIF_DIV_B | PM_CLOCK_SCU_XOSC_DIV_B | PM_CLOCK_HIF_SEL2_B | PM_CLOCK_HIF_UART0_SEL_B)
#define PM_CLOCK_HIF_I2C_SEL    (PM_DOMAIN_HOSTIF | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_HIF_SEL_B | PM_CLOCK_HIF_DIV_B | PM_CLOCK_SCU_XOSC_DIV_B | PM_CLOCK_HIF_SEL2_B | PM_CLOCK_HIF_I2C_SEL_B)

/* SCU */

#define PM_CLOCK_SCU_XOSC_DIV   (PM_DOMAIN_SCU | PM_CLOCK_SCU_XOSC_DIV_B)
#define PM_CLOCK_SCU_SEL        (PM_DOMAIN_SCU | PM_CLOCK_SCU_XOSC_DIV_B | PM_CLOCK_SCU_32K_SEL_B | PM_CLOCK_SCU_SEL_B)
#define PM_CLOCK_SCU_32K_SEL    (PM_DOMAIN_SCU | PM_CLOCK_SCU_32K_SEL_B)
#define PM_CLOCK_SCU_HPADC_SEL  (PM_DOMAIN_SCU | PM_CLOCK_SCU_32K_SEL_B | PM_CLOCK_SCU_HPADC_SEL_B)
#define PM_CLOCK_SCU_LPADC_DIV  (PM_DOMAIN_SCU | PM_CLOCK_SCU_32K_SEL_B | PM_CLOCK_SCU_LPADC_DIV_B)

/* APP */

#define PM_CLOCK_APP_SYSPLL_DIV     (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_APP_SYSPLL_DIV_B)
#define PM_CLOCK_APP_SEL            (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B)
#define PM_CLOCK_APP_AUD_MCLK_DIV   (PM_DOMAIN_APP | PM_CLOCK_APP_AUD_MCLK_DIV_B)
#define PM_CLOCK_APP_AUD_MCLK_SEL   (PM_DOMAIN_APP | PM_CLOCK_APP_AUD_MCLK_DIV_B | PM_CLOCK_APP_AUD_MCLK_SEL_B)
#define PM_CLOCK_APP_AHB_GEAR       (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_AHB_GEAR_B)
#define PM_CLOCK_APP_UART_GEAR      (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_UART_GEAR_B)
#define PM_CLOCK_APP_SPI_GEAR       (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_SPI_GEAR_B)
#define PM_CLOCK_APP_WSPI_GEAR      (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_WSPI_GEAR_B)
#define PM_CLOCK_APP_SDIO_GEAR      (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_SDIO_GEAR_B)
#define PM_CLOCK_APP_USB_GEAR       (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_USB_GEAR_B)
#define PM_CLOCK_APP_VSYNC_GEAR     (PM_DOMAIN_APP | PM_CLOCK_SYS_CTRL_SEL_B |PM_CLOCK_APP_SYSPLL_DIV_B | PM_CLOCK_APP_CPU_SEL_B | PM_CLOCK_APP_VSYNC_GEAR_B)
#define PM_CLOCK_APP_VSYNC_N_GEAR   (PM_DOMAIN_APP | PM_CLOCK_APP_VSYNC_GEAR_N)

/* GPS */

#define PM_CLOCK_GPS_PLL_SEL        (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B)
#define PM_CLOCK_GPS_ACQ_SEL        (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_BB_MODE_SEL_B | PM_CLOCK_GPS_ACQ_SEL_B)
#define PM_CLOCK_GPS_ITP_TRK_SEL    (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_BB_MODE_SEL_B | PM_CLOCK_GPS_ACQ_SEL_B | PM_CLOCK_GPS_ITP_TRK_SEL_B)
#define PM_CLOCK_GPS_BB_MODE_SEL    (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_BB_MODE_SEL_B)
#define PM_CLOCK_GPS_LOGGER_SEL     (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_LOGGER_SEL_B)
#define PM_CLOCK_GPS_ITB_FFT_SEL    (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_BB_MODE_SEL_B | PM_CLOCK_GPS_ITB_FFT_SEL_B)
#define PM_CLOCK_GPS_BB_SEL         (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_BB_MODE_SEL_B | PM_CLOCK_GPS_BB_SEL_B)
#define PM_CLOCK_GPS_PPS_SEL        (PM_DOMAIN_GPS | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_GPS_PLL_SEL_B | PM_CLOCK_GPS_BB_MODE_SEL_B | PM_CLOCK_GPS_PPS_SEL_B)
#define PM_CLOCK_GPS_CPU_DIV        (PM_DOMAIN_GPS | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_GPS_CPU_DIV_B)
#define PM_CLOCK_GPS_AHB_DIV        (PM_DOMAIN_GPS | PM_CLOCK_SYS_CTRL_SEL_B | PM_CLOCK_SYSPLL_DIV_B | PM_CLOCK_SYS_CPU_SEL_B | PM_CLOCK_GPS_CPU_DIV_B | PM_CLOCK_GPS_AHB_DIV_B)

/* PMU */

#define PM_CLOCK_PMU_SEL            (PM_DOMAIN_PMU | PM_CLOCK_PMU_SEL_B)
#define PM_CLOCK_PMU_PWCTL_SEL      (PM_DOMAIN_PMU | PM_CLOCK_PMU_SEL_B | PM_CLOCK_PMU_PWCTL_SEL_B)
#define PM_CLOCK_PMU_PWCTL_DIV      (PM_DOMAIN_PMU | PM_CLOCK_PMU_SEL_B | PM_CLOCK_PMU_PWCTL_SEL_B | PM_CLOCK_PMU_PWCTL_DIV_B )

/****************************************************************************
 * cxd56_pm_getclock & cxd56_pm_register_callback Interface Define
 ****************************************************************************/

#define PM_CLOCK_SYS_CTRL       PM_CLOCK_SYS_CTRL_SEL
#define PM_CLOCK_SYSPLL         PM_CLOCK_SYSPLL_DIV
#define PM_CLOCK_SYS_CPU        PM_CLOCK_SYS_CPU_DIV
#define PM_CLOCK_SYS_AHB        PM_CLOCK_SYS_AHB_DIV
#define PM_CLOCK_SYS_APB        PM_CLOCK_SYS_APB_DIV
#define PM_CLOCK_SYS_COMIF      PM_CLOCK_SYS_COMIF_DIV
#define PM_CLOCK_SYS_UART1      PM_CLOCK_SYS_UART1_SEL
#define PM_CLOCK_SYS_SFC        PM_CLOCK_SYS_SFC_DIV
#define PM_CLOCK_XOSC           (PM_DOMAIN_SYSIOP | 0x00100000ul)
#define PM_CLOCK_RCOSC          (PM_DOMAIN_SYSIOP | 0x00200000ul)
#define PM_CLOCK_RTC            (PM_DOMAIN_SYSIOP | 0x00080000ul)
#define PM_CLOCK_PMU_I2C        PM_CLOCK_PMU_RTC_PCLK_SEL

/* HOSTIF */

#define PM_CLOCK_HIF            PM_CLOCK_HIF_SEL2
#define PM_CLOCK_HIF_UART0      PM_CLOCK_HIF_UART0_SEL
#define PM_CLOCK_HIF_I2C        PM_CLOCK_HIF_I2C_SEL

/* SCU */

#define PM_CLOCK_SCU_XOSC       PM_CLOCK_SCU_XOSC_DIV
#define PM_CLOCK_SCU            PM_CLOCK_SCU_SEL
#define PM_CLOCK_SCU_32K        PM_CLOCK_SCU_32K_SEL
#define PM_CLOCK_SCU_HPADC      PM_CLOCK_SCU_HPADC_SEL
#define PM_CLOCK_SCU_LPADC      PM_CLOCK_SCU_LPADC_DIV

/* APP */

#define PM_CLOCK_APP_SYSPLL     PM_CLOCK_APP_SYSPLL_DIV
#define PM_CLOCK_APP            PM_CLOCK_APP_SEL
#define PM_CLOCK_APP_AUD        PM_CLOCK_APP_AUD_MCLK_SEL
#define PM_CLOCK_APP_AHB        PM_CLOCK_APP_AHB_GEAR
#define PM_CLOCK_APP_CPU        PM_CLOCK_APP_AHB
#define PM_CLOCK_APP_UART       PM_CLOCK_APP_UART_GEAR
#define PM_CLOCK_APP_SPI        PM_CLOCK_APP_SPI_GEAR
#define PM_CLOCK_APP_WSPI       PM_CLOCK_APP_WSPI_GEAR
#define PM_CLOCK_APP_SDIO       PM_CLOCK_APP_SDIO_GEAR
#define PM_CLOCK_APP_USB        PM_CLOCK_APP_USB_GEAR
#define PM_CLOCK_APP_VSYNC      PM_CLOCK_APP_VSYNC_GEAR
#define PM_CLOCK_APP_VSYNC_N    PM_CLOCK_APP_VSYNC_N_GEAR
#define PM_CLOCK_APP_VSYNC_M    PM_CLOCK_APP_VSYNC_GEAR

/* GPS */

#define PM_CLOCK_GPS_PLL        PM_CLOCK_GPS_PLL_SEL
#define PM_CLOCK_GPS_ACQ        PM_CLOCK_GPS_ACQ_SEL
#define PM_CLOCK_GPS_ITP_TRK    PM_CLOCK_GPS_ITP_TRK_SEL
#define PM_CLOCK_GPS_BB_MODE    PM_CLOCK_GPS_BB_MODE_SEL
#define PM_CLOCK_GPS_LOGGER     PM_CLOCK_GPS_LOGGER_SEL
#define PM_CLOCK_GPS_ITB_FFT    PM_CLOCK_GPS_ITB_FFT_SEL
#define PM_CLOCK_GPS_BB         PM_CLOCK_GPS_BB_SEL
#define PM_CLOCK_GPS_PPS        PM_CLOCK_GPS_PPS_SEL
#define PM_CLOCK_GPS_CPU        PM_CLOCK_GPS_CPU_DIV
#define PM_CLOCK_GPS_AHB        PM_CLOCK_GPS_AHB_DIV

/* PMU */

#define PM_CLOCK_PMU            PM_CLOCK_PMU_PWCTL_SEL
#define PM_CLOCK_PMUA           PM_CLOCK_PMU_PWCTL_DIV

#define PM_CLOCK_SYS_DMAC       PM_CLOCK_SYS_AHB
#define PM_CLOCK_SYS_SAKE       PM_CLOCK_SYS_AHB
#define PM_CLOCK_SYS_KAKI       PM_CLOCK_SYS_AHB
#define PM_CLOCK_SYS_SPIM       PM_CLOCK_SYS_COMIF
#define PM_CLOCK_SYS_I2CM       PM_CLOCK_SYS_COMIF
#define PM_CLOCK_APP_DMAC       PM_CLOCK_APP_AHB_GEAR
#define PM_CLOCK_APP_SAKE       PM_CLOCK_APP_AHB_GEAR
#define PM_CLOCK_APP_KAKI       PM_CLOCK_APP_AHB_GEAR

#define PM_CLOCK_CPUID(id)  ((0 == (id)) ? PM_CLOCK_SYS_CPU : \
                             (1 == (id)) ? PM_CLOCK_GPS_CPU : \
                                           PM_CLOCK_APP_CPU)

/* CPU status change callback */

#define PM_CPU_STATUS_CHANGE (PM_DOMAIN_SELF_CPU | 0x10000000ul)

#ifndef __ASSEMBLY__
#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

typedef int (*cxd56_pm_callback)(uint8_t id);

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

void *cxd56_pm_register_callback(uint32_t target,
                                 cxd56_pm_callback callback);
void cxd56_pm_unregister_callback(void *handle);
int cxd56_pm_fifo_handlear(int cpuid, uint32_t data[2]);
int cxd56_pm_main_task(int argc, char *argv[]);
int cxd56_pm_initialize(void);
int cxd56_pm_bootup(void);
uint32_t cxd56_pm_getclock(uint32_t target);
int cxd56_pm_hotsleep(int idletime);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY */
#endif /* __ARCH_ARM_SRC_CXD56XX_POWERMGR_H */
