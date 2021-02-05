// vim:colorcolumn=4,13,22,31,40,49,58,67,76,85,94,103,112,121
/*
 * Copyright 2020 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2020 Anthony MARIN <anthony@hidtech.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
  _QWR,
  _LWR,
  _RSE
};

#define      CTL_ESC  CTL_T(KC_ESC)
#define      CTL_TAB  CTL_T(KC_TAB)
#define      OSM_SFT  OSM(MOD_LSFT)
#define      RSE_SCLN LT(_RSE, KC_SCLN)
#define      RSE_ESC  LT(_RSE, KC_ESC)
#define      LWR_ESC  LT(_LWR, KC_ESC)

#define      RAISE    MO(_RSE)
#define      LOWER    MO(_LWR)

#define      UNDO     C(KC_Z)
#define      REDO     C(S(KC_Z))
#define      CUT      C(KC_X)
#define      COPY     C(KC_C)
#define      PASTE    C(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWR] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    RSE_SCLN,KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                               LWR_ESC, KC_SPC,  OSM_SFT,          KC_BSPC, KC_ENT,  RAISE,
                                        KC_LGUI, CTL_TAB,          KC_RALT, KC_RALT
  ),
  [_LWR] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV, 	       KC_MINS, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,          KC_UNDS, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR,          KC_0,    KC_1,    KC_2,    KC_3,    KC_ASTR, _______,
                               _______, _______, _______,          _______, _______, _______,
                                        _______, _______,          _______, _______
  ),
  [_RSE] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, _______,          KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,REDO,    KC_F12,
    _______, KC_BRID, KC_MPRV, KC_MPLY, KC_MNXT, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_DEL,
                               _______, _______, _______,          _______, _______, _______,
                                        _______, _______,          _______, _______
  ),
};
