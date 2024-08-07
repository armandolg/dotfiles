#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define MASTER_LEFT
#define TAPPING_TERM 200
#define RGB_MATRIX_SLEEP
#undef USE_I2C
#undef SSD1306OLED

#if defined(OLED_ENABLE)
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define SPLIT_OLED_ENABLE
#    define OLED_FONT_H "keyboards/crkbd/keymaps/ei/glcdfont.c"
#    define KEY_LOG_ENABLE
#    define OLED_TIMEOUT 60000
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