#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int compar(const int* p1, const int* p2) {
  return *p1 - *p2;
}

int sum_two_smallest_numbers(size_t n, int* numbers) {
  qsort(numbers, n, sizeof(int), compar);
  return numbers[0] + numbers[1];
}

int main() {
  int size;
  int* numbers;

  printf("How many numbers would you like to enter? ");
  scanf("%d", &size);

  numbers = (int*)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    printf("Enter number #%d: ", (i + 1));
    scanf("%d", &numbers[i]);
  }

  printf("The sum of the two lowest numbers is %d",
         sum_two_smallest_numbers(size, numbers));

  return 0;
}
