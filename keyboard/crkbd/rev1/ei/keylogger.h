#include QMK_KEYBOARD_H
#pragma once
#include <stdbool.h>

#if defined(OLED_VERTICAL)
#    define KEYLOG_LEN (49)
#else
#    define KEYLOG_LEN (38)
#endif

#define KEYLOG_EOL_LEN (KEYLOG_LEN + 1)

#define SPECIAL_KEYS_SHIFT(kc) (0x18 + (kc))
#define RM_LSFT(kc) ((uint8_t)(0x20) + (kc - 0x200))
#define ALT_CODE (0x7E)
#define ASCII_TABLE_LENGTH (0x80)
#define KEYLOG_STRING_STARTUP (KEYLOG_EOL_LEN + 1)

bool process_record_oled(uint16_t keycode, keyrecord_t *record);
void render_keylogger_status(void);
void add_keylog(uint16_t keycode);