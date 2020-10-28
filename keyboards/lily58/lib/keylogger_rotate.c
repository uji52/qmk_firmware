#include <stdio.h>
#include "action.h"
#include "lily58.h"

#define STRING_HISTORY_LENGTH 20

char keylog_str[24] = {};
char keylogs_str[24] = {};
char keylogs_count_str[24] = {};
int keylogs_count = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_count < STRING_HISTORY_LENGTH) {
    keylogs_str[keylogs_count] = name;
  } else {
    for (int i = 1; i < STRING_HISTORY_LENGTH; i++) {
      keylogs_str[i-1] = keylogs_str[i];
    }
    keylogs_str[STRING_HISTORY_LENGTH - 1] = name;
  }

  // update keylog count
  keylogs_count++;
  snprintf(keylogs_count_str, sizeof(keylogs_count_str), "%d key push.", keylogs_count);
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

const char *read_keylogs_count(void) {
  return keylogs_count_str;
}

