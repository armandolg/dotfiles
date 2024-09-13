#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define MASTER_LEFT
#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define RGB_MATRIX_SLEEP

#ifdef OLED_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define OLED_FONT_H "keyboards/crkbd/keymaps/ei/glcdfont.c"
#    define KEY_LOG_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#endif