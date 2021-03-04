#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool IsIsogram(char* str) {
  bool isogram = true;
  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; i < len; i++) {
      if (toupper(str[i]) == toupper(str[j])) {
        isogram = false;
        break;
      }
    }
    if (!isogram) {
      break;
    }
  }
  return isogram;
}

int main() {
  char* str = "Terminal";

  if (IsIsogram(str)) {
    printf("Isogram!");
  } else {
    puts("Not an isogram!");
  }
  return 0;
}
