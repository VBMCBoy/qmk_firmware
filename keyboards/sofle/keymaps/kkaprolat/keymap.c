#include QMK_KEYBOARD_H

enum sofle_layers {
  _QWERTY,
  _GAME,
  _SYMB,
};

enum settings {
  VOLUME,
  BRIGHTNESS,
  SHUTDOWN,
  SUSPEND,
  SYSRQ,
  MUSIC,
  PAGE,
} selected_menu;
#define SETTING_LENGTH 7

enum sysrq_keys {
  R,
  E,
  I,
  S,
  U,
  B,
  F,
  O,
} selected_sysrq;
#define SYSRQ_LENGTH 8


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
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift| // LShift and RShift are ( and ) when tapped
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | SYMB | LALT | LGUI | /Enter  /       \Space \  | MENU | RALT | GAME | RGUI |   Menu works as the compose key
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                      KC_6,       KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,     KC_R,    KC_T,                      KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_ESC,   KC_A,   KC_S,    KC_D,     KC_F,    KC_G,                      KC_H,       KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  SC_LSPO,  KC_Z,   KC_X,    KC_C,     KC_V,    KC_B, KC_OMNU,   KC_OSCT,  KC_N,       KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SC_RSPC, \
                 KC_LCTL,TO(_SYMB), KC_LALT,  KC_LGUI, KC_ENT,      KC_SPC, KC_APP,  KC_ALGR, TO(_GAME), KC_RGUI \
),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | TRNS |   1  |   2  |   3  |   4  |   5  |                    |      |      |   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |   Q  |   W  |   E  |   R  |   T  |                    |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|      |   4  |   5  |   6  |   ,  |      |
 * |------+------+------+------+------+------| TRNS  |    | TRNS  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|      |   1  |   2  |   3  |   =  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | /Space  /       \ ESC  \  |  0   |  .   |QWERTY| Enter|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAME] = LAYOUT( \
  _______,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       XXXXXXX,   XXXXXXX,  KC_PSLS,   KC_PAST,  KC_PMNS,  XXXXXXX,\
  _______,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                       XXXXXXX,   KC_P7,    KC_P8,     KC_P9,    KC_PPLS,  KC_TRNS, \
  KC_LCTL,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                       XXXXXXX,   KC_P4,    KC_P5,     KC_P6,    KC_PCMM,  XXXXXXX, \
  KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, _______,     _______, XXXXXXX,   KC_P1,    KC_P2,     KC_P3,    KC_EQL,  KC_TRNS, \
        _______, _______, _______, _______, KC_SPC,                 KC_ESC, KC_P0, KC_PDOT, TO(_QWERTY), KC_PENT\
),
/* SYMB
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | TRNS | F1   | F2   | F3   | F4   | F5   |                    | F6   | F7   |  F8  | F9   | F10  | F11   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |                    |      |      |PrntSc|ScrLck|Pause | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS | LEFT |  UP  | DOWN | RIGHT|      |-------.    ,-------|      |      | Ins  | Home | PgUp | Bspc |
 * |------+------+------+------+------+------| TRNS   |   | TRNS  |------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |-------|    |-------|      |      | Del  | End  | PgDn | TRNS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS |QWERTY| TRNS |     |  /Enter  /       \Space \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMB] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                         KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  KC_PSCR, KC_SLCT, KC_PAUS, KC_F12, \
  _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, XXXXXXX,                       XXXXXXX,  XXXXXXX,  KC_INS,  KC_HOME, KC_PGUP, KC_BSPC, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,    _______, XXXXXXX,  XXXXXXX,  KC_DEL,  KC_END,  KC_PGDN, _______, \
        _______, TO(_QWERTY), _______, _______, KC_ENT,                      KC_SPC, _______, _______, _______, _______ \
),
};

#ifdef OLED_ENABLE

const char* get_setting_identifier(int sel) {
  switch (sel) {
  case BRIGHTNESS: return "brightness";
  case VOLUME: return "volume";
  case SHUTDOWN: return "shutdown";
  case SUSPEND: return "suspend";
  case MUSIC: return "music";
  case PAGE: return "page";
  case SYSRQ: return "SysRq";
  default: return "default??";
  }

}

const char* get_magic_identifier(int sel) {
  switch (sel) {
  case R:
    return "R - unraw";
  case E:
    return "E - TERM";
  case I:
    return "I - KILL";
  case S:
    return "S - sync";
  case U:
    return "U - remount";
  case B:
    return "B - reboot";
  case F:
    return "F - OOM";
  case O:
    return "O - off";
  default:
    return "default??";
  }

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

static void print_menu(void) {
  for (
       int i = (selected_menu + SETTING_LENGTH-1) % SETTING_LENGTH; // start at the currently selected menu minus one (i.e. the previous item)
       i != ((selected_menu+oled_max_lines()-1) % SETTING_LENGTH); // until we have advanced so many items, that one line on the OLED stays free
       i = (i+1) % SETTING_LENGTH // each step, increment i (the displayed item), wrapping around
   ) {
    if (i == selected_menu) { // the selected item should be highlighted
      char dest[oled_max_chars()];
      dest[0] = '\0';
      strncat(dest, " ", oled_max_chars()-1); // padding/indentation for selected option
      oled_write_ln(strncat(dest, get_setting_identifier(i), oled_max_chars()-1), true);
    } else {
      oled_write_ln(get_setting_identifier(i), false);
    }
  }

  if (selected_menu == SYSRQ) {
    int row = 0;
    for (
         int i = (selected_sysrq + SYSRQ_LENGTH-1) % SYSRQ_LENGTH;
         i != ((selected_sysrq+oled_max_lines()-1) % SYSRQ_LENGTH);
         i = (i+1) % SYSRQ_LENGTH
     ) {
      oled_set_cursor(oled_max_chars()-12, row++); // start writing again at the top, but next to the other menu
      if (i == selected_sysrq) {
        char dest[oled_max_chars()];
        dest[0] = '\0';
        /* strncat(dest, " ", oled_max_chars()-1); // padding/indentation for selected option */
        oled_write_ln(strncat(dest, get_magic_identifier(i), oled_max_chars()-1), true);
      } else {
        oled_write_ln(get_magic_identifier(i), false);
      }
    }
  }
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    print_menu();
  } else {
    print_status_narrow();
  }
  return false;
}

