/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "wakib.h"

// clang-format off

enum layers{
  L_BASE,
  L_NUMLOCK,
  L_FN
};


enum {
    TD_ALT_ESC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ALT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_ESC),
};



#define KC_WAKB KC_WAKIB_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_ansi_98(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             KC_DEL,   KC_PSCR,  KC_WAKB,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            TG(L_NUMLOCK),  KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGUP,    KC_HOME,    KC_END,
        CW_TOGG,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGDN,    KC_UP,    KC_PAUS,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,    KC_LEFT,    KC_DOWN,    KC_RIGHT,
        KC_LCTL,  KC_LWIN,  TD(TD_ALT_ESC),                            KC_SPC,                                 KC_RALT,  MO(L_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),
    [L_NUMLOCK] = LAYOUT_ansi_98(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,              KC_P7,    KC_P8,    KC_P9,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              KC_P4,    KC_P5,    KC_P6,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,    KC_P1,    KC_P2,    KC_P3,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,    KC_P0,  _______,  _______),
    [L_FN] = LAYOUT_ansi_98(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,     KC_APP,  _______,  _______,  _______,  _______,  _______,  _______),
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [L_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [L_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [L_NUMLOCK] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_wakib(keycode, record)) {
        return false;
    }
    switch (keycode) {
    case TG(L_NUMLOCK):
        if (record->event.pressed) {
            if (layer_state_is(L_NUMLOCK)) {
                rgblight_step_reverse_noeeprom();
            } else {
                // always enable numlock when layer will become numlock
                if (!host_keyboard_led_state().num_lock) {
                    register_code(KC_NUM);
                    unregister_code(KC_NUM);
                }
                rgblight_step_noeeprom();
            }
        }
        return true;
    case KC_WAKIB_TOGGLE:
        if (record->event.pressed) {
            if (wakib_get_state()) {
                for (uint8_t i=0; i<5; i++) {
                    rgblight_increase_hue_noeeprom();
                }
            } else {
                for (uint8_t i=0; i<5; i++) {
                    rgblight_decrease_hue_noeeprom();
                }
            }
        }
        return true;
    default:
        return true;
    }
}
