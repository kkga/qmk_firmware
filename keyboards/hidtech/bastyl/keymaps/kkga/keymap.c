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

#define     CTL_ESC  CTL_T(KC_ESC)

#define     RAISE    MO(_RSE)
#define     LOWER    MO(_LWR)

#define     UNDO     C(KC_Z)
#define     CUT      C(KC_X)
#define     COPY     C(KC_C)
#define     PASTE    C(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWR] = LAYOUT(
    KC_BCTK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                               RAISE,   KC_SPC,  KC_BSPC,          KC_DEL,  KC_ENT,  LOWER,
                                        KC_LGUI, OSM_SFT,          KC_RALT, KC_RGUI
  ),
  [_LWR] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    RESET,   _______, _______, _______, _______, KC_LBRC,	       KC_RBRC, KC_P7,   KC_P8,   KC_P9,   _______, KC_PLUS,
    _______, _______, _______, _______, _______, KC_LPRN,	       KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
    _______, _______, _______, _______, _______, _______,          KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_EQL,  _______,
                               _______, _______, _______,          _______, _______, XXXXXXX,
                                        _______, _______,          _______, _______,
  ),
  [_RSE] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_BRGT, KC_VOLD, KC_MUTE, KC_VOLU, _______,          UNDO,    CUT,     COPY,    PASTE,   _______, _______,
    _______, KC_BRGT, KC_PREV, KC_PLAY, KC_NEXT, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                               XXXXXXX, _______, _______,          _______, _______, _______,
                                        _______, _______,          _______, _______,
  ),
};
