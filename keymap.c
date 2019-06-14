#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Keymap layers
enum planck_layers {
  QWERTY_LAYER,
  COLEMAK_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  NAV_LAYER,
  GUI_LAYER,
  STENO_LAYER,
  ADJUST_LAYER
};

// Dashes (macOS)
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))

// Window manager keys
#define WM_FULL LALT(LGUI(KC_F))
#define WM_NEXT LCTL(LALT(LGUI(KC_RGHT)))
#define WM_PREV LCTL(LALT(LGUI(KC_LEFT)))
#define WM_NW   LCTL(LGUI(KC_LEFT))
#define WM_N    LALT(LGUI(KC_UP))
#define WM_NE   LCTL(LGUI(KC_RGHT))
#define WM_E    LALT(LGUI(KC_RGHT))
#define WM_SE   S(LCTL(LGUI(KC_RGHT)))
#define WM_S    LALT(LGUI(KC_DOWN))
#define WM_SW   S(LCTL(LGUI(KC_LEFT)))

#define WM_W    LALT(LGUI(KC_LEFT))
#define WM_CNTR LALT(LGUI(KC_C))

// Custom key codes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  STENO,
  PV_EXIT,
  PV_LOOK,
  SEND_VERSION,
  SEND_MAKE
};

#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)

#define GUI_L LT(GUI_LAYER, KC_LBRC)
#define GUI_R LT(GUI_LAYER, KC_RBRC)

#define NAV_SCLN LT(NAV_LAYER, KC_SCLN)
#define NAV_SPC  LT(NAV_LAYER, KC_SPC)
#define NAV_O    LT(NAV_LAYER, KC_O)

