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
    MUTE_MIC,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define LT_CAP  LT(_FN1, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          MUTE_MIC,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PAGE_UP,
        LT_CAP,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PAGE_DOWN,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                             KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PAGE_UP,
        LT_CAP,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PAGE_DOWN,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(_FN1), MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           KC_MUTE,
        _______, KC_MPRV,  KC_MPLY,  KC_MNXT, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          KC_HOME,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,           KC_END,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN2] = LAYOUT_ansi_67(
        _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          RGB_TOG,
        RGB_TOG, KC_BTN1, KC_MS_UP, KC_BTN2, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,  _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,  _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN3] = LAYOUT_ansi_67(
        KC_TILD, _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
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
            return false;
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
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    else if (layer_state_cmp(layer_state, _FN2)) {
        if (clockwise) {
            rgb_matrix_increase_hue();
        } else {
            rgb_matrix_decrease_hue();
        }
    }
    else {
        uint8_t mod_state = get_mods();

        if (mod_state & MOD_MASK_GUI) {
            del_mods(MOD_MASK_GUI);

            if (clockwise) {
                register_code(KC_RGHT);
            } else {
                register_code(KC_LEFT);
            }

            set_mods(mod_state);
        }
        else {
            if (clockwise) {
                tap_code_delay(KC_UP, 10);
            } else {
                tap_code_delay(KC_DOWN, 10);
            }
        }
    }

    return false;
}
#endif
