/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

enum custom_keycodes {
    MUTE_MIC = SAFE_RANGE,
    EM_DASH,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define MS_WHLU KC_UP // QK_MOUSE_WHEEL_UP
#define MS_WHLD KC_DOWN // QK_MOUSE_WHEEL_DOWN
#define MS_BTN4 KC_WBAK // QK_MOUSE_BUTTON_4
#define MS_BTN5 KC_WFWD // QK_MOUSE_BUTTON_5

#define LT_CAP  LT(_FN1, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          MUTE_MIC,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PAGE_UP,
        LT_CAP,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PAGE_DOWN,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                             KC_SPC,                             MO(_FN2),  KC_RCMD, MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          MUTE_MIC,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PAGE_UP,
        LT_CAP,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PAGE_DOWN,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             MO(_FN2),  KC_RALT, MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           KC_MUTE,
        _______, KC_MPRV,  KC_MPLY,  KC_MNXT, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  KC_PSCR,          KC_HOME,
        _______, KC_VOLD,  KC_MUTE,  KC_VOLU, _______, _______, _______, _______, _______, _______, _______,  _______,             KC_INS,           KC_END,
        _______,           KC_BRID,  KC_BRIU, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, MS_WHLU,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  MS_BTN4, MS_WHLD, MS_BTN5),

    [_FN2] = LAYOUT_ansi_67(
        _______, MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5), MEH(KC_6), MEH(KC_7), MEH(KC_8), MEH(KC_9),    MEH(KC_0),    EM_DASH,      _______,      _______,      RGB_TOG,
        RGB_TOG, MEH(KC_Q), MEH(KC_W), MEH(KC_E), MEH(KC_R), MEH(KC_T), MEH(KC_Y), MEH(KC_U), MEH(KC_I), MEH(KC_O),    MEH(KC_P),    MEH(KC_LBRC), MEH(KC_RBRC), MEH(KC_BSLS), _______,
        _______, MEH(KC_A), MEH(KC_S), MEH(KC_D), MEH(KC_F), MEH(KC_G), MEH(KC_H), MEH(KC_J), MEH(KC_K), MEH(KC_L),    MEH(KC_SCLN), MEH(KC_QUOT),               _______,      _______,
        _______,            MEH(KC_Z), MEH(KC_X), MEH(KC_C), MEH(KC_V), MEH(KC_B), MEH(KC_N), MEH(KC_M), MEH(KC_COMM), MEH(KC_DOT),  MEH(KC_SLSH),               _______,      _______,
        _______, _______,   _______,                            _______,                                 _______,      KC_LWIN,      _______,      _______,      _______,      _______),

    [_FN3] = LAYOUT_ansi_67(
        QK_BOOT, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______,          _______,
        _______, KC_BTN1,  KC_MS_UP, KC_BTN2, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_MS_L,  KC_MS_D,  KC_MS_R, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MUTE_MIC:
            if (record->event.pressed) {
                add_mods(MOD_MASK_CTRL & MOD_MASK_SHIFT);
                tap_code_delay(KC_M, 10);
                del_mods(MOD_MASK_CTRL & MOD_MASK_SHIFT);
            }
            break;

        case EM_DASH:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));  // Alt + 0151; Windows only
            }
            break;
    }
    return true;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3]   = { ENCODER_CCW_CW(_______, _______)}
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_cmp(layer_state, _FN1)) {
        if (clockwise) {
            tap_code_delay(KC_RGHT, 10);
        } else {
            tap_code_delay(KC_LEFT, 10);
        }
    }
    else if (layer_state_cmp(layer_state, _FN2)) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    else {
        if (clockwise) {
            tap_code_delay(KC_UP, 10);
        } else {
            tap_code_delay(KC_DOWN, 10);
        }
    }

    return false;
}
#endif
