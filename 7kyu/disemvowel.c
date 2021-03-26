#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* disemvowel(const char* str);

int main() {
  printf("Comment: %s\n", disemvowel("This website is for losers LOL!"));

  return 0;
}

char* disemvowel(const char* str) {
  char* output = malloc(strlen(str) + 1);
  char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  int counter = 0;

  while (*(str) != '\0') {
    int letters = 1;

    for (int i = 0; i < 10; i++) {
      if (vowels[i] == *str) {
        letters = 0;
      }
    }
    if (letters) {
      output[counter++] = *str;
    }
    str++;
  }
  output[counter] = '\0';

  return output;
}