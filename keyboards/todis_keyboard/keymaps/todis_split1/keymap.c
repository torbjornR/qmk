/* Copyright 2021 torbjorn rasmusson
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,  //defaust alfa
    SYMBOL //symbols
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT(  // layer 0 : default
        // left hand
        KC_TAB,         KC_QUOT,      KC_COMM,   KC_DOT,   KC_P,    KC_Y,
        KC_ESC,         KC_A,         KC_O,      KC_E,     KC_U,    KC_I,  
        KC_LSFT,        KC_SCLN,      KC_Q,      KC_J,     KC_K,    KC_X,
                                                 KC_SPC,   KC_ENT,  MO(SYMBOL)
    ),
[SYMBOL] = LAYOUT(  // layer 1: symbols
        // left hand
        KC_TAB,         KC_QUOT,      KC_7,   KC_8,   KC_9,    KC_Y,
        KC_ESC,         KC_A,         KC_4,      KC_5,     KC_6,    KC_I,  
        KC_LSFT,        KC_SCLN,      KC_1,      KC_2,     KC_3,    KC_X,
                           	                                  KC_0,  KC_ENT, KC_BSPC
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
