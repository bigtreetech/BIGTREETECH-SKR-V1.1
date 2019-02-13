/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (C) 2017 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef TARGET_LPC1768
  #error "Oops!  Make sure you have the LPC1768 environment selected in your IDE."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "BIGTREE SKR V1.1"
#endif

//
// Limit Switches
//
#define X_MIN_PIN          P1_29
#define X_MAX_PIN          P1_28
#define Y_MIN_PIN          P1_27
#define Y_MAX_PIN          P1_26
#define Z_MIN_PIN          P1_25
#define Z_MAX_PIN          P1_24

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  P1_24
#endif

//
// Steppers
//
#define X_STEP_PIN         P0_04
#define X_DIR_PIN          P0_05
#define X_ENABLE_PIN       P4_28
#ifndef X_CS_PIN
  #define X_CS_PIN         P4_28    // ETH
#endif

#define Y_STEP_PIN         P2_01
#define Y_DIR_PIN          P2_02
#define Y_ENABLE_PIN       P2_00
#ifndef Y_CS_PIN
  #define Y_CS_PIN         P2_00   // ETH
#endif

#define Z_STEP_PIN         P0_20
#define Z_DIR_PIN          P0_21
#define Z_ENABLE_PIN       P0_19
#ifndef Z_CS_PIN
  #define Z_CS_PIN         P0_19   // ETH
#endif

#define E0_STEP_PIN        P0_11
#define E0_DIR_PIN         P2_13
#define E0_ENABLE_PIN      P2_12
#ifndef E0_CS_PIN
  #define E0_CS_PIN        P2_12   // ETH
#endif

#define E1_STEP_PIN        P0_01
#define E1_DIR_PIN         P0_00
#define E1_ENABLE_PIN      P0_10
#ifndef E1_CS_PIN
  #define E1_CS_PIN        P0_10   // ETH
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #define TMC_SW_MOSI      P0_18   // ETH
  #define TMC_SW_MISO      P0_17   // ETH
  #define TMC_SW_SCK       P0_15   // ETH
#endif

//
// Temperature Sensors
//  3.3V max when defined as an analog input
//
#define TEMP_BED_PIN       0   // A0 (T0) - (67) - TEMP_BED_PIN
#define TEMP_0_PIN         1   // A1 (T1) - (68) - TEMP_0_PIN
#define TEMP_1_PIN         2   // A2 (T2) - (69) - TEMP_1_PIN

//
// Heaters / Fans
//
#define HEATER_0_PIN       P2_07
#if HOTENDS == 1
  #define FAN1_PIN         P2_04
#else
  #define HEATER_1_PIN     P2_04
#endif
#define FAN_PIN            P2_03
#define HEATER_BED_PIN     P2_05

//
// Misc. Functions
//
#define SDSS               P0_06  

/**
 * Smart LCD adapter
 *
 * The Smart LCD adapter can be used for the two 10 pin LCD controllers such as
 * REPRAP_DISCOUNT_SMART_CONTROLLER.  It can't be used for controllers that use
 * DOGLCD_A0, DOGLCD_CS, LCD_PINS_D5, LCD_PINS_D6 or LCD_PINS_D7. A custom cable
 * is needed to pick up 5V for the EXP1 connection.
 *
 * SD card on the LCD uses the same SPI signals as the LCD. This results in garbage/lines
 * on the LCD display during accesses of the SD card. The menus/code has been arranged so
 * that the garbage/lines are erased immediately after the SD card accesses are completed.
 */
/*
|               _____                                             _____
|           NC | · · | GND                                    5V | · · | GND
|        RESET | · · | 1.31(SD_DETECT)                        NC | · · | NC
|   (MOSI)0.18 | · · | 3.25(BTN_EN2)                          NC | · · | 0.15 (LCD_D4)
|  (SD_SS)1.23 | · · | 3.26(BTN_EN1)               (LCD_RS) 0.16 | · · | 0.18 (LCD_EN)
|    (SCK)0.15 | · · | 0.17(MISO)                 (BTN_ENC) 2.11 | · · | 1.30 (BEEPER)
|               ￣￣                                               ￣￣  
|               EXP2                                              EXP1  
*/
#if ENABLED(ULTRA_LCD)

  #define BEEPER_PIN       P1_30   // (37) not 5V tolerant
  #define BTN_ENC          P2_11   // (35) J3-3 & AUX-4
  #define LCD_PINS_RS      P0_16   // (16) J3-7 & AUX-4

  #define BTN_EN1          P3_26   // (31) J3-2 & AUX-4
  #define BTN_EN2          P3_25   // (33) J3-4 & AUX-4
  #define SD_DETECT_PIN    P1_31   // (49) (NOT 5V tolerant)
  
  #define LCD_SDSS         P1_23

  #define LCD_PINS_ENABLE  P0_18  
  #define LCD_PINS_D4      P0_15  

    #if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER) && DISABLED(DOGLCD)
      #error "REPRAP_DISCOUNT_SMART_CONTROLLER is not supported by the BIGTREE SKR V1.1"
    #endif  
#endif // ULTRA_LCD

//#define USB_SD_DISABLED
#define USB_SD_ONBOARD        // Provide the onboard SD card to the host as a USB mass storage device

#define LPC_SD_LCD            // Marlin uses the SD drive attached to the LCD
//#define LPC_SD_ONBOARD        // Marlin uses the SD drive on the control board

#if ENABLED(LPC_SD_LCD)

  #define SCK_PIN          P0_15
  #define MISO_PIN         P0_17
  #define MOSI_PIN         P0_18
  #define SS_PIN           P1_23   // Chip select for SD card used by Marlin
  #define ONBOARD_SD_CS    P0_06   // Chip select for "System" SD card

#elif ENABLED(LPC_SD_ONBOARD)

  #if ENABLED(USB_SD_ONBOARD)
    // When sharing the SD card with a PC we want the menu options to
    // mount/unmount the card and refresh it. So we disable card detect.
    #define SHARED_SD_CARD
    #undef SD_DETECT_PIN           // redefine detect pin onboard tf card
    #define SD_DETECT_PIN  P0_27   // (57) open-drain
  #endif

  #define SCK_PIN          P0_07
  #define MISO_PIN         P0_08
  #define MOSI_PIN         P0_09
  #define SS_PIN           P1_23   // Chip select for SD card used by Marlin
  #define ONBOARD_SD_CS    P0_06   // Chip select for "System" SD card

#endif

 /**
  * Special pins
  *   P1_30  (37) (NOT 5V tolerant)
  *   P1_31  (49) (NOT 5V tolerant)
  *   P0_27  (57) (Open collector)
  *   P0_28  (58) (Open collector)
  */
