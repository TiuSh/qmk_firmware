#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_canadian_multilingual.h"

#define BASE  0 // Basic layer
#define SYMB  1 // Symbols
#define ACTS  2 // Accents & Numpad
#define CTRLS 3 // Arrows & Mouse controls

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

// Custome keycodes
#define CC_SLSH ALTGR(CSA_ECUT)
#define CC_BSLS ALTGR(CSA_EGRV)
#define CC_PIPE ALTGR(KC_MINUS)
#define CC_AE ALTGR(KC_A)
#define CC_OE ALTGR(KC_Q)
#define CC_DACT LSFT(ALTGR(KC_SCLN))
#define CC_DTLD LSFT(ALTGR(CSA_CCED))

// Custom macros
enum custom_macros {
  _CK = SAFE_RANGE, // must always be here
  VRSN,
  RGB_SLD,
  CC_GRV,  // `
  CC_CIRC, // ˆ
  CC_TILD, // ~
  CC_ICRC, // î
  CC_ITRM,  // ï
  CC_LDSK,  // CMD + Left
  CC_RDSK,  // CMD + Right
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  | Del  |           | Del  |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Caps  |   `  |  ,'  |  ."  |   P  |   Y  | BkSp |           | BkSp |   F  |   G  |   C  |   R  |   L  |  Esc   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | RShift |
 * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
 * |  LGUI  |   ;: |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |  RGUI  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Right| Left | Down |  Up  |  L2  |                                       |  L1  |  Up  | Down | Left | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Play |  V+  |       | Next | Stop |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  V-  |       | Prev |        |      |
 *                                 | Space| LCtrl|------|       |------|  RGUI  |RShift|
 *                                 |      |      | LAlt |       | RAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,                 KC_1,                    KC_2,                    KC_3,                    KC_4,                    KC_5,                    KC_DEL,
  KC_CAPS,                ALTGR(CSA_AGRV),         KC_COMM,                 KC_DOT,                  KC_P,                    KC_Y,                    KC_BSPC,
  KC_LSFT,                KC_A,                    KC_O,                    KC_E,                    KC_U,                    KC_I,
  KC_LGUI,                KC_SCLN,                 KC_Q,                    KC_J,                    KC_K,                    KC_X,                    KC_TAB,
  KC_RIGHT,               KC_LEFT,                 KC_DOWN,                 KC_UP,                   MO(ACTS),

                                                                                                                              KC_MPLY,                 KC_VOLU,
                                                                                                                                                       KC_VOLD,
                                                                                                     KC_SPC,                  KC_LCTRL,                KC_LALT,

  // right hand
  KC_DEL,                 KC_6,                    KC_7,                    KC_8,                    KC_9,                    KC_0,                    XXXXXXX,
  KC_BSPC,                KC_F,                    KC_G,                    KC_C,                    KC_R,                    KC_L,                    XXXXXXX,
                          KC_D,                    KC_H,                    KC_T,                    KC_N,                    KC_S,                    KC_RSFT,
  KC_ENT,                 KC_B,                    KC_M,                    KC_W,                    KC_V,                    KC_Z,                    KC_RGUI,
                                                   MO(SYMB),                KC_UP,                   KC_DOWN,                 KC_LEFT,                 KC_RIGHT,

  KC_MNXT,                KC_MSTP,
  KC_MPRV,
  KC_RALT,                KC_RGUI,                 KC_RSFT
),

/* Keymap 1: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  &   |  *   |  ~   |  €   |      |           |      |   \  |  <   |  >   |  [   |  ]   |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |------|           |------|   /  |  (   |  )   |  {   |  }   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  ^   |  °   |  ?   |  £   |      |           |      |   |  |  -   |  _   |  +   |  =   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Toggle|Animat|Solid |      |  L3  |                                       |      |      |      |      |      |
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
    _______,                _______,                 KC_AMPR,                 KC_ASTR,                 CC_TILD,                 CSA_EURO,                _______,
    _______,                KC_EXLM,                 KC_AT,                   KC_HASH,                 KC_DLR,                  KC_PERC,
    _______,                _______,                 CC_CIRC,                 CSA_DEGR,                CSA_QEST,                CSA_POUND,               _______,
    RGB_TOG,                RGB_MOD,                 RGB_SLD,                 _______,                 MO(CTRLS),

                                                                                                                                _______,                 _______,
                                                                                                                                                         _______,
                                                                                                       _______,                 _______,                 _______,

    // right hand
    _______,                KC_F6,                   KC_F7,                   KC_F8,                   KC_F9,                   KC_F10,                  KC_F11,
    _______,                CC_BSLS,                 CSA_LESS,                CSA_GRTR,                CSA_LBRC,                CSA_RBRC,                KC_F12,
                            CC_SLSH,                 KC_LPRN,                 KC_RPRN,                 CSA_LCBR,                CSA_RCBR,                _______,
    _______,                CC_PIPE,                 KC_MINUS,                KC_UNDS,                 KC_PLUS,                 KC_EQUAL,                _______,
                                                     _______,               _______,                 _______,                 _______,                 _______,

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
 * |        |  à   |  è   |  é   |  î   |  ï   |------|           |------|  /   |  4   |  5   |  6   |  =   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  æ   |  œ   |  ç   |      |      |      |           |      |  *   |  1   |  2   |  3   |  0   |        |
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
    _______,                CC_AE,                   CC_OE,                   CSA_CCED,                _______,                 _______,                 _______,
    _______,                _______,                 _______,                 _______,                 _______,

                                                                                                                                _______,                 _______,
                                                                                                                                                         _______,
                                                                                                       _______,                 _______,                 _______,

    // right hand
    _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
    _______,                KC_PMNS,                 KC_7,                    KC_8,                    KC_9,                    KC_PPLS,                 _______,
                            KC_PSLS,                 KC_4,                    KC_5,                    KC_6,                    KC_PEQL,                 _______,
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
    _______,                KC_LSFT,                 KC_LGUI,                 KC_LALT,                 KC_LCTRL,                _______,                 _______,
    _______,                _______,                 _______,                 _______,                 _______,

                                                                                                                                _______,                 _______,
                                                                                                                                                         _______,
                                                                                                       _______,                 _______,                 _______,

    // right hand
    _______,                _______,                 _______,                 _______,                 _______,                 _______,                 _______,
    _______,                KC_WH_D,                 KC_BTN1,                 KC_MS_U,                 KC_BTN2,                 KC_ACL0,                 _______,
                            KC_WH_U,                 KC_MS_L,                 KC_MS_D,                 KC_MS_R,                 KC_ACL2,                 _______,
    _______,                _______,                 KC_RCTRL,                KC_RALT,                 KC_RGUI,                 KC_RSFT,                 _______,
                                                     _______,                 _______,                 _______,                 _______,                 _______,

    _______,                _______,
    _______,
    _______,                _______,                 _______
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
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false; break;

      case RGB_SLD:
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
#endif
        return false; break;

      case CC_GRV:
        HOLD(KC_LALT);
        TAP(CSA_DCRC);
        RELEASE(KC_LALT);
        TAP(KC_SPC);
        return false; break;

      case CC_CIRC:
        TAP(CSA_DCRC);
        TAP(KC_SPC);
        return false; break;

      case CC_TILD:
        HOLD(KC_LALT);
        TAP(CSA_CCED);
        RELEASE(KC_LALT);
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
