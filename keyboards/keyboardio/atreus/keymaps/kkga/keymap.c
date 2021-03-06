// Copyright 2021 Gadzhi Kharkharov

#include QMK_KEYBOARD_H

enum layers {
  _DEF,
  _SYM,
  _NAV,
  _FNC
};

enum tap_dances {
  TD_SCLN_CLN,
  TD_QUO_DQUO
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_QUO_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
};

#define   SFT_Z      SFT_T(KC_Z)
#define   CTL_X      CTL_T(KC_X)
#define   ALT_C      ALT_T(KC_C)
#define   CTL_DOT    CTL_T(KC_DOT)
#define   ALT_COMM   ALT_T(KC_COMM)
#define   SFT_SLSH   SFT_T(KC_SLSH)
#define   SFT_SPC    SFT_T(KC_SPC)
#define   CTL_TAB    CTL_T(KC_TAB)
#define   GUI_ESC    GUI_T(KC_ESC)
#define   ALT_ENT    ALT_T(KC_ENT)

#define   NAV_ESC    LT(_NAV, KC_ESC)
#define   SYM_ENT    LT(_SYM, KC_ENT)
#define   FNC_TAB    LT(_FNC, KC_TAB)

#define   UNDO       C(KC_Z)
#define   CUT        C(KC_X)
#define   COPY       C(KC_C)
#define   PASTE      C(KC_V)

#define   SCL_CL     TD(TD_SCLN_CLN)
#define   QUO_DQUO   TD(TD_QUO_DQUO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  ,--------------------------------------------.                  ,--------------------------------------------.
  |   q    |   w    |   e    |   r    |   t    |                  |   y    |   u    |   i    |   o    |   p    |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |   a    |   s    |   d    |   f    |   g    |                  |   h    |   j    |   k    |   l    |   ;    |
  |--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
  | Sft/z  |   x    |   c    |   v    |   b    |   `    ||   \    |   n    |   m    |   ,    |   .    | Sft//  |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  |NAV/Esc |FNC/Tab |  Alt   |  Gui   |  Spc   |Ctl/Tab ||Ent/Alt |  Bspc  |  SYM   |  Alt   |  Ctl   |  Ent   |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_DEF] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,
    SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,     KC_COMM, KC_DOT,  SFT_SLSH,
    NAV_ESC, FNC_TAB, KC_LALT, KC_LGUI, KC_SPC,  CTL_TAB, ALT_ENT, KC_BSPC, MO(_SYM), KC_RALT, KC_RCTL, KC_ENT ),

  /* Symbols and numbers
  ,--------------------------------------------.                  ,--------------------------------------------.
  |   1    |   2    |   3    |   4    |   5    |                  |   6    |   7    |   8    |   9    |   0    |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |   !    |   @    |   #    |   $    |   %    |                  |   ^    |   &    |   *    |   (    |   )    |
  |--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
  |   [    |   ]    |   {    |   }    |   '    |   ~    ||   |    |   "    |   -    |   +    |   _    |   =    |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  |        |        |        |        |        |        ||        |        |  XXXX  |        |        |        |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_SYM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_QUOT, KC_TILD, KC_PIPE, KC_DQUO, KC_MINS,  KC_PLUS, KC_UNDS, KC_EQL,
    _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,  _______, _______, _______),

  /* Navigation and system
  ,--------------------------------------------.                  ,--------------------------------------------.
  | RESET  |  Vol-  |  Mute  |  Vol+  |  Bri+  |                  |  Caps  |  Undo  |  Cut   |  Copy  | Paste  |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |        |  Prev  |  Play  |  Next  |  Bri-  |                  |   ←    |   ↓    |   ↑    |   →    |  Ins   |
  |--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
  |  Sft   |        |        |        |        |        ||        |  Home  |  PgDn  |  PgUp  |  End   |  Del   |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  |  XXXX  |        |        |        |        |        ||        |        |        |        |        |        |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_NAV] = LAYOUT(
    RESET,   KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU,                   KC_CAPS, UNDO,     CUT,     COPY,    PASTE,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID,                   KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_INS,
    KC_LSFT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,  KC_DEL,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______),

  /* Function
  ,--------------------------------------------.                  ,--------------------------------------------.
  |        |        |        |        |        |                  |        |   F7   |   F8   |   F9   |  F12   |
  |--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
  |        |        |        |        |        |                  |        |   F4   |   F5   |   F6   |  F11   |
  |--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
  |        |        |        |        |        |        ||        |        |   F1   |   F2   |   F3   |  F10   |
  |--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
  |        |  XXXX  |        |        |        |        ||        |        |        |        |        |        |
  `-----------------------------------------------------''-----------------------------------------------------' */
  [_FNC] = LAYOUT(
    _______, _______, _______, _______, _______,                   _______, KC_F7,    KC_F8,   KC_F9,   KC_F12,
    _______, _______, _______, _______, _______,                   _______, KC_F4,    KC_F5,   KC_F6,   KC_F11,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,    KC_F2,   KC_F3,   KC_F10,
    _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______)
};
