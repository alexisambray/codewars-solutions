#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Accumul.accum("abcd"); // "A-Bb-Ccc-Dddd"
// Repetition time of each alphabet increases by 1

char* accum(const char* source) {
  long len = strlen(source);
  long tlen = len * (len + 1) / 2 + len;  // total length
  char* s = malloc(tlen);                 // malloc stands for memory allocation
  if (s == NULL) {
    return NULL;
  }
  s[tlen - 1] = '\0';  // Repetition time of each alphabet increases by 1

  for (int i = 0; i < len; i++) {
    int start = i * (i + 1) / 2 + i;
    s[start] = toupper(source[i]);  // If the first alphabet is lowercase,
                                    // change it to uppercase

    for (int j = 1; j <= i; j++) {
      s[start + j] =
          tolower(source[i]);  // Change uppercase alphabet to all lowercase
                               // letters except the first alphabet
    }
    if (i < len - 1) {
      s[start + i + 1] = '-';
    }
  }
  return s;
}

int main() {
  const char* source = "NyffsGeyylB";
  const char* expected =
      "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-"
      "Bbbbbbbbbbb";
  char* actual = accum(source);
  printf(expected, actual, "Source: \"%s\" Expected: \"%s\" Actual: \"%s\"",
         source, expected, actual);
  free(actual);
  actual = NULL;
}
