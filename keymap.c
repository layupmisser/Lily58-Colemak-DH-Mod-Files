#include QMK_KEYBOARD_H

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define TAPPING_TERM 200
// how long before a tap becomes a hold

enum layer_number {
  _COLEMAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  | F L2 |  P   |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | ENTER|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Space |   A  | OPT R|CTRL S| CMD T|   G  |-------.    ,-------|   M  |CMD N |CTRL E|OPT I |   O  |BACKSP|
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |tap L1|RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'              
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,        KC_1, KC_2,        KC_3,        KC_4,         KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,        KC_Q, KC_W,        LT(_RAISE),  KC_P,         KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ENT,
  KC_SPC,        KC_A, LALT_T(KC_R),LCTL_T(KC_S),LGUI_T(KC_T), KC_G,                     KC_M,    LGUI_T(KC_N),LCTL_T(KC_E),LALT_T(KC_I),    KC_O,    KC_BSPC,
  OSM(MOD_LSFT), KC_Z, KC_X,        KC_C,        KC_D,         KC_V, KC_LBRC,    KC_RBRC, KC_K,   KC_H,    KC_COMM, KC_DOT,  OSL(_LOWER),OSM(MOD_RSFT),
                                          _______ ,_______ ,_______,_______,     _______ ,_______ ,_______ , _______

),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F19 | F10  |   
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   !  |  @   |   #  |   $  |   %  |                    |  F12 | F11  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |T LCTRL|   / |   -  |   +  |   =  |  *   |-------.    ,-------|   ^  |   &  |   "  |   '  |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |T LShift|  ` |   (  |   )  |   _  |      |-------|    |-------|   |  |   {  |   }  |   \  |      |Tap Rshift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_ESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
  KC_TAB,        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_F12,  KC_F11,  _______, _______, _______, _______,
  OSM(MOD_LCTL), KC_PSLS, KC_MINS, KC_PLUS, KC_EQL,  KC_PAST,                   KC_CIRC, KC_AMPR, KC_DQUO, KC_QUOT, _______, _______,
  OSM(MOD_LSFT), KC_TILD, KC_LPRN, KC_RPRN, KC_UNDS, _______, KC_LT,     KC_GT, KC_PIPE, KC_LCBR,KC_RCBR , KC_BSLS,_______, OSM(MOD_RSFT),
                             _______, _______, _______, _______,     _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |STOP/P|SKIPB |VOLDN |VOLUP | SKIPF|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PRINT| HOME | PGDN | PGUP |  END |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| BPAGE| Left | Down |  Up  |Right |FPAGE |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
*/

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, _______, _______, _______, _______,                     KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
  _______, _______, _______, _______, _______, _______,                     KC_WBAK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_WFWD,
  _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
