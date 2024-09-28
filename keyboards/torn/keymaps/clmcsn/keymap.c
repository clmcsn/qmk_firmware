/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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

enum torn_layers { _QWERTY, _SYST, _SYMB, _NUMB};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//TODO
//arrow
//round brackets
//caps lock
//dollar, @, etc
//make json

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  `   |   Q  |   W  |LGT(E)|   R  |   T  |    |   Y  |   U  |RGT(I)|   O  |   P  |  [   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  _   |   A  |LAT(S)|LCT(D)|LST(F)|   G  |    |   H  |RST(J)|RCT(K)|RAT(L)|   ;  |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  =   |   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               |  <-  | ESC  | Bksp | Del  |    |Enter |Space | TAB  |  ->  |
 *               |System|Cursor|Number|      |    |Symbol|      |Ita   |Mouse |
 *               `---------------------------'    `---------------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_4(
     KC_GRV,    KC_Q,           KC_W,     LGUI_T(KC_E),         KC_R,             KC_T,     /**/                KC_Y,             KC_U,     RGUI_T(KC_I),         KC_O,       KC_P,     KC_LBRC,
    KC_UNDS,    KC_A,   LALT_T(KC_S),     LCTL_T(KC_D), LSFT_T(KC_F),             KC_G,     /**/                KC_H,    RSFT_T(KC_J),     RCTL_T(KC_K), RALT_T(KC_L),    KC_SCLN,     KC_QUOT,
     KC_EQL,    KC_Z,           KC_X,             KC_C,         KC_V,             KC_B,     /**/                KC_N,             KC_M,          KC_COMM,       KC_DOT,    KC_SLSH,     KC_RBRC,
                   LT(_SYST,KC_LEFT),      KC_ESC, LT(_NUMB,KC_BSPC), LT(_SYST,KC_DEL),     /**/     LT(_SYST,KC_ENT),LT(_SYMB,KC_SPC), LT(_SYST,KC_TAB), LT(_SYST,KC_RGHT)
),

/* Number
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  ^   |   !  |   =  |LGT(<)|   >  | Enter|    |   %  |   7  |   8  |   9  |   :  |   k  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  ~   |  Del |LAT(d)|LCT(e)|LST(f)| Tab  |    |   +  |   4  |   5  |   6  |   -  |   j  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  $   |   x  |  a   |  b   |  c   | Space|    |   *  |   1  |   2  |   3  |   /  |   G  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | ____ | ____ | xxxx |    |   .  |   0  |   ,  | Bksp |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_NUMB] = LAYOUT_split_3x6_4(
    KC_CIRC, KC_EXLM,         KC_EQL,    LGUI_T(KC_LT),        KC_GT,            KC_ENT,     /**/             KC_PERC,             KC_7,     RGUI_T(KC_8),         KC_9,    KC_COLN,     KC_K,
    KC_TILD,  KC_DEL,   LALT_T(KC_D),     LCTL_T(KC_E), LSFT_T(KC_F),            KC_TAB,     /**/              KC_PLUS,    RSFT_T(KC_4),     RCTL_T(KC_5), RALT_T(KC_6),    KC_MINS,     KC_J,
     KC_DLR,    KC_X,           KC_A,             KC_B,         KC_C,            KC_SPC,     /**/             KC_ASTR,             KC_1,             KC_2,         KC_3,    KC_SLSH,     KC_G,
                             _______,          _______,      _______,          _______,     /**/              KC_DOT,             KC_0,          KC_COMM,       KC_BSPC
),

/* Symbol
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  Tab |   {  |   '  |LGT(")|   !  |   @  |    |   ?  |   {  |   }  |   *  | Space| Enter|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |   #  |   ^  |LAT(=)|LCT(_)|LST($)| Bksp |    |  Del |   (  |   )  |   `  |   .  |   ~  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |   @  |   <  |  |   |  -   |  >   |   /  |    |   \  |   [  |   ]  |   +  |   &  |St+Tab|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               |   .  |   %  |  :   |   ;  |    | xxxx | ____ | ____ | ____ |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_SYMB] = LAYOUT_split_3x6_4(
     KC_TAB, KC_LCBR,        KC_QUOT,  LGUI_T(KC_DQUO),        KC_EXLM,          KC_AT  ,     /**/              KC_LCBR,         KC_QUES,  RGUI_T(KC_RCBR),       KC_ASTR,      KC_SPC,        KC_ENT,
    KC_HASH, KC_CIRC, LALT_T(KC_EQL),  LCTL_T(KC_UNDS), LSFT_T(KC_DLR),           KC_BSPC,     /**/              KC_DEL, RSFT_T(KC_LPRN),  RCTL_T(KC_RPRN),RALT_T(KC_GRV),     KC_DOT,      KC_TILD,
      KC_AT,   KC_LT,        KC_BSLS,          KC_MINS,          KC_GT,          KC_SLSH,     /**/             KC_BSLS,          KC_LBRC,          KC_RBRC,       KC_PLUS,    KC_AMPR, LSFT(KC_TAB),
                              KC_DOT,          KC_PERC,        KC_COLN,          KC_SCLN,     /**/             _______,          _______,          _______,       _______
),
/* System
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  F13 |  F10 |  F9  |  F8  |  F7  | PgUP |    |  End |  <<  |      |  >>  |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  F14 |  F11 |  F6  |  F5  |  F4  | Home |    | MSTP |  <<  | |>|| |  >>  |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  F15 |  F12 |  F3  |  F2  |  F1  | PgDW |    | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | xxxx | ____ | ____ | ____ |    | VOL+ | MUTE | VOL- |      |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_SYST] = LAYOUT_split_3x6_4(
     KC_F13,  KC_F10,          KC_F9,  LGUI_T(KC_F8),         KC_F7,          KC_PGUP,     /**/             KC_END , KC_MPRV, _______, KC_MNXT, _______, _______,
     KC_F14,  KC_F11,  LALT_T(KC_F6),  LCTL_T(KC_F5), LSFT_T(KC_F4),          KC_HOME,     /**/             KC_MSTP, KC_MRWD, KC_MPLY, KC_MFFD, KC_CAPS, _______,
     KC_F15,  KC_F12,          KC_F3,          KC_F2,         KC_F1,          KC_PGDN,     /**/             KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
                             _______,        _______,       _______,          _______,     /**/             KC_VOLU, KC_MUTE, KC_VOLD, _______
)

};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [_QWERTY]   =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_PGDN,      KC_PGUP } },
    [_SYST]     =  { { C(KC_LEFT),   C(KC_RGHT) },    { KC_VOLD,      KC_VOLU } },
    [_SYMB]     =  { { KC_TRNS,      KC_TRNS },       { G(KC_TAB),    G(S(KC_TAB)) } },
    [_NUMB]     =  { { KC_TRNS,      KC_TRNS },       { KC_TRNS,      KC_TRNS } },
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _SYST));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _NUMB));
    return state;
}
