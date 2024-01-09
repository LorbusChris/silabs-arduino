/***************************************************************************//**
 * @file
 * @brief I2CSPM Config
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef SL_I2CSPM_QWIIC_CONFIG_H
#define SL_I2CSPM_QWIIC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu

// <h>I2CSPM settings

// <o SL_I2CSPM_QWIIC_REFERENCE_CLOCK> Reference clock frequency
// <i> Frequency in Hz of the reference clock.
// <i> Select 0 to use the frequency of the currently selected clock.
// <i> Default: 0
#define SL_I2CSPM_QWIIC_REFERENCE_CLOCK 0

// <o SL_I2CSPM_QWIIC_SPEED_MODE> Speed mode
// <0=> Standard mode (100kbit/s)
// <1=> Fast mode (400kbit/s)
// <2=> Fast mode plus (1Mbit/s)
// <i> Default: 0
#define SL_I2CSPM_QWIIC_SPEED_MODE      0
// </h> end I2CSPM config

// <<< end of configuration section >>>

// <<< sl:start pin_tool >>>
// <i2c signal=SCL,SDA> SL_I2CSPM_QWIIC
// $[I2C_SL_I2CSPM_QWIIC]
#define SL_I2CSPM_QWIIC_PERIPHERAL               I2C0
#define SL_I2CSPM_QWIIC_PERIPHERAL_NO            0

// I2C0 SCL on PB03
#define SL_I2CSPM_QWIIC_SCL_PORT                 gpioPortB
#define SL_I2CSPM_QWIIC_SCL_PIN                  3

// I2C0 SDA on PB04
#define SL_I2CSPM_QWIIC_SDA_PORT                 gpioPortB
#define SL_I2CSPM_QWIIC_SDA_PIN                  4

// [I2C_SL_I2CSPM_QWIIC]$
// <<< sl:end pin_tool >>>

#endif // SL_I2CSPM_QWIIC_CONFIG_H
