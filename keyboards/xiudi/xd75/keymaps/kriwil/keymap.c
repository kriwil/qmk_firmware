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
     * | ESC    | 1      | 2      | 3      | 4      | 5      | VOL-   | MUTE   | VOL+   | 6      | 7      | 8      | 9      | 0      | `      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | F      | P      | G      | P7     | P8     | P9     | J      | L      | U      | Y      | ;      | BKSPC  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A      | R      | S      | T      | D      | P4     | P5     | P6     | H      | N      | E      | I      | O      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | P1     | P2     | P3     | K      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | CAPSLK | DELETE | LALT   | LGUI   | LOWER  | SPACE  | SPACE  | PRTSCR | ENTER  | ENTER  | RAISE  | LGUI   | RALT   | MBTN1  | MBTN2  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_COS] = LAYOUT_ortho_5x15( /* COLEMAK SPLIT */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_VOLD, KC_MUTE, KC_VOLU, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_P7,   KC_P8,   KC_P9,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_P4,   KC_P5,   KC_P6,   KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_P1,   KC_P2,   KC_P3,   KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_CAPS, KC_DEL,  KC_LALT, KC_LGUI, MO(_LO), KC_SPC, KC_SPC , KC_PSCR, KC_ENT,  KC_ENT, MO(_RA), KC_LGUI, KC_RALT, KC_BTN1, KC_BTN2
    ),

    /* LOWER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | FLASH  |        |        |        |        |        | MDPREV | PAUSE  | MDNEXT |        |        |        | -      | =      | \      |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        | [      | ]      | DELETE |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LO] = LAYOUT_ortho_5x15( /* FUNCTION */
        QK_BOOT, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_MINS, KC_EQL, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    /* RAISE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        |        |        |        | _      | +      | |      |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        |        | UP     | {      | }      |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        | LEFT   | DOWN   | RIGHT  |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        | INSERT | HOME   | PGUP   |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        |        |        |        |        | DELETE | END    | PGDOWN |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RA] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_PIPE,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, KC_UP,   KC_LCBR, KC_RCBR, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN
    )
};
