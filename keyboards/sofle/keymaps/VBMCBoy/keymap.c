#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _GAME,
    _SYMB,
};

enum custom_keycodes {
    KC_OMNU = SAFE_RANGE,  // OLED menu
    KC_OSCT,  // selected ok
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  OMNU |    | OSCT  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | SYMB | LGUI | LALT | /Enter  /       \Space \  | GAME | RALT | MENU | RGUI |   Menu works as the compose key
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                      KC_6,       KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,     KC_R,    KC_T,                      KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_ESC,   KC_A,   KC_S,    KC_D,     KC_F,    KC_G,                      KC_H,       KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,     KC_V,    KC_B, KC_OMNU,   KC_OSCT,  KC_N,       KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LCTRL,TO(_SYMB), KC_LGUI,  KC_LALT, KC_ENT,      KC_SPC, TO(_GAME),  KC_ALGR, KC_APP, KC_RGUI \
),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | TRNS |   1  |   2  |   3  |   4  |   5  |                    |      |      |   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |   Q  |   W  |   E  |   R  |   T  |                    |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|      |   4  |   5  |   6  |   ,  |      |
 * |------+------+------+------+------+------| TRNS  |    | TRNS  |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|      |   1  |   2  |   3  |   =  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | /Space  /       \ ESC  \  |QWERTY|   0  |   .  | Enter|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAME] = LAYOUT( \
  _______,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       XXXXXXX,   XXXXXXX,  KC_PSLS,   KC_PAST,  KC_PMNS,  XXXXXXX,\
  _______,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                       XXXXXXX,   KC_P7,    KC_P8,     KC_P9,    KC_PPLS,  KC_TRNS, \
  KC_LSFT,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                       XXXXXXX,   KC_P4,    KC_P5,     KC_P6,    KC_PCMM,  XXXXXXX, \
  KC_LCTRL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, _______,     _______, XXXXXXX,   KC_P1,    KC_P2,     KC_P3,    KC_PEQL,  KC_TRNS, \
        _______, _______, _______, _______, _______,                 _______, TO(_QWERTY), KC_P0, KC_PDOT, KC_PENT\
),
/* SYMB
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | TRNS | F1   | F2   | F3   | F4   | F5   |                    | F6   | F7   |  F8  | F9   | F10  | F11   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |                    |  R   |  E   |PrntSc|ScrLck|Pause | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS | LEFT |  UP  | DOWN | RIGHT|      |-------.    ,-------|  I   |  S   | Ins  | Home | PgUp | Bspc |
 * |------+------+------+------+------+------| TRNS   |   | TRNS  |------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |-------|    |-------|  U   |  B   | Del  | End  | PgDn | TRNS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS |QWERTY| TRNS |     |  /Enter  /       \Space \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMB] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                         KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                       KC_R,  KC_E,  KC_PSCR, KC_SLCK, KC_PAUS, KC_F12, \
  _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, XXXXXXX,                       KC_I,  KC_S,  KC_INS,  KC_HOME, KC_PGUP, KC_BSPC, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,    _______, KC_U,  KC_B,  KC_DEL,  KC_END,  KC_PGDN, _______, \
        _______, TO(_QWERTY), _______, _______, KC_ENT,                      KC_SPC, _______, _______, _______, _______ \
),
};

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#endif
