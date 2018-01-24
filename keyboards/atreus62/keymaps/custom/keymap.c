// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
		{ KC_ESC,  KC_1,    KC_2,         KC_3,         KC_4,   KC_5,    KC_NO,  KC_6,     KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC },
		{ KC_TAB,  KC_Q,    KC_W,         KC_E,         KC_R,   KC_T,    KC_NO,  KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC },
		{ KC_GRV,  KC_A,    KC_S,         KC_D,         KC_F,   KC_G,    KC_NO,  KC_H,     KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RBRC },
		{ KC_LSFT, KC_Z,    KC_X,         KC_C,         KC_V,   KC_B,    KC_SPC, KC_N,     KC_M,    KC_COMM, KC_DOT, KC_QUOT, KC_DELETE },
		{ KC_LCTL, KC_LALT, LGUI(KC_SPC), LGUI(KC_GRV), KC_MEH, KC_LGUI, KC_ENT, MO(_NAV), KC_HYPR, KC_MINS, KC_EQL, KC_SLSH, KC_BSLS }
},

[_NAV] = { 
		{ TO(_DEFAULT), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_TRNS },
		{ KC_TRNS,      KC_NO,   KC_MS_U, KC_NO,   KC_WH_U, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,  KC_F11   },
		{ KC_TRNS,      KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,  KC_F12  },
		{ KC_TRNS,      KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN2, KC_TRNS, KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,  KC_NO   },
		{ KC_TRNS,      KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  TO(_RESET) }
},

[_RESET] = {
		{ TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
}


/*
[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};
