#include QMK_KEYBOARD_H
#include "keylogger.h"

#define KEYLOGGER_LENGTH 5
static char     keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
static uint16_t key_timer                        = 0;
static bool     is_key_processed                 = true;

void render_keylogger_status(void) {
    oled_write(keylog_str, false);
}

static const char PROGMEM code_to_name[0xFF] = {
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    ' ', ' ',  ' ', ' ', 'a',  'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', // 0x
    'm', 'n',  'o', 'p', 'q',  'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', // 1x
    '3', '4',  '5', '6', '7',  '8', '9', '0', 20,  19,  27,  26,  22,  '-', '=', '[', // 2x
    ']', '\\', '#', ';', '\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ', // 3x
    ' ', ' ',  ' ', ' ', ' ',  ' ', 'P', 'S', ' ', ' ', ' ', ' ', 16,  ' ', ' ', ' ', // 4x
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // 5x
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // 6x
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // 7x
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // 8x
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // 9x
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // Ax
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // Bx
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // Cx
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // Dx
    'C', 'S',  'A', 'C', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // Ex
    ' ', ' ',  ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '       // Fx
};

#if defined(KEY_LOG_ENABLE)
void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }
    for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < ARRAY_SIZE(code_to_name)) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }
}
#endif

bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_timer        = timer_read();
        is_key_processed = true;
        add_keylog(keycode);
    }
    return true;
}