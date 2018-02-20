#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE  0
#define LOWER 1
#define RAISE 2

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, 
};

enum tap_dance_codes {
  TD_Ctrl_CtrlG = 0, 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
        KC_ESC,            KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,
        KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    CTL(KC_Z),
        TD(TD_Ctrl_CtrlG), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,
        KC_LCTRL,          KC_LGUI, KC_LALT, KC_LALT, MO(LOWER),
                                                             CTL(KC_C), CTL(KC_V),
                                                                        ALT(KC_TAB),
                                                   KC_LSFT, KC_SPC,     KC_ENT,

        KC_PSCREEN, KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        CTL(KC_Y),  KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                    KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_B,       KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                    MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        KC_LEFT, KC_RIGHT,
        KC_UP,
        KC_DOWN, KC_ENT, KC_SPC
    ),

[LOWER] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
                KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
       _______, KC_F12,  _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[RAISE] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,

       _______,  _______, _______, _______, _______, _______, _______,
       _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
                 KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
       _______,  KC_F12,  _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Ctrl_CtrlG] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, LCTL(KC_G))
};


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
