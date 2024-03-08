/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "env_validate.h"

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "BTT SKR Mini E3 V3.0"
#endif

#define USES_DIAG_JUMPERS

// Onboard I2C EEPROM
#if ANY(NO_EEPROM_SELECTED, I2C_EEPROM)
  #undef NO_EEPROM_SELECTED
  #define I2C_EEPROM
  #define SOFT_I2C_EEPROM    
  #define I2C_SCL_PIN                       PB6
  #define I2C_SDA_PIN                       PB7
  #define MARLIN_EEPROM_SIZE              0x1000  // 4K
#endif

// Led
#define LED_PIN                             PD8

// Servo
#define SERVO0_PIN                          PA1   

// Endstops
#define X_STOP_PIN                          PC0   
#define Y_STOP_PIN                          PC1   
#define Z_STOP_PIN                          PC2   
#define Z_MIN_PROBE_PIN                     PC14  

// Filament sensor
#define FIL_RUNOUT_PIN                      -1 

// Power 
#define POWER_LOSS_PIN                      -1
#define PS_ON_PIN                           -1

// Steppers
#define X_ENABLE_PIN                        PB14
#define X_STEP_PIN                          PB13
#define X_DIR_PIN                           PB12
#define Y_ENABLE_PIN                        PB11
#define Y_STEP_PIN                          PB10
#define Y_DIR_PIN                           PB2
#define Z_ENABLE_PIN                        PB1
#define Z_STEP_PIN                          PB0
#define Z_DIR_PIN                           PC5
#define E0_ENABLE_PIN                       PD1
#define E0_STEP_PIN                         PB3
#define E0_DIR_PIN                          PB4

// UART stepper drivers
#if HAS_TMC_UART
  #define X_HARDWARE_SERIAL  MSerial4
  #define Y_HARDWARE_SERIAL  MSerial4
  #define Z_HARDWARE_SERIAL  MSerial4
  #define E0_HARDWARE_SERIAL MSerial4

  #ifndef X_SLAVE_ADDRESS
    #define X_SLAVE_ADDRESS  0
  #endif
  #ifndef Y_SLAVE_ADDRESS
    #define Y_SLAVE_ADDRESS  2
  #endif
  #ifndef Z_SLAVE_ADDRESS
    #define Z_SLAVE_ADDRESS  1
  #endif
  #ifndef E0_SLAVE_ADDRESS
    #define E0_SLAVE_ADDRESS 3
  #endif
#endif

// Temperature sensors
#define TEMP_0_PIN                          PA0   // TH0
#define TEMP_BED_PIN                        PC4   // TB0

// Heaters
#define HEATER_0_PIN                        PC8   // HE
#define HEATER_BED_PIN                      PC9   // HB

// Fans
#define FAN0_PIN                            PB15  // FAN2
#define FAN1_PIN                            PC7   // FAN1
#define FAN2_PIN                            -1

// LCD
#define BTN_ENC                  PA15
#define BTN_EN1                  PB8
#define BTN_EN2                  PD6
#define BEEPER_PIN               PB5
#define LCD_RESET_PIN            PA10    
#define DOGLCD_CS                PA9
#define DOGLCD_A0                PB9
#define DOGLCD_SCK               PA5
#define DOGLCD_MOSI              PA7
#define NEOPIXEL_PIN             PA8
#define LCD_BACKLIGHT_PIN        -1
#define SD_DETECT_PIN            PC14
#define SDSS                     PA1

// SPI bus
#define FORCE_SOFT_SPI
#define ONBOARD_SPI_DEVICE       1
#define ENABLE_SPI1