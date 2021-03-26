#include <stdio.h>

int rowSumOddNumbers(int row) {
  return row * row * row;
}

int main() {
  printf("%d", rowSumOddNumbers(2));
}
