#ifndef WAKIB
#define WAKIB

#include "quantum.h"

enum wakib_keycodes {
    KC_WAKIB_TOGGLE = SAFE_RANGE,
};

bool process_record_wakib(uint16_t keycode, keyrecord_t *record);
bool wakib_get_state(void);

#endif
