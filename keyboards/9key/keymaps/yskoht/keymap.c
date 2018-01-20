#include "9key.h"

// Tap Dance Declarations
enum {
  ENT_5 = 0,
  ZERO_7
};

// Macro Declarations
enum {
  DBL_0 = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = KEYMAP( \
  KC_HOME , KC_BSPC , KC_DEL  , \
  KC_END  , KC_UP  , KC_ENTER, \
  KC_LEFT , KC_DOWN, KC_RIGHT  \
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
  [ZERO_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_0)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
      switch(id) {
          case DBL_0:
              SEND_STRING("00");
              return false;
      }
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
}
