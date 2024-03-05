/****************************************************************************
 * include/nuttx/pci/pci_qemu_test.h
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

#ifndef __INCLUDE_NUTTX_PCI_PCI_QEMU_TEST_H
#define __INCLUDE_NUTTX_PCI_PCI_QEMU_TEST_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: pci_register_qemu_test_driver
 *
 * Description:
 *   register a pci driver
 *
 ****************************************************************************/

#ifdef CONFIG_PCI_QEMU_TEST
int pci_register_qemu_test_driver(void);
#endif

#ifdef CONFIG_VIRT_QEMU_EDU
extern const struct pci_dev_type_s g_pci_type_qemu_edu;
#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __INCLUDE_NUTTX_PCI_PCI_QEMU_TEST_H */