// vim:colorcolumn=4,13,22,31,40,49,58,67,76,85,94,103,112,121
/* Copyright 2021 Gadzhi KHARKHAROV <me@kkga.me> */

#include QMK_KEYBOARD_H

enum layers {
  _BSE,
  _LWR,
  _RSE
};

#define      CTL_ESC  CTL_T(KC_ESC)
#define      GUI_ESC  GUI_T(KC_ESC)
#define      GUI_DEL  GUI_T(KC_DEL)
#define      CTL_TAB  CTL_T(KC_TAB)
#define      CTL_SPC  CTL_T(KC_SPC)
#define      ALT_TAB  ALT_T(KC_TAB)
#define      GUI_TAB  GUI_T(KC_TAB)
#define      OSM_SFT  OSM(MOD_LSFT)

// bottom row mods
#define      CTL_Z    CTL_T(KC_Z)
#define      ALT_X    ALT_T(KC_X)
#define      GUI_C    GUI_T(KC_C)
#define      SFT_BSLS SFT_T(KC_BSLS)
#define      CTL_SLSH CTL_T(KC_SLSH)
#define      ALT_DOT  ALT_T(KC_DOT)
#define      GUI_COMM GUI_T(KC_COMM)

#define      RAISE    MO(_RSE)
#define      LOWER    MO(_LWR)
#define      ADJUST   MO(_ADJ)
#define      OSL_LWR  OSL(_LWR)
#define      RSE_ESC  LT(_RSE, KC_ESC)
#define      RSE_TAB  LT(_RSE, KC_TAB)
#define      RSE_BSP  LT(_RSE, KC_BSPC)
#define      LWR_ESC  LT(_LWR, KC_ESC)
#define      LWR_DEL  LT(_LWR, KC_DEL)
#define      LWR_BSP  LT(_LWR, KC_BSPC)

#define      SFT_SPC  SFT_T(KC_SPC)
#define      SFT_ENT  SFT_T(KC_ENT)

#define      C_LEFT   C(KC_LEFT)
#define      C_RGHT   C(KC_RGHT)
#define      C_UP     C(KC_UP)
#define      C_DOWN   C(KC_DOWN)
#define      C_BSPC   C(KC_BSPC)

#define      UNDO     C(KC_Z)
#define      CUT      C(KC_X)
#define      COPY     C(KC_C)
#define      PASTE    C(KC_V)
#define      REDO     C(S(KC_Z))

  /* Keyboard layout
   ,-----------------------------------------------------.        ,-----------------------------------------------------.
   |        |        |        |        |        |        |        |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |        |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |        |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |        |        |        |        |        |        |        |
   '--------------------------+--------+--------+--------|        |--------+--------+--------+--------------------------'
                              |        |        |        |        |        |        |        |
                              '--------+--------+--------|        |--------+--------+--------'
                                       |        |        |        |        |        |
                                       '--------+--------'        '--------+--------'                                   */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE: Qwerty
   ,-----------------------------------------------------.        ,-----------------------------------------------------.
   |   `    |   1    |   2    |   3    |   4    |   5    |        |   6    |   7    |   8    |   9    |   0    |  Bspc  |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |  Tab   |   q    |   w    |   e    |   r    |   t    |        |   y    |   u    |   i    |   o    |   p    |   \    |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |Ctl-Esc |   a    |   s    |   d    |   f    |   g    |        |   h    |   j    |   k    |   l    |   ;    |   '    |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |OSM_Sft |   z    |   x    |   c    |   v    |   b    |        |   n    |   m    |   ,    |   .    |   /    |OSM_Sft |
   '--------------------------+--------+--------+--------|        |--------+--------+--------+--------------------------'
                              |Gui/Esc |  Spc   |Alt/Tab |        |  Alt   |  Ent   |  Bspc  |
                              '--------+--------+--------|        |--------+--------+--------'
                                       | LOWER  |  Ctl   |        | RAISE  | LOWER  |
                                       '--------+--------'        '--------+--------'                                    */
  [_BSE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    OSM_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_SFT,
                               GUI_ESC, KC_SPC,  ALT_TAB,          KC_LALT, KC_ENT,  KC_BSPC,
                                        OSL_LWR, KC_LCTL,          RAISE,   OSL_LWR
  ),

  /* LOWER: Symbols + Arrows
   ,-----------------------------------------------------.        ,-----------------------------------------------------.
   |   ~    |   !    |   @    |   #    |   $    |   %    |        |   ^    |   &    |   *    |   (    |   )    |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |   {    |  PgUp  |   ↑    |  PgDn  |   }    |        |        |   -    |   +    |   _    |   =    |   |    |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |   (    |   ←    |   ↓    |   →    |   )    |        |   ←    |   ↓    |   ↑    |   →    |   :    |   "    |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |   [    |  Home  |        |  End   |   ]    |        |        |        |   <    |   >    |   ?    |        |
   '--------------------------+--------+--------+--------|        |--------+--------+--------+--------------------------'
                              |        |        |        |        |        |        |        |
                              '--------+--------+--------|        |--------+--------+--------'
                                       |        |        |        |        |        |
                                       '--------+--------'        '--------+--------'                                   */
  [_LWR] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_LCBR, KC_PGUP, KC_UP,   KC_PGDN, KC_RCBR,	       _______, KC_MINS, KC_PLUS, KC_UNDS, KC_EQL,  KC_PIPE,
    _______, KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQUO,
    _______, KC_LBRC, KC_HOME, _______, KC_END,  KC_RBRC,          _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
                               _______, _______, _______,          _______, _______, _______,
                                        _______, _______,          _______, _______
  ),

  /* RAISE: System and extra navigation
   ,-----------------------------------------------------.        ,-----------------------------------------------------.
   | RESET  |   F1   |   F2   |   F3   |   F4   |   F5   |        |   F6   |   F7   |   F8   |   F9   |  F10   |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |  F11   |  Vol-  |  Mute  |  Vol+  |  Bri+  |        |  Ctl←  |  Ctl↓  |  Ctl↑  |  Ctl→  |Ctl Bsp |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |  F12   |  Prev  |  Play  |  Next  |  Bri-  |        |   ←    |   ↓    |   ↑    |   →    |  Ins   |        |
   |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
   |        |  Undo  |  Cut   |  Copy  | Paste  |  Redo  |        |  Home  |  PgDn  |  PgUp  |  End   |  Del   |        |
   '--------------------------+--------+--------+--------|        |--------+--------+--------+--------------------------'
                              |        |        |        |        |        |        |        |
                              '--------+--------+--------|        |--------+--------+--------'
                                       |        |        |        |        |        |
                                       '--------+--------'        '--------+--------'                                   */
  [_RSE] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU,          C_LEFT,  C_DOWN,  C_UP,    C_RGHT,  C_BSPC,  _______,
    _______, KC_F12,  KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
    _______, UNDO,    CUT,     COPY,    PASTE,   REDO,             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  _______,
                               _______, _______, _______,          _______, _______, _______,
                                        _______, _______,          _______, _______ 
  ),
};
