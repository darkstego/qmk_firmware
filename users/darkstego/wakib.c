#include "wakib.h"

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

bool wakib_get_state(void) {
    return wakib_state;
}


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


bool process_record_wakib(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_WAKIB_TOGGLE:
            if (record->event.pressed) {
                wakib_state = !wakib_state;
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
                if (mod_state & MOD_BIT(KC_LALT)) {
                    del_mods(MOD_BIT(KC_LALT));
                }
                uint8_t result = unregister_wakib_code(keycode);
                set_mods(mod_state);
                return result;
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
                if (mod_state & MOD_BIT(KC_LALT)) {
                    del_mods(MOD_BIT(KC_LALT));
                }
                uint8_t result = unregister_wakib_code(keycode);
                set_mods(mod_state);
                return result;
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
