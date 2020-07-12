/* Copyright 2017 Wunder
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

// Layer shorthand
//#define _QW 0
//#define _FN 1

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVIGATION
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

// Keypress aliases
//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

//TODO: add numpad
//TODO: add printscreen, scroll lock, pause
//TODO: add define/aliases for long keys
//TODO: add colemak and dvorak
//TODO: cleanup spacing
//TODO: add insert key
//TODO: add capslock
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LCTRL  | LALT   | LGUI   | LOWER  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | RAISE  | RGUI   | RALT   | RCTRL  | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    HYPR_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_T(KC_ENT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER, LT(_NAVIGATION, KC_SPC), KC_LEFT, KC_DOWN, KC_RGHT, LT(_NAVIGATION, KC_SPC), RAISE, KC_RGUI, KC_RALT, KC_RCTL, KC_RCTL
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

//  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
//    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
//    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
//    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
//    _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
//  )

/* Raise
 * ,--------------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |        |        |        |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |        |        |        |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+--------+--------+---------------+------+------+------+------+------|
 * | Del  |      | VOL- | MUTE | VOL+ |      |        |        |        |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      | STOP | PREV | PLAY | NEXT |      |        |        |        |      |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+---------------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |        |        |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x15(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, _______,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_MSTP, KC_MPRV,  KC_MPLY,  KC_MNXT, _______, _______, _______, _______, _______,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

/* Lower
 * ,--------------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |        |        |        |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |        |        |        |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+--------+--------+---------------+------+------+------+------+------|
 * | Del  |      | VOL- | MUTE | VOL+ |      |        |        |        |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      | STOP | PREV | PLAY | NEXT |      |        |        |        |      |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+---------------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |        |        |      |      | Prev | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x15(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______, _______, _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______,  _______,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_MSTP, KC_MPRV,  KC_MPLY,  KC_MNXT,  _______, _______, _______, _______,  _______,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MPLY
  ),

/* Adjust (Lower + Raise)
 *                                           v---RGB CONTROL---v
 * ,--------------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  VAL+  |  VAL-  |        |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * | Reset|Debug |      |      |      |      |  SAT+  |  SAT-  |        |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|  HUE+  |  HUE-  |        |AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | MODE+  | MODE-  |        |      |      |      |      |      |      |
 * |------+------+------+------+------+---------------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | TOGGLE |        |        |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT_ortho_5x15(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   RGB_VAI, RGB_VAD, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    RESET,   DEBUG, _______,  _______, _______, _______,  RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______, _______, _______, AG_NORM, RGB_HUI, RGB_HUD, _______, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______ 
  ),

/* Navigation
 * ,--------------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |        |        |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |        |        |Pg Dn |      |      |      |Right |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      | End  |      |      |Pg Up | Home |        |        |        |Pg Dn | Left |      |      |      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      | Down |  Up  |      |        |        |        |Pg Up |      |      |      |      |      |
 * |------+------+------+------+------+---------------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |        |        |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------------'
 */
  [_NAVIGATION] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______,  _______, KC_RIGHT, _______,
    _______, KC_END , _______, _______, KC_PGUP, KC_HOME, _______, _______, _______, KC_PGDN, KC_LEFT, _______,  _______, _______, _______,
    _______, _______, _______, KC_DOWN, KC_UP  , _______, _______, _______, _______, KC_PGUP, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            print("mode just switched to qwerty and this is a huge string\n");
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
//        case COLEMAK:
//          if (record->event.pressed) {
//            set_single_persistent_default_layer(_COLEMAK);
//          }
//          return false;
//          break;
//        case DVORAK:
//          if (record->event.pressed) {
//            set_single_persistent_default_layer(_DVORAK);
//          }
//          return false;
//          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
//        case BACKLIT:
//          if (record->event.pressed) {
//            register_code(KC_RSFT);
//            #ifdef BACKLIGHT_ENABLE
//              backlight_step();
//            #endif
//            #ifdef __AVR__
//            writePinLow(E6);
//            #endif
//          } else {
//            unregister_code(KC_RSFT);
//            #ifdef __AVR__
//            writePinHigh(E6);
//            #endif
//          }
          return false;
          break;
      }
    return true;
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case QMKBEST:
//      if (record->event.pressed) {
//        // when keycode QMKBEST is pressed
//        SEND_STRING("QMK is the best thing ever!");
//      } else {
//        // when keycode QMKBEST is released
//      }
//      break;
//    case QMKURL:
//      if (record->event.pressed) {
//        // when keycode QMKURL is pressed
//        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
//      } else {
//        // when keycode QMKURL is released
//      }
//      break;
//  }
//  return true;
//}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
