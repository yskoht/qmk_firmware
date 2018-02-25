#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

enum tap_dance_codes {
  TD_Ctrl_CtrlG = 0,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ,-----------------------------------------.  ,-----------------------------------------.
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |  |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Ctr/Cg|  A   |  S   |  D   |  F   |  G   |  |  H   |  J   |  K   |  L   | SCLN | QUOT |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   |  |  N   |  M   | COMM | DOT  | SLSH |ET/SFT|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | ESC  | LALT | LGUI | LGUI |LOWER | LSFT |  | SPC  |RAISE | LEFT | DOWN |  UP  | RGHT |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  TD(TD_Ctrl_CtrlG), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
  KC_ESC,            KC_LALT, KC_LGUI, KC_LGUI, LOWER,   KC_LSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* ,-----------------------------------------.  ,-----------------------------------------.
 * | TILD | EXLM |  AT  | HASH | DLR  | PERC |  | CIRC | AMPR | ASTR | LPRN | RPRN | DEL  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  | UNDS | PLUS | LCBR | RCBR | PIPE |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  |  | F12  |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ,-----------------------------------------.  ,-----------------------------------------.
 * | GRV  |  1   |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  | MINS | EQL  | LBRC | RBRC | BSLS |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  |  | F12  |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Ctrl_CtrlG] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, LCTL(KC_G))
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}

