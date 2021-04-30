#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS 10

void getRange(int* startNum, int* endNum) {
  printf("Enter the starting number: ");
  scanf(" %d", startNum);

  do {
    printf("Enter the ending number: ");
    scanf(" %d", endNum);
  } while (*endNum < *startNum);
}

int charToInt(char digit) {
  return digit - '0';
}

void getFrequencies(const char* snum, int* frequencyTable) {
  for (int i = 0; i < strlen(snum); i++) {
    frequencyTable[charToInt(snum[i])]++;
  }
}

void initializeFrequencyTable(int* frequencyTable) {
  for (int i = 0; i < DIGITS; i++) {
    frequencyTable[i] = 0;
  }
}

int* buildFrequencyTable(const int startNum, const int endNum) {
  int* frequencyTable = (int*)malloc(DIGITS * sizeof(int));
  initializeFrequencyTable(frequencyTable);

  for (int i = startNum; i <= endNum; i++) {
    char snum[10];
    sprintf(snum, "%d", i);
    getFrequencies(snum, frequencyTable);
  }

  return frequencyTable;
}

void displayFrequencyTable(int* frequencyTable) {
  for (int i = 0; i < DIGITS; i++) {
    printf("%d is painted %d time/s\n", i, frequencyTable[i]);
  }
}

int main() {
  int startNum, endNum;
  getRange(&startNum, &endNum);

  int* frequencyTable = buildFrequencyTable(startNum, endNum);
  displayFrequencyTable(frequencyTable);
  free(frequencyTable);

  return 0;
}
