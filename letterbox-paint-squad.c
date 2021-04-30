#include <stdio.h>

#DEFINE DIGITS 10

void getRange(int* startNum, int* endNum) {
  printf("Enter the starting number: ");
  scanf(" %d", startNum);

  do {
    printf("Enter the ending number: ");
    scanf(" %d", endNum);
  } while (*endNum < *startNum);
}

int main() {
  int startNum, endNum;
  getRange(&startNum, &endNum);

  int frequency[DIGITS];

  return 0;
}
