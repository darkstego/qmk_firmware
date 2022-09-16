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

// clang-format off

enum layers{
  L_BASE,
  L_NUMLOCK,
  L_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_WAKIB_TOGGLE,
};


// List of Wakib Shortcuts
// All Shortcuts that use the shift modifier appear at the end of the list
// This is to ease counting through the shift modified keys to unregister them
// when the shift key is released
enum wakib_tracker_codes {
    WAKIB_BACKSPACE = 0,
    WAKIB_DELETE,
    WAKIB_WORD_BACKSPACE,
    WAKIB_WORD_DELETE,
    WAKIB_LEFT,
    WAKIB_RIGHT,
    WAKIB_UP,
    WAKIB_DOWN,
    WAKIB_WORD_LEFT,
    WAKIB_WORD_RIGHT,
    WAKIB_NEXT,
    WAKIB_PGUP,
    WAKIB_PGDOWN,
    WAKIB_TAB_PREV,
    WAKIB_TAB_NEXT,
    WAKIB_LINE_START,
    WAKIB_LINE_END,
    WAKIB_PREVIOUS,
};


#define WAKIB_KEY_COUNT 18
#define WAKIB_SHIFT_KEY_COUNT 7
bool wakib_tracker[WAKIB_KEY_COUNT] = {false};
bool wakib_state = false;

