#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCRTL |   A  |   R  |   S  |   T  |   D  |                    |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |       |    |       |   K  |   M  |   ,  |   .  |   /  |RSHIFT|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *                      |      | LALT | LGUI | SPACE |    | ENTER | RGUI | RALT |      |
 *                      |      |      |      | LOWER |    | RAISE |      |      |      |
 *                      `---------------------------'     '----------------------------'
 */
 [_COLEMAK] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_TAB,  KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,                                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_LCTL, KC_A,    KC_R,   KC_S,    KC_T,    KC_D,                                 KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,          XXXXXXX, XXXXXXX,      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                       XXXXXXX, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_RGUI, KC_RALT, XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |GRAVE |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |ENTER |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LSHIFT|  =   |  -   |  +   |   [  |   ]  |       |    |       |   {  |   }  |   _  |   |  |   \  |RSHIFT|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *                      |      | LALT | LGUI | SPACE |    | ENTER | RGUI | RALT |      |
 *                      |      |      |      | LOWER |    | RAISE |      |      |      |
 *                      `---------------------------'     '----------------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_ENT,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_BSLS, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      | INS  | HOME | PGUP |      |                    |      |      | UP   |      |      |VOLUP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL | F11  | DEL  | END  |PGDOWN| MUTE |                    | PLAY | LEFT | DOWN |RIGHT | F12  |VOLDN |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |LSHIFT| F1  | F2    | F3   | F4   | F5   |       |    |       | F6   | F7   | F8   | F9   | F10  |RSHIFT|
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *                      |      | LALT | LGUI | SPACE |    | ENTER | RGUI | RALT |      |
 *                      |      |      |      | LOWER |    | RAISE |      |      |      |
 *                      `---------------------------'     '----------------------------'
 */
[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_ESC,  XXXXXXX, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_VOLU,
  _______, KC_F11,  KC_DEL,  KC_END,  KC_PGDN, KC_MUTE,                   KC_MPLY, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12,  KC_VOLD,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                             XXXXXXX, _______, _______, _______, _______,  _______, _______, XXXXXXX
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |SCPT3 |SCPT4 |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CPSLCK|      |      |SCPT3C|SCPT4C|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|-------|    |-------|------+------+------+------+------+------|
 * |      |     |       |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *                      |      | LALT | LGUI | SPACE |    | ENTER | RGUI | RALT |      |
 *                      |      |      |      | LOWER |    | RAISE |      |      |      |
 *                      `---------------------------'     '----------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,          XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, LSG(KC_3),       LSG(KC_4),        XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, LCTL(LSG(KC_3)), LCTL(LSG(KC_4)),  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX,         _______, _______, _______, _______, _______, _______, XXXXXXX
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