#endif

void run_sysrq(int sel) {
  register_code(KC_LALT);
  register_code(KC_PSCR);
  switch (sel) {
  case R:
    register_code(KC_R);
    break;
  case E:
    register_code(KC_E);
    break;
  case I:
    register_code(KC_I);
    break;
  case S:
    register_code(KC_S);
    break;
  case U:
    register_code(KC_U);
    break;
  case B:
    register_code(KC_B);
    break;
  case F:
    register_code(KC_F);
    break;
  case O:
    register_code(KC_O);
    break;
  default:
    clear_keyboard();
  }
  clear_keyboard();

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_OSCT: {
    switch (selected_menu) {
    case BRIGHTNESS: break;
    case VOLUME: if (record->event.pressed) tap_code(KC_MUTE); return true;
    case SHUTDOWN: if (record->event.pressed) tap_code(KC_PWR); oled_off(); return true;
    case SUSPEND: if (record->event.pressed) tap_code(KC_SLEP); oled_off(); return true;
    case MUSIC: if (record->event.pressed) tap_code(KC_MPLY); return true;
    case SYSRQ: if (record->event.pressed) run_sysrq(selected_sysrq); return true;
    case PAGE: break;
    default: break;
    }
  }
  default: return true;

  }
  return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (!clockwise) {
      selected_menu = (selected_menu+1) % SETTING_LENGTH;
    } else {
      selected_menu = (selected_menu + SETTING_LENGTH-1) % SETTING_LENGTH;
    }
  } else if (index == 1) {
    switch (selected_menu) {
    case BRIGHTNESS: if (clockwise) tap_code(KC_BRIU); else tap_code(KC_BRID); break;
    case VOLUME: if (clockwise) tap_code(KC_VOLU); else tap_code(KC_VOLD); break;
    case SHUTDOWN: break;
    case SUSPEND: break;
    case MUSIC: if (clockwise) tap_code(KC_MNXT); else tap_code(KC_MPRV); break;
    case PAGE: if (clockwise) tap_code(KC_PGDN); else tap_code(KC_PGUP); break;
    case SYSRQ: if (clockwise) selected_sysrq = (selected_sysrq+1) % SYSRQ_LENGTH; else selected_sysrq = (selected_sysrq + SYSRQ_LENGTH-1) % SYSRQ_LENGTH; break;
    default: break;
    }
  }
  return false;
}

#endif
