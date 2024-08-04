#include QMK_KEYBOARD_H

enum {
    TD_PC,
    TD_COMI,
    TD_SLA,
    TD_CAPLOCK,
    TD_ALT,
    TD_MEN,
    TD_MAY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESC,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                          KC_J, KC_L,   KC_U,      KC_Y,   TD(TD_PC), KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TAB,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                          KC_M, KC_N,   KC_E,      KC_I,      KC_O,TD(TD_COMI),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                          KC_K, KC_H,TD(TD_MEN),TD(TD_MAY),TD(TD_SLA),KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        TD(TD_CAPLOCK),MO(1),KC_SPC,        KC_ENT, MO(2), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                      KC_EQL,  KC_7, KC_8, KC_9, KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,                      KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,                      KC_UNDS, KC_1, KC_2, KC_3, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, _______, XXXXXXX,         XXXXXXX, MO(3), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_TILD,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, MO(3), XXXXXXX,         XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                      XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_TOG, RGB_HUI, RGB_VAI, RGB_SPI, XXXXXXX, KC_VOLU,                      XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_MOD, RGB_HUD, RGB_VAD, RGB_SPD, XXXXXXX, KC_VOLD,                      XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, _______, XXXXXXX,       XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_COMI] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
    [TD_MEN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)),
    [TD_MAY] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT))
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