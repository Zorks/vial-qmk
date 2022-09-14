 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
#include "split_util.h"

extern uint8_t is_master;
// Layer Declarations 
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};




// Define custom keys
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |    | Skip  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,    KC_MNXT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                             KC_LALT, KC_LGUI,LOWER, KC_SPC,      KC_ENT,   RAISE,   KC_BSPC, KC_RGUI
),
//commented out the two extra layers to save space as layers are defined by VIAL.
// /* LOWER 
 // * ,-----------------------------------------.                    ,-----------------------------------------.
 // * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 // * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 // * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 // * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 // * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 // * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 // * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 // * `-----------------------------------------/       /     \      \-----------------------------------------'
 // *                   |      |      |      | /       /       \      \  |      |      |      |
 // *                   |      |      |      |/       /         \      \ |      |      |      |
 // *                   `----------------------------'           '------''--------------------'
 // */
// [_LOWER] = LAYOUT(
  // _______, _______, _______, _______, _______, _______,                     _______, _______, _______,  _______, _______, _______,
  // _______, _______, _______, _______, _______, _______,                     _______, _______, _______,    _______, _______, _______,
  // _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, 
  // _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, 
                             // _______, _______, _______,  _______, _______,  _______, _______ , _______
// ),


// /* RAISE
 // * ,-----------------------------------------.                    ,-----------------------------------------.
 // * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 // * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 // * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 // * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 // * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 // * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 // * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 // * `-----------------------------------------/       /     \      \-----------------------------------------'
 // *                   |      |      |      | /       /       \      \  |      |      |      |
 // *                   |      |      |      |/       /         \      \ |      |      |      |
 // *                   `----------------------------'           '------''--------------------'
 // */

// [_RAISE] = LAYOUT(
  // _______, _______, _______, _______, _______, _______,                     _______, _______, _______,  _______, _______, _______,
  // _______, _______, _______, _______, _______, _______,                     _______, _______, _______,  _______, _______, _______,
  // _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, 
  // _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, 
                             // _______, _______, _______,  _______, _______,  _______, _______ , _______
// ),

};
 // uncomment the following only if there's an adjust layer too
// layer_state_t layer_state_set_user(layer_state_t state) {
    // state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    // return state;
// }

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
		// 'lily cascadia', 128x32px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x20, 0x00, 0x00, 
		0x20, 0xe0, 0x20, 0x20, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
		0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xe0, 0xc0, 
		0x00, 0x00, 0xc0, 0xe0, 0x38, 0x70, 0xc0, 0x00, 0xe0, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0xc0, 
		0xc0, 0xbc, 0xf8, 0xc0, 0x9f, 0x3c, 0xe0, 0xc0, 0x84, 0xb8, 0xe0, 0x00, 0x40, 0xf8, 0xf0, 0xe0, 
		0xc0, 0xf0, 0xc0, 0xe0, 0xf8, 0xf4, 0xc0, 0x60, 0x00, 0x00, 0xc0, 0xe0, 0x90, 0xc0, 0x40, 0x00, 
		0x80, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x42, 0x66, 0x46, 
		0xc2, 0x83, 0x40, 0x40, 0xc3, 0x83, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
		0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 
		0xe0, 0xe0, 0xfc, 0xfc, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf8, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xfe, 0xfc, 0xff, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xe3, 0xe7, 0xef, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xcf, 0xfe, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xfc, 0xff, 0x5f, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xfc, 0x7c, 0x3e, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc7, 0xcc, 0xcc, 0xcc, 
		0xc7, 0xc7, 0xc4, 0xcc, 0xc4, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x03, 0x03, 0x03, 0x03, 0x03, 
		0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0f, 0x03, 0x00, 0x8f, 0xe7, 0x71, 0x1c, 
		0x6f, 0x3f, 0xcf, 0xef, 0xff, 0x3f, 0x7f, 0xbf, 0xff, 0xff, 0xff, 0xe7, 0xf8, 0xf8, 0x7c, 0x3c, 
		0xff, 0x7f, 0x1f, 0xc7, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xc6, 
		0xfd, 0xff, 0xff, 0x3f, 0x1f, 0x7d, 0xff, 0xff, 0xff, 0x1f, 0x3f, 0xff, 0xff, 0x3f, 0x6f, 0x3f, 
		0x07, 0x0d, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
		0x1e, 0x12, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 
		0x00, 0x00, 0x1f, 0xff, 0x01, 0x00, 0x00, 0x0f, 0x1f, 0x01, 0x03, 0x0f, 0x03, 0x00, 0x00, 0x00, 
		0x01, 0x00, 0x21, 0x1d, 0x0f, 0x03, 0x19, 0x0f, 0x03, 0x00, 0x05, 0x07, 0x03, 0x00, 0x00, 0x03, 
		0x0f, 0x02, 0x1f, 0x21, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}
