#include QMK_KEYBOARD_H
#include "oled.h"
#include "keylogger.h"

enum { TD_CAPLOCK };

enum layers { _DEFAULT, _LOWER, _RAISE, _ADJUST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESC,       KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,    KC_L,   KC_U,     KC_Y,   KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    CTL_T(KC_ESC),KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                          KC_M,    KC_N,   KC_E,     KC_I,   KC_O,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TAB,       KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                          KC_K,    KC_H,   KC_COMM,  KC_DOT, KC_SLSH, KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(1),TD(TD_CAPLOCK),KC_SPC,        KC_ENT, MO(2), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_F7,  KC_F8,  KC_F9,  KC_F12,  XXXXXXX,  XXXXXXX,                        KC_PLUS,   KC_7,   KC_8,    KC_9,   KC_EQL,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F4,  KC_F5,  KC_F6,  KC_F11,  XXXXXXX,  XXXXXXX,                        KC_MINS,   KC_4,   KC_5,    KC_6,   KC_0,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F1,  KC_F2,  KC_F3,  KC_F10,  XXXXXXX,  XXXXXXX,                        KC_UNDS,   KC_1,   KC_2,    KC_3,   KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, KC_LSFT, XXXXXXX,         XXXXXXX, MO(3), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_PIPE, XXXXXXX, XXXXXXX,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, XXXXXXX, KC_LBRC, KC_LPRN, KC_LCBR, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, KC_RBRC, KC_RPRN, KC_RCBR, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(3), KC_LSFT, XXXXXXX,         XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_TOG, RGB_HUI, RGB_VAI, RGB_SPI, XXXXXXX, KC_VOLU,                      KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_MOD, RGB_HUD, RGB_VAD, RGB_SPD, XXXXXXX, KC_VOLD,                      KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, XXXXXXX, XXXXXXX,       XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

tap_dance_action_t tap_dance_actions[] = {[TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_ESC):
            return true;
        default:
            return false;
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 0, 255, 0);
            };
        };
    };
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case 3:
                rgb_matrix_set_color(i, 0, 0, 0);
                break;
            case 2:
                rgb_matrix_set_color(i, 0, 0, 255);
                break;
            case 1:
                rgb_matrix_set_color(i, 0, 255, 0);
                break;
            default:
                break;
        };
    };
    return false;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case 1:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            };
            return false;
        case 2:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            };
            return false;
        case 3:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            };
    };
    return process_record_oled(keycode, record);
};