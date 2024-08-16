/* Copyright 2017 Wunder
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

enum layer_names {
    _COS,
    _LO,
    _RA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* COLEMAK SPLIT
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | MUTE   | F5     | F6     | F7     | F8     | F9     | F10    | `      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | F      | P      | G      | 7      | PLAY   | F4     | J      | L      | U      | Y      | ;      | BKSPC  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A      | R      | S      | T      | D      | 8      |        | F3     | H      | N      | E      | I      | O      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | 9      |        | F2     | K      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | CAPSLK | DELETE | LALT   | LGUI   | LOWER  | SPACE  | 0      |        | F1     | ENTER  | RAISE  | LGUI   | RALT   | MBTN1  | MBTN2  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_COS] = LAYOUT_ortho_5x15( /* COLEMAK SPLIT */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_MUTE, KC_F5,     KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,     KC_7,    KC_MPLY, KC_F4,     KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,     KC_8,    XXXXXXX, KC_F3,     KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_9,    XXXXXXX, KC_F2,     KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_CAPS, KC_DEL,  KC_LALT, KC_LGUI, MO(_LO), KC_SPC,   KC_0,    XXXXXXX, KC_F1,     KC_ENT, MO(_RA), KC_LGUI, KC_RALT, KC_BTN1, KC_BTN2
    ),

    /* LOWER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * | TAB    | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | F12    |
     * '--------------------------------------------------------------------------------------------------------------------'-----------------'
     * | LCTRL  | !      | @      | #      | $      | %      |        |        |        | ^      | &      | *      | (      | )      | CAPSLK |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * | LSHIFT | =      |  -     |  +     |   {    |   }    |        |        |        | [      |   ]    |   _    |   |    |   \    | RSHIFT |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * | CAPSLK | DELETE | LALT   | LGUI   | LOWER  | SPACE  |        |        |        | ENTER  | RAISE  | LGUI   | RALT   | MBTN1  | MBTN2  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LO] = LAYOUT_ortho_5x15( /* FUNCTION */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     _______, XXXXXXX, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      _______, XXXXXXX, _______,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   _______, XXXXXXX, _______,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CAPS,
        _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC,   _______, XXXXXXX, _______,   KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,   _______, XXXXXXX, _______,   _______, _______, _______, _______, _______, _______
    ),
    /* RAISE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        | UP     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        | LEFT   | DOWN   | RIGHT  |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '---------------------------------------------------------------------------------------------------------------------------------------
     * | CAPSLK | DELETE | LALT   | LGUI   | LOWER  | SPACE  |        | BOOT   |        | ENTER  | RAISE  | LGUI   | RALT   | MBTN1  | MBTN2  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RA] = LAYOUT_ortho_5x15( /* FUNCTION */
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, XXXXXXX, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX,   _______, XXXXXXX, _______,   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX,   _______, XXXXXXX, _______,   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, XXXXXXX, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,   _______, QK_BOOT, _______,   _______, _______, _______, _______, _______, _______
    )
};