#ifdef RGB_MATRIX_ENABLE
#define LIT_TOG RGB_TOG
#define LIT_DEC RGB_VAD
#define LIT_INC RGB_VAI
#else
#define LIT_TOG BL_TOGG
#define LIT_DEC BL_DEC
#define LIT_INC BL_INC
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ DEL │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │; Nav│  '  │ -- Tap for Enter
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *             -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *   Tap for [ -- │ GUI │CTRL │  ⌥  │  ⌘  │  ↓  │   Space   │  ↑  │  ⌘  │  ⌥  │Hyper│ GUI │ -- Tap for ]
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   *                        /                                                     /
   *   Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_ortho_4x12(
    KC_TAB,        KC_Q,           KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,           KC_DEL,
    CTL_T(KC_ESC), KC_A,           KC_S,    KC_D,    KC_F,  KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    NAV_SCLN,       KC_QUOT,
    KC_LSFT,       KC_Z,           KC_X,    KC_C,    KC_V,  KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,        RSFT_T(KC_ENT),
    GUI_L,         CTL_T(KC_RBRC), KC_LALT, KC_LGUI, LOWER, NAV_SPC, KC_BSPC, RAISE, KC_RGUI, KC_RALT, ALL_T(KC_LBRC), GUI_R
  ),

  /* Base layer (Colemak)
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │     │  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │O Nav│     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │  Z  │  X  │  C  │  V  │  B  │  K  │  M  │     │     │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │           │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [COLEMAK_LAYER] = LAYOUT_ortho_4x12(
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    NAV_O,   _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Numeric layer
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * Application    │  `  │  1  │  2  │  3  │  4  │  5  │ [   │  ]  │ (   │  )  │ F10 │  #  │
   *      window    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    switcher -- │ ⌘-` │  6  │  7  │  8  │  9  │  0  │  {  │  }  │  -  │  =  │  \  │  `  │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │enter│  -  │  =  │  `  │  \  │  :  │  (  │  )  │  ,  │  \  │  /  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │ Backspace │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_ortho_4x12(
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_LBRC,   KC_RBRC,   KC_LPRN,   KC_RPRN,   KC_F10,  S(KC_3),
    LGUI(KC_GRV),      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    S(KC_LBRC),    S(KC_RBRC),    KC_MINS,    KC_EQL,    KC_BSLS,    KC_GRV,
    KC_ENT,      KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_COLN, KC_LPRN, KC_RPRN, KC_COMM, KC_BSLS,  KC_SLSH, _______,
    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Symbol layer
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │  ~  │  !  │  @  │  #  │  $  │  %  │  -  │  =  │  _  │  +  │ F20 │  #  │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │  ^  │  &  │  *  │  (  │  )  │  ^  │  &  │  _  │  +  │  |  │  ~  │ \
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  |-- Mostly shifted version
   *                │     │  _  │  +  │  ~  │  |  │  :  │ndash│mdash│  ,  │  .  │  /  │     │ /    of lower layer
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │  Delete   │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_ortho_4x12(
    KC_TILD, S(KC_1),  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  KC_MINS,  KC_EQL,  KC_UNDS,  KC_PLUS,  KC_F20,     S(KC_3),
    _______, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_6), S(KC_7), S(KC_MINS), KC_PLUS, S(KC_BSLS), KC_TILD,
    _______, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_COLN, KC_NDSH, KC_MDSH, KC_COMM, KC_DOT,  KC_SLSH,    _______,
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______, _______, _______,    _______
  ),

  /* Directional navigation layer
   *
   *         Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │     │     │     │     │     │     │GUI L│GUI R│     │     │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │     │     │     │     │     │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │           │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NAV_LAYER] = LAYOUT_ortho_4x12(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGUI(KC_LBRC), RGUI(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    _______, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NAV_SCLN, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
    _______, _______, _______, _______, XXXXXXX, NAV_SPC, XXXXXXX, XXXXXXX, _______, _______, _______,  _______
  ),

  /* GUI (window management/mouse/media controls) layer
   *
   *        Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │     │Ms B2│Ms Up│Ms B1│Ms WD│     │     │Prev │ NW  │  N  │ NE  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │Ms L │Ms Dn│Ms R │Ms WU│     │     │Full │  W  │Centr│  E  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │Undo │ Cut │Copy │Paste│     │     │Next │ SW  │  S  │ SE  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │Prev │Play │Next │Brig-│   Sleep   │Brig+│Mute │Vol- │Vol+ │     │
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   *                        \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
   */
  [GUI_LAYER] = LAYOUT_ortho_4x12(
    _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX, XXXXXXX, WM_PREV, WM_NW,   WM_N,    WM_NE,   _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX, XXXXXXX, WM_FULL, WM_W,    WM_CNTR, WM_E,    _______,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX, WM_NEXT, WM_SW,   WM_S,    WM_SE,   _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_SLCK, KC_SLEP, KC_WAKE, KC_PAUS, KC_MUTE, KC_VOLD, KC_VOLU, _______
  ),

  /* Keyboard settings layer
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *    Firmware -- │     │Reset│Make │     │     │     │     │     │     │     │Vers │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *         RGB -- │Qwert│     │     │Mode-│Mode+│Hue +│Hue -│Sat +│Sat -│Val +│Val -│     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *       Audio -- │Colem│Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│     │     │Aud +│Aud -│     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │Steno│     │Swap │Norm │     │  Toggle   │     │Toggl│Brig-│Brig+│     │
   *                └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   *               Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [ADJUST_LAYER] = LAYOUT_ortho_4x12(
    XXXXXXX, RESET,   SEND_MAKE, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SEND_VERSION, XXXXXXX,
    QWERTY,  XXXXXXX, XXXXXXX,   RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX,      XXXXXXX,
    COLEMAK, MUV_DE,  MUV_IN,    MU_ON,    MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,       XXXXXXX,
    STENO,   XXXXXXX, AG_SWAP,   AG_NORM,  LOWER,   LIT_TOG, LIT_TOG, RAISE,   LIT_TOG, LIT_DEC, LIT_INC,      XXXXXXX
  )
};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(QWERTY_LAYER);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(COLEMAK_LAYER);
      }
      return false;
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
  // Disable middle LED between keys in grid layout.
  rgb_matrix_set_color(42, 0, 0, 0);
}
#endif
