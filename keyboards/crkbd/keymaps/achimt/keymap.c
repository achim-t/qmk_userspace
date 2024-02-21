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

enum combos {
  DF_DASH,
  JK_ESC
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // Add commonly used dash to home row
  [DF_DASH]    = COMBO(df_combo, KC_MINS),
  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _SYM1,
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

//TODO Modifiers for symbol layer
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
                                        MO(_FUNC),MO(_NAV),  KC_SPC,     KC_ENT,MO(_SYM1),MO(_NUM)
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), DE_ACUT,
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
      _______,  KC_ESC,LALT(KC_LEFT),LCTL(KC_F),LALT(KC_RGHT),KC_INS,            KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_CAPS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,LCTL(DE_Z),LCTL(KC_X),LCTL(KC_C),KC_LGUI,LCTL(KC_V),               KC_ENT, KC_BSPC,  KC_TAB,  KC_APP, KC_PSCR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |-------+--------+--------+--------+ -------|--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |-------+--------+--------+--------+ -------|--------|
      _______, _______, _______, _______, _______, _______,                      KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, OSM_AGR,                      _______,    KC_4,    KC_5,    KC_6, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
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