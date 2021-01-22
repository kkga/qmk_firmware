// Copyright 2021 Gadzhi Kharkharov

#include QMK_KEYBOARD_H

enum layers {
  _DEF,
  _SYM,
  _NAV,
  _FNC
};

enum {
  TD_SCLN_CLN,
  TD_QUO_DQUO
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_QUO_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
};

#define SFT_Z SFT_T(KC_Z)
#define SFT_SLSH SFT_T(KC_SLSH)
#define NAV_ESC LT(_NAV, KC_ESC)
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define SCL_CL TD(TD_SCLN_CLN)
#define QUO_DQUO TD(TD_QUO_DQUO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  ,--------------------------------------------.                  ,--------------------------------------------.
  |   q    |   w    |   e    |   r    |   t    |                  |   y    |   u    |   i    |   o    |   p    |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |   a    |   s    |   d    |   f    |   g    |                  |   h    |   j    |   k    |   l    |  ;_:   |
  |--------+--------+--------+--------+--------+--------,,--------+--------+--------+--------+--------+--------|
  | Sft/z  |   x    |   c    |   v    |   b    |  Tab   ||        |   n    |   m    |   ,    |   .    | Sft//  |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  | NAV/Esc|  Tab   |  Alt   |  Sup   |  Spc   |  Ctl   ||  Alt   |  BkSp  |  SYM   |        |  '_"   |  Ent   |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_DEF] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,     KC_K,    KC_L,    SCL_CL,
    SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,  _______, KC_N,    KC_M,     KC_COMM, KC_DOT,  SFT_SLSH,
    NAV_ESC, KC_TAB,  KC_LALT, KC_LGUI, KC_SPC,  KC_LCTL, KC_LALT, KC_BSPC, MO(_SYM), _______, QUO_DQUO,KC_ENT ),

  /* Symbols and numbers
  ,--------------------------------------------.                  ,--------------------------------------------.
  |   !    |   @    |   {    |   }    |   `    |                  |   _    |   7    |   8    |   9    |   +    |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |   #    |   $    |   (    |   )    |   ~    |                  |   -    |   4    |   5    |   6    |   =    |
  |--------+--------+--------+--------+--------+--------,,--------+--------+--------+--------+--------+--------|
  |   %    |   ^    |   [    |   ]    |   &    |        ||        |   |    |   1    |   2    |   3    |   \    |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  |        |        |        |        |        |        ||        |        |  XXXX  |   0    |   .    |        |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_SYM] = LAYOUT(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,                    KC_UNDS, KC_7,     KC_8,    KC_9,    KC_PLUS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                   KC_MINS, KC_4,     KC_5,    KC_6,    KC_EQL,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR, _______, _______, KC_PIPE, KC_1,     KC_2,    KC_3,    KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,  KC_0,    KC_DOT,  _______),

  /* Navigation and system
  ,--------------------------------------------.                  ,--------------------------------------------.
  | RESET  |  Vol-  |  Mute  |  Vol   |  Bri+  |                  |  Caps  |  Undo  |  Cut   |  Copy  | Paste  |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |   #    |  Prev  |  Play  |  Next  |  Bri-  |                  |  Left  |  Down  |   Up   | Right  |  Ins   |
  |--------+--------+--------+--------+--------+--------,,--------+--------+--------+--------+--------+--------|
  |  Sft   |        |        |        |        |        ||        |  Home  |  PgDn  |  PgUp  |  End   |  Del   |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  |  XXXX  |        |        |        |        |        ||        |        |        |        |        |        |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_NAV] = LAYOUT(
    RESET,   KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU,                   KC_CAPS, UNDO,     CUT,     COPY,    PASTE,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID,                   KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_INS,
    KC_LSFT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,  KC_DEL,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______)
};
