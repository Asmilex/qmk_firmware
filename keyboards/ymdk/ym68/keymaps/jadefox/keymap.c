/* Copyright 2019 REPLACE_WITH_YOUR_NAME
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

#define LT1_CAP     LT(1, KC_CAPS)
#define LT2_APP     LT(2, KC_APP)

enum custom_keycodes {
    EM_DASH = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC, KC_DEL,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,       KC_PGUP,
        LT1_CAP,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,        KC_PGDN,
        KC_LSPO,   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,        KC_UP,    MO(1),
        KC_LCTL, KC_LGUI,  KC_LALT,                       KC_SPC,                              KC_RALT, KC_RGUI, LT2_APP, KC_LEFT, KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT_all(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  KC_INS,
        _______,     KC_MPRV,   KC_MPLY,   KC_MNXT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME,
        _______,       KC_MUTE,   KC_VOLD,   KC_VOLU,   _______, _______, _______, _______, _______, KC_LOCK, _______, _______, _______,        KC_END,
        _______,   _______, _______,   _______,   _______,   _______, _______, _______, _______, _______, _______, _______, KC_BTN1,  KC_MS_U,  KC_BTN3,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, KC_MS_L, KC_MS_D,  KC_MS_R
    ),
    [2] = LAYOUT_all(
        QK_BOOT,      KC_P7,    KC_P8,   KC_P9,   KC_PPLS,   _______,   _______,   _______,   _______,   _______,   _______,  EM_DASH, _______,  _______, _______, _______,
        _______,        KC_P4,    KC_P5,   KC_P6,   KC_PMNS,   _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,
        _______,          KC_P1,    KC_P2,   KC_P3,   KC_PAST,   _______, _______, _______, _______, _______, _______, _______, _______,             _______,
        KC_PENT,   _______, KC_PCMM,  KC_P0,  KC_PDOT,  KC_PSLS,   _______, _______, _______, _______, _______, _______, _______,        _______, _______,
        KC_NUM_LOCK,  _______,   _______,                      _______,                              _______, _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EM_DASH:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));  // Alt + 0151; Windows only
            }
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT1_CAP:
            return 130;
        case KC_LSPO:
            return 130;
        case KC_RSPC:
            return 130;
        default:
            return TAPPING_TERM;
    }
}
