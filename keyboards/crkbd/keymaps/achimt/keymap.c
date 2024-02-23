// Copyright 2022 Mark Stosberg (@markstos)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
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

//ctrl-a in sudoku layersd
// For _NAV layer
#define CTL_ESC  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  TG(_SUDOKU),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         DE_Z,    KC_U,    KC_I,    KC_O,    KC_P, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, DE_ODIA, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_NUM),MO(_NAV),  KC_SPC,     KC_ENT,MO(_SYM),MO(_FUNC)
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), DE_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      DE_LABK, DE_LPRN, DE_LCBR, DE_LBRC, DE_PLUS, DE_HASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_CIRC, XXXXXXX, DE_SLSH, DE_PIPE, DE_BSLS,                      DE_RABK, DE_RPRN, DE_RCBR, DE_RBRC, DE_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX  ,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_ESC,A(KC_LEFT),C(KC_F),A(KC_RGHT),KC_INS,                     KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(DE_Z), C(KC_X), C(KC_C), KC_LGUI, C(KC_V),                       QK_REP, KC_BSPC,  KC_TAB,  KC_APP, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      AS_TOGG,  AS_UP,  AS_DOWN,  AS_RPT, XXXXXXX, XXXXXXX,                      KC_F12,    KC_F7,   KC_F8,   KC_F9, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+ -------|--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      KC_F11,    KC_F4,   KC_F5,   KC_F6, KC_SCRL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+ -------|--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F10,    KC_F1,   KC_F2,   KC_F3, KC_PAUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, DE_SLSH, DE_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      XXXXXXX,    KC_4,    KC_5,    KC_6, DE_MINS, DE_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3,  DE_DOT, DE_COLN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX, KC_0, DE_COMM
                                      //`--------------------------'  `--------------------------'
  ),
  [_SUDOKU] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  TG(_SUDOKU), XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
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

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case DE_ODIA:
        case DE_UDIA:
        case DE_ADIA:
            return true;
        default:
            return false;
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
        case _FUNC:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
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

// void render_led_number(void){
//   oled_write_ln_P(PSTR(""), false);
//   oled_write_P(PSTR("LED: "), false);
//   oled_write_P(PSTR(current_led + 1), false);
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        render_mod_status(get_mods());
        // render_led_number();
    } else {
        
    }
    return false;
}
#endif // OLED_ENABLE


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

        rgb_matrix_set_color_all(0, 0, 0);
    // // Get the current time
    // uint32_t now = timer_read();

    //     // Turn off all LEDs

    //     // Turn on the current LED
    //     rgb_matrix_set_color(current_led, 0, 0, 255);
    // // Check if it's been at least 1000 milliseconds since the last update
    // if (now - last_update_time >= 1000) {

    //     // Update the time of the last update
    //     last_update_time = now;

    //     // Move to the next LED, wrapping around if necessary
    //     current_led = (current_led + 1);
    // }

    return false;
}