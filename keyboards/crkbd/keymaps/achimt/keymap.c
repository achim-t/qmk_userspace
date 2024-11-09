// Copyright 2022 Mark Stosberg (@markstos)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "features/flow.h"
#include "features/layer_lock.h"

enum custom_keycodes {
  OS_FUNC = SAFE_RANGE,
  LLOCK,
};


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _COLEMAK,
  _GAMING,
  _SYM,
  _NAV,
  _FUNC,
  _NUM,
  _SUDOKU,
};

// For _QWERTY layer
#define OSM_CTL  OSM(MOD_LCTL)
#define OSM_AGR  OSM(MOD_RALT)
#define OSM_SFT  OSM(MOD_LSFT) 
#define OSM_ALT  OSM(MOD_LALT) 
#define OSM_GUI  OSM(MOD_LGUI) 

// For _NAV layer
#define CTL_ESC  LCTL_T(KC_ESC)

#ifdef RGB_MATRIX_ENABLE
    #define ___off___	{0,0,0}
    #define MG__WHITE	{255,255,255}
    #define	MG____RED	{255,0,0}
    #define MG__GREEN	{32,159,33}
    #define MG___BLUE	{0,181,213}
    #define MG_YELLOW	{255,208,0}
    #define MG_ORANGE	{255,85,0}
    #define MG___PINK	{208,0,255}
    #define MG_PURPLE	{50,0,232}
#endif

const uint16_t flow_config[FLOW_COUNT][2] = {
    {MO(_NAV), KC_LALT},
    {MO(_NAV), KC_LGUI},
    {MO(_NAV), KC_LCTL},
    {MO(_NAV), KC_RALT},
    {MO(_NAV), KC_LSFT},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_FUNC, _FUNC},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         DE_Z,    KC_U,    KC_I,    KC_O,    KC_P, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, DE_ODIA, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, DE_MINS,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_NUM),MO(_NAV), KC_LSFT,     KC_SPC,MO(_SYM),MO(_FUNC)
                                      //`--------------------------'  `--------------------------'
  ),
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    DE_Y, DE_ADIA, DE_ODIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    DE_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT,   DE_SS, DE_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_NUM),MO(_NAV), KC_LSFT,     KC_SPC,MO(_SYM),MO(_FUNC)
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_C,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Q,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_I,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LALT, KC_LSFT,    KC_SPC,MO(_SYM),MO(_FUNC)
                                      //`--------------------------'  `--------------------------'
    ),
  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), DE_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_RALT,                      DE_LABK, DE_LPRN, DE_LCBR, DE_LBRC, DE_PLUS, DE_HASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_CIRC, DE_ASTR, DE_SLSH, DE_PIPE, DE_BSLS,                      DE_RABK, DE_RPRN, DE_RCBR, DE_RBRC, DE_SCLN, DE_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK,  KC_ESC,A(KC_LEFT),C(KC_F),A(KC_RGHT),C(KC_D),                      QK_REP, KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_RALT,                       KC_INS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(DE_Z), C(KC_X), C(KC_C), C(KC_V), C(DE_Y),                       KC_DEL, KC_BSPC,  KC_TAB,  KC_APP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT, XXXXXXX,XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F12,    KC_F7,   KC_F8,   KC_F9, KC_PSCR, DF(_COLEMAK),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+ -------|--------|
      _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_RALT,                      KC_F11,    KC_F4,   KC_F5,   KC_F6, KC_SCRL, DF(_QWERTY),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+ -------|--------|
      DF(_GAMING), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F10,    KC_F1,   KC_F2,   KC_F3, KC_PAUS, TG(_SUDOKU),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      XXXXXXX,    KC_7,    KC_8,    KC_9, DE_SLSH, DE_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_RALT,                      XXXXXXX,    KC_4,    KC_5,    KC_6, DE_MINS, DE_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3,  DE_DOT, DE_COLN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX, KC_0, DE_COMM
                                      //`--------------------------'  `--------------------------'
  ),
  [_SUDOKU] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  TG(_SUDOKU), C(KC_A),    KC_7,    KC_8,    KC_9, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_DEL,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,    KC_0, KC_LCTL,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )

};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

    // static uint8_t current_led = 0;
    // static uint32_t last_update_time = 0;
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLEMAK"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _SUDOKU:
            oled_write_ln_P(PSTR("SUDOKU"), false);
            break;
    }
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR(""), false);
    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}
    static uint8_t current_led = 0;
void render_led_number(void){
  oled_write_ln_P(PSTR(""), false);
  oled_write_P(PSTR("LED: "), false);
  oled_write(get_u8_str(current_led, '0'), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        render_mod_status(get_mods());
        // render_led_number();
    } else {
        render_led_number();
    }
    return false;
}
#endif // OLED_ENABLE

#ifdef RGB_MATRIX_ENABLE

// const uint8_t PROGMEM ledmap[][42][3] = {
// /* Starts at layer 1; we don't apply lights to Base (layer 0). */
// [_NAV] = {
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// 								 ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___
// 			},
// [_NUM] = {
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// 						   		 ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___
// 			},
// [_FUNC] = {
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// 						   		 ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___
// 			},
// [_SYM] = {
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// ___off___, ___off___, ___off___, ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// 						   		 ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___
// 			},
// [_SUDOKU] = {
// ___off___, ___off___, MG____RED, MG____RED, MG____RED, ___off___, 				___off___, ___off___, MG__WHITE, ___off___, ___off___, ___off___,
// ___off___, ___off___, MG____RED, MG____RED, MG____RED, ___off___, 				___off___, MG__WHITE, MG__WHITE, MG__WHITE, ___off___, ___off___,
// ___off___, ___off___, MG____RED, MG____RED, MG____RED, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
// 						   		 ___off___, ___off___, ___off___, 				___off___, ___off___, ___off___
// 			},
// };

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // (180, 255, 231) is purple
    rgb_matrix_mode_noeeprom(1);
}

// ====================================================
// RGB matrix
// ====================================================

uint8_t ledIndexForKeymapIndex(uint8_t keyIndex) {
	// Turn keyIndex into a row and column within g_led_config.
	// Reference: https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/r2g/r2g.c
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t keysPerRow = 12; // Specific to crkdb!
	uint8_t keysPerHalf = keysPerRow / 2; // Assumes equal split!

	row = keyIndex / keysPerRow;
	col = keyIndex % keysPerRow;
	if (row == 3) { // Specific to crkbd!
		col += 3; // Compensate for leading three NO_LED entries in g_led_config.
	}

	bool mirror = (col >= keysPerHalf);
	if (mirror) {
		// Normalise row and col per g_led_config structure.
		row += 4;
		col -= keysPerHalf;
		// Mirror column position.
		col = (keysPerHalf - 1) - col;
	}

	return g_led_config.matrix_co[row][col];
}

void my_set_led(uint8_t layer, uint8_t keyIndex, uint8_t led_min, uint8_t led_max) {
        uint8_t ledIndex = ledIndexForKeymapIndex(keyIndex);
    if (ledIndex >= led_min && ledIndex <= led_max) {
        if (is_layer_locked(layer)) {
            RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, 255, 0, 0);
        } else {
            RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, 0, 0, 0);
        }
    }
}

    // static uint32_t last_update_time = 0;
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // uint8_t layerNum = get_highest_layer(layer_state);
    // if (layerNum == 0) {
    //     rgb_matrix_set_color_all(0, 0, 0);
    //     return false;
    // }

    // // Per-key indicators
    // uint8_t ledIndex = 0;
    // uint8_t r, g, b;
    // for (uint8_t keyIndex = 0; keyIndex < 42; keyIndex++) { // 0 to 42
    //     ledIndex = ledIndexForKeymapIndex(keyIndex);

    //     if (ledIndex >= led_min && ledIndex <= led_max) {
    //         r = pgm_read_byte(&ledmap[layerNum][keyIndex][0]);
    //         g = pgm_read_byte(&ledmap[layerNum][keyIndex][1]);
    //         b = pgm_read_byte(&ledmap[layerNum][keyIndex][2]);

    //         if (!r && !g && !b) {
    //             RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, 0, 0, 0);
    //         } else {
    //             RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, r, g, b);
    //         }
    //     }
    // }
    // my_set_led(_NUM, 41, led_min, led_max);

    my_set_led(_NAV, 37, led_min, led_max);
    if (is_layer_locked(_NUM)) {
            RGB_MATRIX_INDICATOR_SET_COLOR(ledIndexForKeymapIndex(39), 255, 0, 0);
        } else {
            RGB_MATRIX_INDICATOR_SET_COLOR(ledIndexForKeymapIndex(39), 0, 0, 0);
        }
    // my_set_led(_SYM, 40, led_min, led_max);
    // my_set_led(_NAV, 36, led_min, led_max);
    // my_set_led(_FUNC, 41, led_min, led_max);

    // uint32_t now = timer_read();
    // RGB_MATRIX_INDICATOR_SET_COLOR(ledIndexForKeymapIndex(current_led), 0, 0, 0);
    // if (now - last_update_time >= 1000) {
    //     last_update_time = now;
    //     current_led = (current_led + 1) % 42;
    // }
    // RGB_MATRIX_INDICATOR_SET_COLOR(ledIndexForKeymapIndex(current_led), 255, 0, 0);

    return false;
}


#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false; 
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

void layer_lock_set_user(layer_state_t locked_layers) {
  // Do something like `set_led(is_layer_locked(NAV));`
}
