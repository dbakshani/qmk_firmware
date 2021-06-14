/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVIGATION,
  _MEDIA,
  _MOUSE
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// multifunction tap/hold keys
#define LSH_ENT LSFT_T(KC_ENT)
#define RSH_ENT RSFT_T(KC_ENT)
#define HYP_ESC HYPR_T(KC_ESC)
#define HYP_MIN HYPR_T(DVK_MINS)
#define LOWR_SPC LT(_LOWER, KC_SPC)
#define NAV_ENT LT(_NAVIGATION, KC_ENT)
#define RAIS_BSP LT(_RAISE, KC_BSPC)
//#define LSFT_DEL LSFT_T(KC_DEL)
#define LSFT_MIN LSFT_T(DVK_MINS)
#define MDIA_TAB LT(_MEDIA, KC_TAB)
#define MOUS_ESC LT(_MOUSE, KC_ESC)

// make it easier to map qwerty to dvorak on symbol layers
#define DVK_QUOT KC_Q
#define DVK_COMM KC_W
#define DVK_DOT KC_E
#define DVK_SLSH KC_LBRC
#define DVK_EQUL KC_RBRC
#define DVK_QSTN KC_LCBR
#define DVK_PLUS KC_RCBR
#define DVK_MINS KC_QUOT
#define DVK_UNDS KC_DQUO
#define DVK_SCLN KC_Z
#define DVK_LBRC KC_MINS
#define DVK_RBRC KC_EQL
#define DVK_LCBR KC_UNDS
#define DVK_RCBR KC_PLUS

// Left-hand home row mods
#define ALT_A LALT_T(KC_A)
#define GUI_S LGUI_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
#define HYPR_G HYPR_T(KC_G)
#define ALGR_Z ALGR_T(KC_Z)

// Right-hand home row mods
#define HYPR_H HYPR_T(KC_H)
#define CTL_J LCTL_T(KC_J)
#define SFT_K LSFT_T(KC_K)
#define GUI_L LGUI_T(KC_L)
#define ALT_SCLN LALT_T(KC_SCLN)
#define ALGR_SLS ALGR_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_preonic_grid(
    KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_GRV , KC_BSPC, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
    KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_TAB , KC_BSPC, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
    ALT_A  , GUI_S  , SFT_D  , CTL_F  , HYPR_G , HYP_ESC, HYP_MIN, HYPR_H , CTL_J  , SFT_K  , GUI_L  ,ALT_SCLN,
    ALGR_Z , KC_X   , KC_C   , KC_V   , KC_B   , LSH_ENT, RSH_ENT, KC_N   , KC_M   , KC_COMM, KC_DOT ,ALGR_SLS,
    KC_DOWN, KC_UP  ,MDIA_TAB,LOWR_SPC,MOUS_ESC, KC_SPC , KC_SPC , NAV_ENT,RAIS_BSP,LSFT_MIN, KC_LEFT, KC_RGHT
),

[_LOWER] = LAYOUT_preonic_grid(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR, KC_GRV , KC_DEL ,DVK_PLUS, KC_7   , KC_8   , KC_9   , KC_ASTR,
    KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_DEL , KC_DEL , _______,DVK_SLSH, KC_4   , KC_5   , KC_6   ,DVK_EQUL,
    KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_GRV , _______, _______, KC_BSLS, KC_1   , KC_2   , KC_3   , KC_SLCK,
    _______, _______, _______, _______, KC_PAUS, _______, _______,DVK_MINS, KC_0   , DVK_DOT, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,KC_TILD , KC_DEL , _______,DVK_LCBR,DVK_RCBR,DVK_QSTN,DVK_PLUS,
    _______, KC_DLR , KC_PERC, KC_CIRC, _______, _______, _______, _______,DVK_LBRC,DVK_RBRC,DVK_SLSH,DVK_EQUL,
    _______, KC_EXLM, KC_AT  , KC_HASH, KC_TILD, _______, _______, KC_PIPE, KC_LPRN, KC_RPRN, _______, KC_BSPC,
    _______, _______, _______, _______,DVK_UNDS, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RESET  , DEBUG  , RGB_TOG, RGB_MOD, RGB_HUI, _______, _______, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
    _______, MU_MOD , AU_ON  , AU_OFF , AG_NORM, _______, _______, AG_SWAP, QWERTY , _______, _______, _______,
    MUV_DE , MUV_IN , MU_ON  , MU_OFF , MI_ON  , _______, _______, MI_OFF , TERM_ON,TERM_OFF, _______, _______,
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NAVIGATION] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, KC_CAPS, _______,KC_RIGHT,
    KC_END , _______, _______, KC_PGUP, KC_HOME, _______, _______, KC_PGDN, KC_LEFT, _______, _______, _______,
    _______, _______, KC_DOWN, KC_UP  , _______, _______, _______, KC_PGUP, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
