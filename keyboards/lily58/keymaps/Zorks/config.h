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

#ifdef RGBLIGHT_ENABLE
// #    define RGBLIGHT_ANIMATIONS // individually definining animations to save a little space
// #    define RGBLIGHT_EFFECT_BREATHING
// #    define RGBLIGHT_EFFECT_KNIGHT
// #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 6 // number of steps to cycle through the hue by
#    define RGBLIGHT_SAT_STEP 6 // number of steps to increment the saturation by
#    define RGBLIGHT_VAL_STEP 6 // number of steps to increment the brightness by
#    define RGBLIGHT_SLEEP //  the RGB lighting will be switched off when the host goes to sleep
#	 define RGBLIGHT_LAYERS // use LEDs as status indicators to show which keyboard layer is currently active, or the state of caps lock, all without disrupting any animation
#	 define RGBLIGHT_MAX_LAYERS 4 //how many layers 
#endif

#define TAPPING_TERM 170  // max allowable time between taps in milliseconds
#define TAPPING_TOGGLE 2

#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// a little space saving
#define VIAL_TAP_DANCE_ENTRIES 8
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT
#define DISABLE_LEADER

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT