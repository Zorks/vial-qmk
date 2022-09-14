/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Ben Roesner (keycapsss.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* VIAL UID for Lily58*/
#define VIAL_KEYBOARD_UID {0x7E, 0xFD, 0xFC, 0x5B, 0x7D, 0x39, 0x48, 0x06}

/* VIAL secure unlock keystroke - currently both big keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS {4, 9}
#define VIAL_UNLOCK_COMBO_COLS {4, 4}

/* ws2812 RGB MATRIX LED */
#ifdef RGB_MATRIX_ENABLE
#	 define DRIVER_LED_TOTAL 70 // Number of LEDs for Lily58 Light
#	 define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // Sane brightness values so the board has enough power to operate
# 	 define RGB_MATRIX_STARTUP_VAL 120
#	 define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#	 define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_SPLIT { 35, 35 }
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    define RGBLIGHT_SLEEP
#    define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // max leds processed per animation task
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16 // LEDs refresh rate max. 60fps
#    define RGB_MATRIX_HUE_STEP 4
#    define RGB_MATRIX_SAT_STEP 4
#    define RGB_MATRIX_VAL_STEP 3
#    define RGB_MATRIX_SPD_STEP 6
#	 define RGB_MATRIX_STARTUP_SPD 10 //animation speed
#	 define VIALRGB_NO_DIRECT
#	 undef RGBLIGHT_ANIMATIONS
# 	 define SPLIT_TRANSPORT_MIRROR  	 // This mirrors the master side matrix to the slave side for features that react or require knowledge of master side key presses on the slave side
#	 define SPLIT_LAYER_STATE_ENABLE    	 // enables syncing of the layer state between both halves of the split keyboard
#	 define SPLIT_LED_STATE_ENABLE 			 // enables syncing of the Host LED status (caps lock, num lock, etc) between both halves of the split keyboard
#	 define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE //simple animation set as default so layer indicators will work
// Effects enabled
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#	 define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE  // Pulses keys hit to hue & value then fades value out
#	 define ENABLE_RGB_MATRIX_SOLID_REACTIVE      // Static single hue, pulses keys hit to shifted hue then fades to current hue
#	 define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE // Hue & value pulse near multiple key hits then fades value out
#endif

#define TAPPING_TERM 180  // max allowable time between taps in milliseconds
#define TAPPING_TOGGLE 2
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// a little space saving
#define VIAL_TAP_DANCE_ENTRIES 8
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT


