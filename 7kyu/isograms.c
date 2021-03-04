#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool IsIsogram(char* str) {
  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (toupper(str[i]) == toupper(str[j])) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char* str = "Terminal";
  if (IsIsogram(str)) {
    puts("Isogram!");
  } else {
    puts("Not an isogram!");
  }
  return 0;
}