//static display on both OLEDs....decisions were made for space
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_lily58_logo();
  } else {
    render_lily58_logo();
  }
    return false;
}

#endif // OLED_ENABLE

// Rotary encoder related code
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
};
#endif
//RGB Matrix (borrowed from https://github.com/qmk/qmk_firmware/pull/8900/files - don't fully understand the x,y coordinates used but they work so why mess with it?)
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
	// Key Matrix to LED Index
		{  11,  10,   9,   8,   7,   6 },
		{  12,  13,  14,  15,  16,  17 },
		{  23,  22,  21,  20,  19,  18 },
		{  24,  25,  26,  27,  28,  29 },
		{  NO_LED,  34,  33,  32,  31,  30 },
	//right half - flipped direction
		{  46,  45,  44,  43,  42,  41 },
		{  47,  48,  49,  50,  51,  52 },
		{  58,  57,  56,  55,  54,  53 },
		{  59,  60,  61,  62,  63,  64 },
		{  NO_LED,  69,  68,  67,  66,  65 }
    }, {
	// LED Index to Physical Position 
    // Left half
		{  89, 55 }, {  54, 52 }, {  19, 42 }, {  19, 13 }, {  54,  9 }, {  89, 12 }, {  89,  4 },
		{  72,  3 }, {  54,  1 }, {  37,  2 }, {  19,  6 }, {   1,  7 }, {   1, 21 }, {  19, 20 },
		{  37, 17 }, {  54, 16 }, {  72, 17 }, {  89, 19 }, {  89, 33 }, {  72, 31 }, {  54, 30 },
		{  37, 31 }, {  19, 35 }, {   1, 36 }, {   1, 50 }, {  19, 49 }, {  37, 46 }, {  54, 44 },
		{  72, 46 }, {  89, 47 }, { 107, 40 }, { 104, 62 }, {  81, 61 }, {  63, 60 }, {  45, 60 },
    // Right half
		{ 135, 55 }, { 170, 52 }, { 205, 42 }, { 205, 13 }, { 170,  9 }, { 135, 12 }, { 135,  4 },
		{ 152,  3 }, { 170,  1 }, { 187,  2 }, { 205,  6 }, { 223,  7 }, { 223, 21 }, { 205, 20 },
		{ 187, 17 }, { 170, 16 }, { 152, 17 }, { 135, 19 }, { 135, 33 }, { 152, 31 }, { 170, 30 },
		{ 187, 31 }, { 205, 35 }, { 223, 36 }, { 223, 50 }, { 205, 49 }, { 187, 46 }, { 170, 44 },
		{ 152, 46 }, { 135, 47 }, { 117, 40 }, { 120, 62 }, { 143, 61 }, { 161, 60 }, { 179, 60 }
    }, {
	// LED Index to Flag
    // 0x01 = 1 = modifier key
    // 0x02 = 2 = underglow
    // 0x04 = 4 = key backlight
    // 0x08 = 8 = keyboard state indication
    // Left half
        2, 2, 2, 2, 2, 2, 4,
        4, 4, 4, 4, 1, 1, 4,
        4, 4, 4, 4, 4, 4, 4,
        4, 4, 1, 1, 4, 4, 4,
        4, 4, 4, 1, 1, 1, 1,
    // Right half		
        2, 2, 2, 2, 2, 2, 4,
        4, 4, 4, 4, 1, 1, 4,
        4, 4, 4, 4, 4, 4, 4,
        4, 4, 1, 1, 4, 4, 4,
        4, 4, 4, 1, 1, 1, 1
} };
#endif
//END RGB MATRIX
//RGB MATRIX MODS

//Capslock indicator on shift keys
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(24, 135, 0, 0); // led #24 - Shift Key Left
		RGB_MATRIX_INDICATOR_SET_COLOR(59, 135, 0, 0); // led #59 - Shift Key Right
    }
	switch(get_highest_layer(layer_state)){  // special handling per layer
            case 1:  //layer 1
                RGB_MATRIX_INDICATOR_SET_COLOR(32, 135, 0, 0);
			    for (uint8_t i = led_min; i <= led_max; i++) {
					if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x02 == Underglow
					rgb_matrix_set_color(i, 255, 0, 0);
					}
				}
            break;
            case 2:  //layer 2
                RGB_MATRIX_INDICATOR_SET_COLOR(67, 0, 0, 135);
			    for (uint8_t i = led_min; i <= led_max; i++) {
					if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x02 == Underglow
					rgb_matrix_set_color(i, 0, 0, 255);
					}
				}				
            break;
            default: //layer 0
                break;
            break;
}
}
//END RGB MATRIX MODS