#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _FKEYS 1
#define _ADJUST 16

enum custom_keycodes {
  FKEYS = SAFE_RANGE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Macropad FKEYS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | TAB  |  Q   |  W   |  E   |  R   |  T   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | CTRL |  A   |  S   |  D   |  F   |  G   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | SHIFT|  Z   |  X   |  C   |  V   |  B   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |ADJUST| DEL  | ALT  | ESC  | ENTER| SPACE|
 * `-----------------------------------------------------------------------------------'
 */
[_FKEYS] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, KC_ESC,   KC_1,   KC_2,    KC_3,   KC_4,   KC_5,  \
  /* _______, _______, _______, _______, _______, _______, KC_F1,    KC_F2,  KC_F3,   KC_F4,  KC_F5,  KC_F6, \ */
  _______, _______, _______, _______, _______, _______, KC_TAB,   KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,  \
  _______, _______, _______, _______, _______, _______, KC_LCTRL, KC_A,   KC_S,    KC_D,   KC_F,   KC_G,  \
  _______, _______, _______, _______, _______, _______, KC_LSFT,  KC_Z,   KC_X,    KC_C,   KC_V,   KC_B,  \
  _______, _______, _______, _______, _______, _______, ADJUST,   KC_DEL, KC_LALT, KC_ESC, KC_ENT, KC_SPC \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |FKEYS |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, _______, _______, _______, _______, _______, FKEYS,   _______, _______, _______, _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FKEYS:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_FKEYS);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
