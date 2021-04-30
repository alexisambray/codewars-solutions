#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#DEFINE DIGITS 10

void getRange(int* startNum, int* endNum) {
  printf("Enter the starting number: ");
  scanf(" %d", startNum);

  do {
    printf("Enter the ending number: ");
    scanf(" %d", endNum);
  } while (*endNum < *startNum);
}

int* buildFrequencyTable(const int startNum, const endNum) {
  int* frequencyTable = (int*)malloc(DIGITS * sizeof(int));

  for (int i = startNum; i <= endNum; i++) {
    char snum[10];  
    sprintf(snum, %d, num);
    getFrequencies(snum, frequencyTable);
  }

  return frequencyTable;
}

void getFrequencies(const char* snum, int* frequencyTable) {
  for (int i = 0; i < strlen(snum); i++) {
    frequencyTable[charToInt(snum[0])]++;
  }
}

int charToInt(char digit) {
  return digit - '0';
}

int main() {
  int startNum, endNum;
  getRange(&startNum, &endNum);

  int* frequencyTable;
  buildFrequencyTable(startNum, endNum);

  return 0;
}

/* 
310 START
311
312
313
314
315 END

0 --> 0
1 --> 0
2 --> 0
3 --> 0
4 --> 0
5 --> 0
6 --> 0
7 --> 0
8 --> 0
9 --> 0
*/
