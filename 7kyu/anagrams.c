#include <stdio.h>
#include <string.h>

void convertLowercase(char letter[]) {
  int nextLetter;

  for (nextLetter = 0; nextLetter < strlen(letter) - 1; nextLetter++) {
    letter[nextLetter] = letter[nextLetter] + 32;
  }
}

void sortArray(char letter[]) {
  int temp = 0, b, c;

  for (b = 0; b < strlen(letter) - 1; b++) {
    for (c = b + 1; c < strlen(letter); c++) {
      if (letter[b] > letter[c]) {
        temp = letter[b];
        letter[b] = letter[c];
        letter[c] = temp;
      }
    }
  }
}

int main() {
  char string1[] = "Loop";
  char string2[] = "Pool";

  char i, j = 0;
  // If strings have different lengths, then they are not anagrams!

  char n = strlen(string1);
  char n1 = strlen(string2);

  if (n != n1) {
    printf("Strings are not anagram");
    return 0;
  } else {
    // String convert to lowercase
    convertLowercase(string1);
    convertLowercase(string2);
    // Sort both strings
    sortArray(string1);
    sortArray(string2);
    // Compare both strings character by character
    for (i = 0; i < n; i++) {
      if (string1[i] != string2[i]) {
        printf("Strings are not anagram!");
        return 0;
      }
    }
    printf("Strings are anagram!");
  }
  return 0;
}
