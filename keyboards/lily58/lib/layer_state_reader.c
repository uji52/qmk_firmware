
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_ADJUST (1 << 3)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
  case L_BASE+1:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer-%ld: Default", layer_state);
    break;
  case L_RAISE:
  case L_RAISE+1:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer-%ld: Raise", layer_state);
    break;
  case L_LOWER:
  case L_LOWER+1:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer-%ld: Lower", layer_state);
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer-%ld: Adjust", layer_state);
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer-%ld: Undef", layer_state);
  }

  return layer_state_str;
}
