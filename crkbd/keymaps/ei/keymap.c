#include QMK_KEYBOARD_H

enum {
    // TD_PC,
    // TD_COMI,
    // TD_SLA,
    TD_CAPLOCK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESC,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                          KC_J, KC_L,   KC_U,      KC_Y,   KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TAB,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                          KC_M, KC_N,   KC_E,      KC_I,   KC_O,    KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                          KC_K, KC_H,   KC_COMM,   KC_DOT, KC_SLSH, KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(1),TD(TD_CAPLOCK),KC_SPC,        KC_ENT, MO(2), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_F7,  KC_F8,  KC_F9,  KC_F10,  XXXXXXX,  XXXXXXX,                        KC_EQL,    KC_7,   KC_8,    KC_9,   KC_0,     XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F4,  KC_F5,  KC_F6,  KC_F11,  XXXXXXX,  XXXXXXX,                        KC_MINS,   KC_4,   KC_5,    KC_6,   KC_PLUS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F1,  KC_F2,  KC_F3,  KC_F12,  XXXXXXX,  XXXXXXX,                        KC_UNDS,   KC_1,   KC_2,    KC_3,   KC_ASTR,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, XXXXXXX, XXXXXXX,         XXXXXXX, MO(3), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_PIPE, XXXXXXX, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                      XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_BSLS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(3), XXXXXXX, XXXXXXX,         XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_TOG, RGB_HUI, RGB_VAI, RGB_SPI, XXXXXXX, KC_VOLU,                      KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_MOD, RGB_HUD, RGB_VAD, RGB_SPD, XXXXXXX, KC_VOLD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, XXXXXXX, XXXXXXX,       XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

tap_dance_action_t tap_dance_actions[] = {
    // [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    // [TD_COMI] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    // [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

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