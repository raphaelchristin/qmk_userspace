#include QMK_KEYBOARD_H
#include "version.h"

#define MOON_LED_LEVEL LED_LEVEL
#define HRM_A MT(MOD_LALT, KC_A)
#define HRM_S MT(MOD_LGUI, KC_S)
#define HRM_D MT(MOD_LSFT, KC_D)
#define HRM_F MT(MOD_LCTL, KC_F)
#define HRM_J MT(MOD_RCTL, KC_J)
#define HRM_K MT(MOD_RSFT, KC_K)
#define HRM_L MT(MOD_RGUI, KC_L)
#define HRM_SCLN MT(MOD_RALT, KC_SCLN)
#define LT_BSPC LT(2, KC_BSPC)
#define LT_SPC LT(1, KC_SPC)

enum custom_keycodes {
    /*RGB_SLD = ML_SAFE_RANGE,*/
    RGB_SLD = SAFE_RANGE,
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(2, KC_BSPC), KC_DEL);
const key_override_t next_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL,                    // Trigger modifiers: ctrl
                                                                                   KC_MPLY,                          // Trigger key: play/pause
                                                                                   KC_MNXT,                          // Replacement key
                                                                                   ~0,                               // Activate on all layers
                                                                                   MOD_MASK_SA,                      // Do not activate when shift or alt are pressed
                                                                                   ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting ctrl

const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY, KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

const key_override_t vol_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_MPLY, KC_VOLU, ~0, MOD_MASK_CSG, ko_option_no_reregister_trigger);

const key_override_t vol_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SA, KC_MPLY, KC_VOLD, ~0, MOD_MASK_CG, ko_option_no_reregister_trigger);

const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_GUI, KC_MPLY, KC_BRIU, ~0, MOD_MASK_CSA, ko_option_no_reregister_trigger);

const key_override_t brightness_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SG, KC_MPLY, KC_BRID, ~0, MOD_MASK_CA, ko_option_no_reregister_trigger);

const key_override_t grave_override = ko_make_basic(MOD_MASK_SHIFT, KC_TILD, KC_GRV);

const key_override_t pipe_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_BSLS);

const key_override_t tab_override = ko_make_basic(MOD_MASK_CTRL, LT(1, KC_SPACE), KC_TAB);

// clang-format off
const key_override_t *key_overrides[] = {
	&delete_key_override, 
	&grave_override, 
	&next_track_override, 
	&prev_track_override, 
	&vol_up_override, 
	&vol_down_override, 
	&brightness_up_override, 
	&brightness_down_override, 
	&pipe_override, 
	&tab_override,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_voyager(
		TO(3), 	    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,  KC_MPRV,  KC_MNXT, KC_MPLY, 
		KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,  KC_GRV, 
		KC_MINS,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G,           KC_H,   HRM_J,   HRM_K,    HRM_L, HRM_SCLN, KC_QUOT, 
		CW_TOGG,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M, KC_COMM,   KC_DOT,  KC_SLSH, KC_PIPE, 
					            LT_BSPC,  KC_ENT,         KC_ESC,  LT_SPC
	),
    [1] = LAYOUT_voyager(
		KC_NO,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO, 
		KC_TAB,  KC_PLUS,    KC_7,    KC_8,    KC_9, KC_ASTR,          KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO, 
		KC_HASH, KC_MINS,    KC_4,    KC_5,    KC_6,  KC_EQL,          KC_NO, KC_RCTL, KC_RSFT,  KC_RGUI,  KC_RALT,   KC_NO, 
		KC_AMPR, KC_SLSH,    KC_1,    KC_2,    KC_3, KC_PERC,          KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO, 
		                                       KC_0,  KC_ENT,          KC_NO, KC_TRNS
	),
    [2] = LAYOUT_voyager(
		KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_NO, 
		KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_CIRC, KC_LCBR, KC_LBRC,  KC_LPRN,    KC_LT,   KC_NO, 
		KC_NO,   KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,   KC_NO,        KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,  KC_EXLM,   KC_NO, 
		KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_DLR, KC_RCBR, KC_RBRC,  KC_RPRN,    KC_GT,   KC_NO, 
		                                    KC_TRNS,   KC_NO,          KC_AT,  KC_EQL
	),
    [3] = LAYOUT_voyager(
		TO(0),      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,     KC_9,     KC_0,   KC_NO, 
		KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,   KC_NO, 
		KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,     KC_L,  KC_SCLN,   KC_NO, 
		KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M, KC_COMM,   KC_DOT,  KC_SLSH,   KC_NO, 
		                                     KC_SPC,  KC_ESC,         KC_ENT, KC_BSPC
	),
};
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {{28, 151, 230}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {28, 151, 230}, {28, 151, 230}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {28, 151, 230}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {28, 151, 230}, {28, 151, 230}},

    [1] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {128, 99, 188}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [2] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {65, 148, 192}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    // [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {65,148,192}, {65,148,192}, {65,148,192}, {65,148,192}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = {{128, 99, 188}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}, {28, 151, 230}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}

void leader_start_user(void) {}

void leader_end_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
