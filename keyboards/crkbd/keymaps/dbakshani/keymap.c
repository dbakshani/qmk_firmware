/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVIGATION,
  _MEDIA,
  _MOUSE
};

// enum planck_keycodes {
//   QWERTY = SAFE_RANGE,
//   BACKLIT
// };

enum combos {
    WE_TAB,
    IO_MINS,
    COMMADOT_USCR
};

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)

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
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define GUI_L RGUI_T(KC_L)
#define ALT_SCLN RALT_T(KC_SCLN)
#define ALGR_SLS ALGR_T(KC_SLSH)

 const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
 const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
 const uint16_t PROGMEM commadot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

 combo_t key_combos[] = {
     [WE_TAB] = COMBO(we_combo, KC_TAB),
     [IO_MINS] = COMBO(io_combo, DVK_MINS),
     [COMMADOT_USCR] = COMBO(commadot_combo, DVK_UNDS),
 };

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //   [0] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  //
  // ),
  //
  //   [1] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //
  //   [2] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //
  //   [3] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // )
// };

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
      KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,KC_BSPC, 
      HYP_ESC, ALT_A  , GUI_S  , SFT_D  , CTL_F  , HYPR_G ,                   HYPR_H , CTL_J  , SFT_K  , GUI_L  ,ALT_SCLN,HYP_MIN, 
      LSH_ENT, ALGR_Z , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT ,ALGR_SLS,RSH_ENT, 
                                          MDIA_TAB,LOWR_SPC,MOUS_ESC, NAV_ENT,RAIS_BSP,LSFT_MIN
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
      _______, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_GRV ,                   DVK_PLUS, KC_7   , KC_8   , KC_9   , KC_ASTR, KC_DEL , 
      _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_DEL ,                   DVK_SLSH, KC_4   , KC_5   , KC_6   ,DVK_EQUL, _______, 
      _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_GRV ,                   KC_BSLS,  KC_1   , KC_2   , KC_3   , _______, _______, 
                                          _______, _______, _______,  DVK_MINS, KC_0 ,  DVK_DOT
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
      _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                   _______,DVK_LCBR,DVK_RCBR,DVK_QSTN,DVK_PLUS, KC_DEL ,
      _______, _______, KC_DLR , KC_PERC, KC_CIRC, KC_GRV ,                   KC_BSLS,DVK_LBRC,DVK_RBRC,DVK_SLSH,DVK_EQUL, _______,
      _______, _______, KC_EXLM, KC_AT  , KC_HASH, KC_TILD,                   KC_PIPE, KC_LPRN, KC_RPRN, _______, KC_BSPC, _______,
                                          _______, _______, _______, _______, _______, _______
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
  [_ADJUST] = LAYOUT_split_3x6_3(
      // RESET  , DEBUG  , RGB_TOG, RGB_MOD, RGB_HUI, _______, _______, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
      // _______, MU_MOD , AU_ON  , AU_OFF , AG_NORM, _______, _______, AG_SWAP, QWERTY , _______, _______, _______,
      // MUV_DE , MUV_IN , MU_ON  , MU_OFF , MI_ON  , _______, _______, MI_OFF , TERM_ON,TERM_OFF, _______, _______,
      // BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, AG_NORM,                      AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
  ),

  [_NAVIGATION] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______,                   KC_PGDN, _______, KC_CAPS, _______,KC_RIGHT, _______, 
      CW_TOGG, KC_END , _______, _______, KC_PGUP, KC_HOME,                   KC_PGDN, KC_LEFT, _______, _______, _______, _______, 
      _______, _______, _______, KC_DOWN, KC_UP  , _______,                   KC_PGUP, _______, _______, _______, _______, _______, 
                                          _______, _______, _______, _______, _______, _______
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______,
                                          _______, _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
      _______, _______, _______, _______, _______, _______,                   _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, 
      _______, _______, _______, _______, _______, _______,                   _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______, 
                                          _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         print("mode just switched to qwerty and this is a huge string\n");
//         set_single_persistent_default_layer(_QWERTY);
//       }
//       return false;
//       break;
//     case BACKLIT:
//       if (record->event.pressed) {
//         register_code(KC_RSFT);
//         #ifdef BACKLIGHT_ENABLE
//           backlight_step();
//         #endif
//         #ifdef KEYBOARD_planck_rev5
//           writePinLow(E6);
//         #endif
//       } else {
//         unregister_code(KC_RSFT);
//         #ifdef KEYBOARD_planck_rev5
//           writePinHigh(E6);
//         #endif
//       }
//       return false;
//       break;
//   }
//   return true;
// }

