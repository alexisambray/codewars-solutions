#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* disenvowel(const char* str) {
  int numVowels = 0;  // accumulator

  for (int i = 0; i < strlen(str); i++) {
    char letter = toupper(str[i]);

    switch (letter) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        numVowels++;
    }
  }

  int disenvoweled_size = strlen(str) - numVowels;  // size of elements
  char* disenvoweled_str = (char*)malloc((disenvoweled_size + 1) *
                                         sizeof(char));  // size of data type

  for (int i = 0; i <= disenvoweled_size; i++) {  // initializes the string
    disenvoweled_str[i] = '\0';
  }
  // char* disenvoweled_str =
  //     (char*)calloc((strlen(str) - numVowels + 1), sizeof(char));

  for (int i = 0; i < strlen(str); i++) {
    char letter = toupper(str[i]);

    switch (letter) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        break;
      default:
        strncat(disenvoweled_str, &str[i], 1);
    }
  }
  // free(disenvoweled_str); // use free to free up memory allocated by malloc
  return disenvoweled_str;
}

int main() {
  puts(disenvowel("This website is for losers LOL!"));
}
