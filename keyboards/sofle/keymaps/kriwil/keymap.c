// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_COLEMAK = QK_USER,
    KC_QWERTY,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |  MUTE |    |       |   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *               | DEL  | LALT | LGUI |LOWER | SPACE |    | ENTER |RAISE | RGUI | RALT |RCTRL |
 *               `----------------------------------'     '-----------------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_DEL,KC_LALT,KC_LGUI, TL_LOWR, KC_SPC,      KC_ENT,  TL_UPPR, KC_RGUI, KC_RALT, KC_RCTL
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCRTL |   A  |   R  |   S  |   T  |   D  |                    |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |  MUTE |    |       |   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *               | DEL  | LALT | LGUI |LOWER | SPACE |    | ENTER |RAISE | RGUI | RALT |RCTRL |
 *               `----------------------------------'     '-----------------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
  KC_LCTL,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                    KC_DEL,  KC_LALT, KC_LGUI, TL_LOWR, KC_SPC,  KC_ENT,  TL_UPPR, KC_RGUI, KC_RALT, KC_RCTL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |CPSLCK|
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LSHIFT|  =   |  -   |  +   |   {  |   }  |  MUTE |    |       |   [  |   ]  |   _  |   |  |   \  |RSHIFT|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *               | DEL  | LALT | LGUI |LOWER | SPACE |    | ENTER |RAISE | RGUI | RALT |RCTRL |
 *               `----------------------------------'     '-----------------------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CAPS,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, _______, _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_BSLS, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |      | INS  | HOME | PGUP |      |                    |      |      | UP   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      | DEL  | END  |PGDOWN|      |                    |      | LEFT | DOWN |RIGHT |      |      |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LSHIFT|     |       |      |      |      |  MUTE |    |       |      |      |      |      |      |RSHIFT|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *               | DEL  | LALT | LGUI |LOWER | SPACE |    | ENTER |RAISE | RGUI | RALT |RCTRL |
 *               `----------------------------------'     '-----------------------------------'
 */
[_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |QWERTY|COLEMK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |                    |      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  MUTE |    |       |      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *               | DEL  | LALT | LGUI |LOWER | SPACE |    | ENTER |RAISE | RGUI | RALT |RCTRL |
 *               `----------------------------------'     '-----------------------------------'
 */
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, KC_QWERTY,KC_COLEMAK, CG_TOGG, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, CG_TOGG,  XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case KC_QWERTY:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_QWERTY);
        //     }
        //     return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
