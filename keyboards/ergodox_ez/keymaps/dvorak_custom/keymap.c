#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_canadian_multilingual.h"

#define BASE  0 // Basic layer
#define SYMB  1 // Symbols
#define ACTS  2 // Accents & Numpad
#define CTRLS 3 // Arrows & Mouse controls
#define GAME  4 // Gaming

// TAP / HOLD / RELEASE actions
#define TAP(code) \
  register_code (code); \
  unregister_code (code)

#define HOLD(code) \
  register_code (code)

#define RELEASE(code) \
  unregister_code (code)

// NONE key
#define XXXXXXX KC_NO

// Custom keycodes
/* #define CC_SLSH ALGR(CSA_ECUT) */
/* #define CC_BSLS ALGR(CSA_EGRV) */
/* #define CC_PIPE ALGR(KC_MINUS) */
#define CC_AE ALGR(KC_A)
#define CC_OE ALGR(KC_Q)
#define CC_DACT LSFT(ALGR(KC_SCLN))
#define CC_DTLD LSFT(ALGR(CSA_CCED))

// Custom macros
enum custom_macros {
  _CK = SAFE_RANGE, // must always be here
  VRSN,
  RGB_SLD,
  CC_GRV,   // `
  CC_CIRC,  // ˆ
  CC_TILD,  // ~
  CC_ICRC,  // î
  CC_ITRM,  // ï
  CC_LDSK,  // CMD + Left
  CC_RDSK,  // CMD + Right
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  | Del  |           | Del  |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Esc  |   `  |  ,'  |  ."  |   P  |   Y  | Space|           | BkSp |   F  |   G  |   C  |   R  |   L  |  Caps  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | RShift |
 * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
 * |  LGUI  |   ;: |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |  RGUI  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Left| Right | Down |  Up  |  L2  |                                       |  L1  |  Up  | Down | Left | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Play |  V+  |       | Next | Stop |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  V-  |       | Prev |        |      |
 *                                 | LCtrl| LGUI |------|       |------|  RAlt  |RShift|
 *                                 | Space|      | LAlt |       |      |        |Space |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  _______,                KC_1,                    KC_2,                    KC_3,                    KC_4,                    KC_5,                    KC_DEL,
  KC_ESC,                 ALGR(CSA_AGRV),          KC_COMM,                 KC_DOT,                  KC_P,                    KC_Y,                    KC_SPC,
  KC_LSFT,                KC_A,                    KC_O,                    KC_E,                    KC_U,                    KC_I,
  KC_LGUI,                KC_SCLN,                 KC_Q,                    KC_J,                    KC_K,                    KC_X,                    KC_TAB,
  KC_LEFT,                KC_RIGHT,                KC_DOWN,                 KC_UP,                   MO(ACTS),

                                                                                                                              KC_MPLY,                 KC_VOLU,
                                                                                                                                                       KC_VOLD,
                                                                                                     LCTL_T(KC_SPC),          KC_LGUI,                 KC_LALT,

  // right hand
  KC_DEL,                 KC_6,                    KC_7,                    KC_8,                    KC_9,                    KC_0,                    XXXXXXX,
  KC_BSPC,                KC_F,                    KC_G,                    KC_C,                    KC_R,                    KC_L,                    KC_CAPS,
                          KC_D,                    KC_H,                    KC_T,                    KC_N,                    KC_S,                    KC_RSFT,
  KC_ENT,                 KC_B,                    KC_M,                    KC_W,                    KC_V,                    KC_Z,                    KC_RGUI,
                                                   MO(SYMB),                KC_UP,                   KC_DOWN,                 KC_LEFT,                 KC_RIGHT,

  KC_MNXT,                KC_MSTP,
  KC_MPRV,
  KC_RALT,                KC_RALT,                 RSFT_T(KC_SPC)
),

/* Keymap 1: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  @   |  [   |  ]   |  ?   |      |           |      |   \  |  <   |  >   |  =   |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ~   |  #   |  {   |  }   |  !   |------|           |------|   /  |  (   |  )   |  +   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Toggle |      |  &   |  %   |  $   |  *   |      |           |      |   |  |  -   |  _   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Animat| Hue  | Satur| Value|  L3  |                                       |      |  L4  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[SYMB] = LAYOUT_ergodox(
    // left hand
    _______,                KC_F1,                   KC_F2,                   KC_F3,                   KC_F4,                   KC_F5,                   _______,
    _______,                _______,                 KC_AT,                   CSA_LBRC,                CSA_RBRC,                CSA_QEST,                _______,
    _______,                CC_TILD,                 KC_HASH,                 CSA_LCBR,                CSA_RCBR,                KC_EXLM,
    RGB_TOG,                _______,                 KC_AMPR,                 KC_PERC,                 KC_DLR,                  KC_ASTR,                 _______,
    RGB_MOD,                RGB_HUI,                 RGB_SAI,                 RGB_VAI,                 MO(CTRLS),


                                                                                                                                _______,                 _______,
                                                                                                                                                         _______,
                                                                                                       _______,                 _______,                 _______,

    // right hand
    _______,                KC_F6,                   KC_F7,                   KC_F8,                   KC_F9,                   KC_F10,                  KC_F11,
    _______,                CSA_BSLS,                CSA_LESS,                CSA_GRTR,                KC_EQUAL,                _______,                 KC_F12,
                            CSA_SLSH,                KC_LPRN,                 KC_RPRN,                 KC_PLUS,                 _______,                 _______,
    _______,                CSA_PIPE,                KC_MINUS,                KC_UNDS,                 _______,                 _______,                 _______,
                                                     _______,                 TG(GAME),                _______,                 _______,                 _______,

    _______,                _______,
    _______,
    _______,                _______,                 _______
),

/* Keymap 2: Accents & Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  `   |  ´   |  ˆ   |  ~   |      |           |      |  -   |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  à   |  è   |  é   |  î   |  ï   |------|           |------|  /   |  4   |  5   |  6   |  .   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  æ   |  œ   |  ç   |      |      |           |      |  *   |  1   |  2   |  3   |  0   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  L3  |Light+|Light-| Hue+ | Hue- |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[ACTS] = LAYOUT_ergodox(
    // left hand
    _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
    _______,                _______,                 CSA_DGRV,                CC_DACT,                 CSA_DCRC,                CC_DTLD,                 _______,
    _______,                CSA_AGRV,                CSA_EGRV,                CSA_ECUT,                CC_ICRC,                 CC_ITRM,
    _______,                _______,                 CC_AE,                   CC_OE,                   CSA_CCED,                _______,                 _______,
    _______,                _______,                 _______,                 _______,                 _______,
                                                                                                                                _______,                 _______,
                                                                                                                                                         _______,
                                                                                                       _______,                 _______,                 _______,

    // right hand
    _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
    _______,                KC_PMNS,                 KC_7,                    KC_8,                    KC_9,                    KC_PPLS,                 _______,
                            KC_PSLS,                 KC_4,                    KC_5,                    KC_6,                    KC_DOT,                  _______,
    _______,                KC_PAST,                 KC_1,                    KC_2,                    KC_3,                    KC_0,                    _______,
                                                     MO(CTRLS),               RGB_VAI,                 RGB_VAD,                 RGB_HUI,                 RGB_HUD,


    _______,                _______,
    _______,
    _______,                _______,                 _______
),

/* Keymap 3: Controls
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  VRSN  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  <=  |  ↑   |  =>  |      |      |           |      | ScrlD|LClick|  ⇡   |RClick| Spd+ |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  ←   |  ↓   |  →   |      |------|           |------| ScrlU|  ⇠   |  ⇣   |  ⇢   | Spd- |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |LShift| LGui | LAlt | LCtrl|      |      |           |      |      | RCtrl| RAlt | RGui |RShift|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[CTRLS] = LAYOUT_ergodox(
    // left hand
    VRSN,                   _______,                 _______,                 _______,                 _______,                 _______,                 _______,
    _______,                _______,                 CC_LDSK,                 KC_UP,                   CC_RDSK,                 _______,                 _______,
    _______,                _______,                 KC_LEFT,                 KC_DOWN,                 KC_RIGHT,                _______,
    CSA_U_GRAVE,            KC_LSFT,                 KC_LGUI,                 KC_LALT,                 KC_LCTRL,                _______,                 _______,
    _______,                _______,                 _______,                 _______,                 _______,

                                                                                                                                _______,                 _______,
                                                                                                                                                         _______,
                                                                                                       _______,                 _______,                 _______,

    // right hand
    _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
    _______,                KC_WH_D,                 KC_BTN1,                 KC_MS_U,                 KC_BTN2,                 KC_ACL0,                 _______,
                            KC_WH_U,                 KC_MS_L,                 KC_MS_D,                 KC_MS_R,                 KC_ACL2,                 _______,
    _______,                _______,                 KC_RCTRL,                KC_RALT,                 KC_RGUI,                 KC_RSFT,                 CSA_E_ACUTE,
                                                     _______,                 _______,                 _______,                 _______,                 _______,

    _______,                _______,
    _______,
    _______,                _______,                 _______
),

/* Keymap 4: Gaming
 * ┌──────┬───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┬──────┐
 * │Escape│ 1 │ 2 │ 3 │ 4 │ 5 │ = │                     │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │    - │
 * ├──────┼───┼───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┼───┼──────┤
 * │ Tab  │ Q │ W │ E │ R │ T │ = │                     │ Y │ Y │ U │ I │ O │ P │    \ │
 * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
 * │Shift │ A │ S │ D │ F │ G ├───┤                     ├───┤ H │ J │ K │ L │ ; │    ' │
 * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
 * │ Ctl  │ Z │ X │ C │ V │ B │ B │                     │ N │ N │ M │ , │ . │ / │ Shift│
 * └──┬───┼───┼───┼───┼───┼───┴───┘ ┌───┬───┐ ┌───┬───┐ └───┴───┼───┼───┼───┼───┼───┬──┘
 *    │Cap│F4 │F5 │F6 │Alt│         │ C │ V │ │Alt│ A │         │   │   │   │   │GUI│
 *    └───┴───┴───┴───┴───┘     ┌───┼───┼───┤ ├───┼───┼───┐     └───┴───┴───┴───┴───┘
 *                              │   │   │PgU│ │PgD│   │   │
 *                              │   │Bsp├───┤ ├───┤Ent│   │
 *                              │   │   │Del│ │Ctl│   │   │
 *                              └───┴───┴───┘ └───┴───┴───┘
 */
[GAME] = LAYOUT_ergodox(
    // left hand
    KC_ESC,                 KC_1,                    KC_2,                    KC_3,                    KC_4,                    KC_5,                    KC_EQL,
    KC_TAB,                 KC_Q,                    KC_W,                    KC_E,                    KC_R,                    KC_T,                    KC_EQL,
    KC_LSFT,                KC_A,                    KC_S,                    KC_D,                    KC_F,                    KC_G,
    KC_LCTL,                KC_Z,                    KC_X,                    KC_C,                    KC_V,                    KC_B,                    KC_B,
    KC_CAPS,                KC_F4,                   KC_F5,                   KC_F6,                   KC_LALT,
                                                                                                                                KC_C,                    KC_V,
                                                                                                                                                         KC_PGUP,
                                                                                                       KC_SPC,                  KC_BSPC,                 KC_DEL,

    // right hand
    KC_5,                   KC_6,                    KC_7,                    KC_8,                    KC_9,                    KC_0,                    KC_MINS,
    KC_Y,                   KC_Y,                    KC_U,                    KC_I,                    KC_O,                    KC_P,                    KC_BSLS,
                            KC_H,                    KC_J,                    KC_K,                    KC_L,                    KC_SCLN,                 KC_QUOT,
    KC_N,                   KC_N,                    KC_M,                    KC_COMM,                 KC_DOT,                  KC_SLSH,                 KC_RSFT,
                                                     _______,                 _______,                 _______,                 _______,                 KC_RGUI,
    KC_RALT,                KC_A,
    KC_PGDN,
    KC_RCTL,                KC_ENT,                  KC_SPC
),

/* Keymap X:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// [XXX] = LAYOUT_ergodox(
//     // left hand
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//     _______,                _______,                 _______,                 _______,                 _______,
//
//                                                                                                                                 _______,                 _______,
//                                                                                                                                                          _______,
//                                                                                                        _______,                 _______,                 _______,
//
//     // right hand
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//                             _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//     _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
//                                                      _______,                 _______,                 _______,                 _______,                 _______,
//
//     _______,                _______,
//     _______,
//     _______,                _______,                 _______,
// ),
};

// Key processing hook
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING(QMK_KEYBOARD " - " QMK_KEYMAP " @ " QMK_VERSION);
        return false; break;

      case RGB_SLD:
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
#endif
        return false; break;

      case CC_GRV:
        HOLD(KC_RALT);
        TAP(CSA_DCRC);
        RELEASE(KC_RALT);
        TAP(KC_SPC);
        return false; break;

      case CC_CIRC:
        TAP(CSA_DCRC);
        TAP(KC_SPC);
        return false; break;

      case CC_TILD:
        HOLD(KC_RALT);
        TAP(CSA_CCED);
        RELEASE(KC_RALT);
        return false; break;

      case CC_ICRC:
        TAP(CSA_DCRC);
        TAP(KC_I);
        return false; break;

      case CC_ITRM:
        HOLD(KC_LSHIFT);
        TAP(CSA_DCRC);
        RELEASE(KC_LSHIFT);
        TAP(KC_I);
        return false; break;

      case CC_LDSK:
        HOLD(KC_RGUI);
        TAP(KC_LEFT);
        RELEASE(KC_RGUI);
        return false; break;

      case CC_RDSK:
        HOLD(KC_RGUI);
        TAP(KC_RIGHT);
        RELEASE(KC_RGUI);
        return false; break;
    }
  }

  return true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  // Turn off all the leds
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  // Turn back on the ones corresponding to the current layer
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }
};
