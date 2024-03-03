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

enum torn_layers { _QWERTY, _SYST, _SYMB, _MOUS, _ITAL, _NUMB, _CURS};

#define S_BSPC LSFT_T(KC_BSPC)
#define R_DEL LT(_RAISE, KC_DEL)
#define G_ENT LGUI_T(KC_ENT)
#define L_SPC LT(_LOWER, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | `    |   Q  |   W  |LGT(E)|   R  |   T  |    |   Y  |   U  |RGT(I)|   O  |   P  |  [   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | -    |   A  |LAT(S)|LCT(D)|LST(F)|   G  |    |   H  |RST(J)|RCT(K)|RAT(L)|   ;  |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | =    |   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               |  <-  | ESC  | Bksp | Del  |    |Enter |Space | TAB  |  ->  |
 *               |System|Cursor|      |Number|    |Symbol|      |Ita   |Mouse |
 *               `---------------------------'    `---------------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_4(
     KC_GRV,    KC_Q,           KC_W,     LGUI_T(KC_E),         KC_R,             KC_T,     /**/                KC_Y,             KC_U,     RGUI_T(KC_I),         KC_O,       KC_P,     KC_LBRC,
    KC_MINS,    KC_A,   LALT_T(KC_S),     LCTL_T(KC_D), LSFT_T(KC_F),             KC_G,     /**/                KC_H,    KRSFT_T(KC_J),     RCTL_T(KC_K), RALT_T(KC_L),    KC_SCLN,     KC_QUOT,
     KC_EQL,    KC_Z,           KC_X,             KC_C,         KC_V,             KC_B,     /**/                KC_N,             KC_M,          KC_COMM,       KC_DOT,    KC_SLSH,     KC_RBRC,
                   LT(_SYST,KC_LEFT), LT(_CURS,KC_ESC),       S_BSPC, LT(_NUMB,KC_DEL),     /**/     LT(_NUMB,G_ENT),            L_SPC, LT(_ITAL,KC_TAB), LT(_MOUS,KC_RGHT)
),

/* Number //TODO shift all keys on the left, one key to the left
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |      |   M  | Gui  |   <  |   >  |    | Enter|   7  |   8  |   9  |   :  |   K  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |   x  |LAT(d)|LCT(e)|LST(f)|    | Tab  |   4  |   5  |   6  |   -  |   j  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |   T  |  a   |  b   |   c  |    | Space|   1  |   2  |   3  |   /  |   G  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | ____ | ____ | ____ |    |   .  |   0  |   ,  | ____ |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_LOWER] = LAYOUT_split_3x6_4(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PMNS,
    KC_UNDS, _______, _______, _______, _______, _______,   _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_PPLS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Raise
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |    |      |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |    | Home | Left | Down | Right| End  | PgUp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |    |      |      |      |      |      | PgDn |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_RAISE] = LAYOUT_split_3x6_4(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     _______, S(A(KC_LEFT)), KC_UP, S(A(KC_RGHT)), _______, _______,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGUP,
    _______, KC_F11,  KC_F12,  _______, _______, _______,   A(KC_BSPC), A(KC_LEFT), S(KC_DOWN), A(KC_RGHT), _______, KC_PGDN ,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_ADJUST] = LAYOUT_split_3x6_4(
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [_QWERTY] =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_PGDN,      KC_PGUP } },
    [_LOWER]  =  { { C(KC_LEFT),   C(KC_RGHT) },    { KC_VOLD,      KC_VOLU } },
    [_RAISE]  =  { { KC_TRNS,      KC_TRNS },       { G(KC_TAB),    G(S(KC_TAB)) } },
    [_ADJUST] =  { { KC_TRNS,      KC_TRNS },       { KC_TRNS,      KC_TRNS } },
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _RAISE));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _LOWER));
    return state;
}