uint8_t mod_state;

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_WAKB KC_WAKIB_TOGGLE

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_ansi_98(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             KC_DEL,   KC_PSCR,  KC_WAKB,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            TG(L_NUMLOCK),  KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGUP,    KC_HOME,    KC_END,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGDN,    KC_UP,    KC_PAUS,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,    KC_LEFT,    KC_DOWN,    KC_RIGHT,
        KC_LCTL,  KC_LWIN,  LALT_T(KC_ESC),                            KC_SPC,                                 KC_RALT,  MO(L_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),
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

void register_wakib_code(uint16_t keycode){
    switch (keycode) {
    case KC_D:
        wakib_tracker[WAKIB_BACKSPACE] = true;
        register_code(KC_BSPC);
        break;
    case KC_F:
        wakib_tracker[WAKIB_DELETE] = true;
        register_code(KC_DEL);
        break;
    case KC_E:
        wakib_tracker[WAKIB_WORD_BACKSPACE] = true;
        register_code(KC_LCTL);
        register_code(KC_BSPC);
        break;
    case KC_R:
        wakib_tracker[WAKIB_WORD_DELETE] = true;
        register_code(KC_LCTL);
        register_code(KC_DEL);
        break;
    case KC_I:
        wakib_tracker[WAKIB_UP] = true;
        register_code(KC_UP);
        break;
    case KC_J:
        wakib_tracker[WAKIB_LEFT] = true;
        register_code(KC_LEFT);
        break;
    case KC_K:
        wakib_tracker[WAKIB_DOWN] = true;
        register_code(KC_DOWN);
        break;
    case KC_L:
        wakib_tracker[WAKIB_RIGHT] = true;
        register_code(KC_RIGHT);
        break;
    case KC_U:
        wakib_tracker[WAKIB_WORD_LEFT] = true;
        register_code(KC_LCTL);
        register_code(KC_LEFT);
        break;
    case KC_O:
        wakib_tracker[WAKIB_WORD_RIGHT] = true;
        register_code(KC_LCTL);
        register_code(KC_RIGHT);
        break;
    case KC_SCLN:
        wakib_tracker[WAKIB_NEXT] = true;
        register_code(KC_F3);
        break;
    }
}

void register_wakib_shift_code(uint16_t keycode){
    switch (keycode) {
    case KC_I:
        wakib_tracker[WAKIB_PGUP] = true;
        register_code(KC_PGUP);
        break;
    case KC_J:
        wakib_tracker[WAKIB_TAB_PREV] = true;
        register_code(KC_LCTL);
        register_code(KC_PGUP);
        break;
    case KC_K:
        wakib_tracker[WAKIB_PGDOWN] = true;
        register_code(KC_PGDN);
        break;
    case KC_L:
        wakib_tracker[WAKIB_TAB_NEXT] = true;
        register_code(KC_LCTL);
        register_code(KC_PGDN);
        break;
    case KC_U:
        wakib_tracker[WAKIB_LINE_START] = true;
        register_code(KC_HOME);
        break;
    case KC_O:
        wakib_tracker[WAKIB_LINE_END] = true;
        register_code(KC_END);
        break;
    case KC_SCLN:
        wakib_tracker[WAKIB_PREVIOUS] = true;
        register_code(KC_RSFT);
        register_code(KC_F3);
        break;
    }
}

bool unregister_wakib_code(uint16_t keycode) {
    switch (keycode) {
    case KC_D:
        if (wakib_tracker[WAKIB_BACKSPACE]) {
            wakib_tracker[WAKIB_BACKSPACE] = false;
            unregister_code(KC_BSPC);
            return false;
        }
        break;
    case KC_F:
        if (wakib_tracker[WAKIB_DELETE]) {
            wakib_tracker[WAKIB_DELETE] = false;
            unregister_code(KC_DEL);
            return false;
        }
        break;
    case KC_E:
        if (wakib_tracker[WAKIB_WORD_BACKSPACE]) {
            wakib_tracker[WAKIB_WORD_BACKSPACE] = false;
            unregister_code(KC_BSPC);
            unregister_code(KC_LCTL);
            return false;
        }
        break;
    case KC_R:
        if (wakib_tracker[WAKIB_WORD_DELETE]) {
            wakib_tracker[WAKIB_WORD_DELETE] = false;
            unregister_code(KC_DEL);
            unregister_code(KC_LCTL);
            return false;
        }
        break;
    case KC_I:
        if (wakib_tracker[WAKIB_UP]) {
            wakib_tracker[WAKIB_UP] = false;
            unregister_code(KC_UP);
            return false;
        }
        if (wakib_tracker[WAKIB_PGUP]) {
            wakib_tracker[WAKIB_PGUP] = false;
            unregister_code(KC_PGUP);
            return false;
        }
        break;
    case KC_J:
        if (wakib_tracker[WAKIB_LEFT]) {
            wakib_tracker[WAKIB_LEFT] = false;
            unregister_code(KC_LEFT);
            return false;
        }
        if (wakib_tracker[WAKIB_TAB_PREV]) {
            wakib_tracker[WAKIB_TAB_PREV] = false;
            unregister_code(KC_LCTL);
            unregister_code(KC_PGUP);
            return false;
        }
        break;
    case KC_K:
        if (wakib_tracker[WAKIB_DOWN]) {
            wakib_tracker[WAKIB_DOWN] = false;
            unregister_code(KC_DOWN);
            return false;
        }
        if (wakib_tracker[WAKIB_PGDOWN]) {
            wakib_tracker[WAKIB_PGDOWN] = false;
            unregister_code(KC_PGDN);
            return false;
        }
        break;
    case KC_L:
        if (wakib_tracker[WAKIB_RIGHT]) {
            wakib_tracker[WAKIB_RIGHT] = false;
            unregister_code(KC_RIGHT);
            return false;
        }
        if (wakib_tracker[WAKIB_TAB_NEXT]) {
            wakib_tracker[WAKIB_TAB_NEXT] = false;
            unregister_code(KC_LCTL);
            unregister_code(KC_PGDN);
            return false;
        }
        break;
    case KC_U:
        if (wakib_tracker[WAKIB_WORD_LEFT]) {
            wakib_tracker[WAKIB_WORD_LEFT] = false;
            unregister_code(KC_LEFT);
            unregister_code(KC_LCTL);
            return false;
        }
        if (wakib_tracker[WAKIB_LINE_START]) {
            wakib_tracker[WAKIB_LINE_START] = false;
            unregister_code(KC_HOME);
            return false;
        }
        break;
    case KC_O:
        if (wakib_tracker[WAKIB_WORD_RIGHT]) {
            wakib_tracker[WAKIB_WORD_RIGHT] = false;
            unregister_code(KC_RIGHT);
            unregister_code(KC_LCTL);
            return false;
        }
        if (wakib_tracker[WAKIB_LINE_END]) {
            wakib_tracker[WAKIB_LINE_END] = false;
            unregister_code(KC_END);
            return false;
        }
        break;
    case KC_SCLN:
        if (wakib_tracker[WAKIB_NEXT]) {
            wakib_tracker[WAKIB_NEXT] = false;
            unregister_code(KC_F3);
            return false;
        }
        if (wakib_tracker[WAKIB_PREVIOUS]) {
            wakib_tracker[WAKIB_PREVIOUS] = false;
            unregister_code(KC_F3);
            unregister_code(KC_RSFT);
            return false;
        }
        break;
    }
    return true;
}

void unregister_all_wakib_codes(uint8_t start) {
    for (int i = start; i < WAKIB_KEY_COUNT; i++) {
        if (wakib_tracker[i]) {
            wakib_tracker[i] = false;
            switch (i) {
            case WAKIB_BACKSPACE:
                unregister_code(KC_BSPC);
                break;
            case WAKIB_DELETE:
                unregister_code(KC_DEL);
                break;
            case WAKIB_WORD_BACKSPACE:
                unregister_code(KC_BSPC);
                unregister_code(KC_LCTL);
                break;
            case WAKIB_WORD_DELETE:
                unregister_code(KC_DEL);
                unregister_code(KC_LCTL);
                break;
            case WAKIB_UP:
                unregister_code(KC_UP);
                break;
            case WAKIB_LEFT:
                unregister_code(KC_LEFT);
                break;
            case WAKIB_DOWN:
                unregister_code(KC_DOWN);
                break;
            case WAKIB_RIGHT:
                unregister_code(KC_RIGHT);
                break;
            case WAKIB_WORD_LEFT:
                unregister_code(KC_LEFT);
                unregister_code(KC_LCTL);
                break;
            case WAKIB_WORD_RIGHT:
                unregister_code(KC_RIGHT);
                unregister_code(KC_LCTL);
                break;
            case WAKIB_LINE_START:
                unregister_code(KC_HOME);
                break;
            case WAKIB_LINE_END:
                unregister_code(KC_END);
                break;
            case WAKIB_TAB_PREV:
                unregister_code(KC_LCTL);
                unregister_code(KC_PGUP);
                break;
            case WAKIB_TAB_NEXT:
                unregister_code(KC_LCTL);
                unregister_code(KC_PGDN);
                break;
            case WAKIB_PGUP:
                unregister_code(KC_PGUP);
                break;
            case WAKIB_PGDOWN:
                unregister_code(KC_PGDN);
                break;
            case WAKIB_NEXT:
                unregister_code(KC_F3);
                break;
            case WAKIB_PREVIOUS:
                unregister_code(KC_F3);
                unregister_code(KC_RSFT);
                break;
            }
        }
    }
}

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        case KC_WAKB:
            if (record->event.pressed) {
                wakib_state = !wakib_state;
                if (wakib_state) {
                    for (uint8_t i=0; i<5; i++) {
                        rgblight_increase_hue_noeeprom();
                    }
                } else {
                    for (uint8_t i=0; i<5; i++) {
                        rgblight_decrease_hue_noeeprom();
                    }
                }
            }
            return false;  // Skip all further processing of this key
        case TG(L_NUMLOCK):
            if (record->event.pressed) {
                if (layer_state_is(L_NUMLOCK)) {
                    rgblight_step_reverse_noeeprom();
                } else {
                    // always enable numlock when layer will become numlock
                    if (!host_keyboard_led_state().num_lock) {
                        register_code(KC_NLCK);
                        unregister_code(KC_NLCK);
                    }
                    rgblight_step_noeeprom();
                }
            }
            return true;
        case KC_D:
        case KC_F:
        case KC_E:
        case KC_R:
            // Wakib keys without shift version
            if (record->event.pressed) {
                // ignore if Win/Super is held
                if (!wakib_state || (mod_state & (MOD_BIT(KC_LWIN) | MOD_BIT(KC_LCTL)))) {
                    return true;
                }
                if (!(mod_state & MOD_BIT(KC_LALT))) {
                    return true;
                }
                del_mods(MOD_BIT(KC_LALT));
                register_wakib_code(keycode);
                set_mods(mod_state);
                return false;
            } else {
                return unregister_wakib_code(keycode);
            }
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_U:
        case KC_O:
        case KC_SCLN:
            // Wakib keys with shift version
            if (record->event.pressed) {
                // ignore if Win/Super is held
                if (!wakib_state || (mod_state & (MOD_BIT(KC_LWIN) | MOD_BIT(KC_LCTL)))) {
                    return true;
                }
                if (!(mod_state & MOD_BIT(KC_LALT))) {
                    return true;
                }
                del_mods(MOD_BIT(KC_LALT));
                if (mod_state & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    register_wakib_shift_code(keycode);
                    set_mods(mod_state);
                    return false;
                } else {
                    register_wakib_code(keycode);
                    set_mods(mod_state);
                    return false;
                }
            } else {
                return unregister_wakib_code(keycode);
            }
        case KC_LALT: // Left Alt
            if (!record->event.pressed) {
                if (wakib_state) {
                    unregister_all_wakib_codes(0);
                }
            }
            return true;
        case KC_LSFT: // Left Shift
            if (!record->event.pressed) {
                if (wakib_state) {
                    unregister_all_wakib_codes(WAKIB_KEY_COUNT - WAKIB_SHIFT_KEY_COUNT);
                }
            }
            return true;
        default:
            return true;  // Process all other keycodes normally
    }
}
