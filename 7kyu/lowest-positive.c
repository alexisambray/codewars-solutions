#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

long sum_two_smallest_numbers(size_t n, const int numbers[n]);

long sum_two_smallest_numbers(size_t n, const int numbers[n]) {
  int current_low1;  // if first 2 are the lowest
  int current_low2;  // lowest number

  int comparison1;
  int comparison2;
  // every new value in array to be compared with
  // then define - if new values are lesser
  // and if so - find out if its new value is the lowest
  if (numbers[0] < numbers[1]) {
    current_low1 = numbers[0];
    current_low2 = numbers[1];
  } else {
    current_low1 = numbers[1];
    current_low2 = numbers[0];
  }
  int ind;  // indeterminate (not precisely determined)
  for (ind = 2; (unsigned long)ind < n; ind++) {
    if ((numbers[ind] < current_low1) && (numbers[ind] < current_low2)) {
      comparison1 = current_low1 - numbers[ind];
      comparison2 = current_low2 - numbers[ind];
      if (comparison1 > comparison2) {
        current_low1 = numbers[ind];
      } else {
        current_low2 = numbers[ind];
      }
    } else if ((numbers[ind] >= current_low1) &&
               (numbers[ind] < current_low2)) {
      current_low2 = numbers[ind];
    } else if ((numbers[ind] < current_low1) &&
               (numbers[ind] >= current_low2)) {
      current_low1 = numbers[ind];
    }
  }

  return (unsigned long)(current_low1 + current_low2);
}

int main() {
  int i, n;
  int displayNum;
  int* numbers;

  printf("How many numbers would you like to enter? ");
  scanf("%d", &displayNum);

  numbers = (int*)malloc(displayNum * sizeof(int));

  for (i = 0; i < displayNum; i++) {
    printf("Enter number #%d: ", (i + 1));
    scanf("%d", numbers + 1);
  }

  printf("The sum of the two lowest numbers is %" PRIu64,
         sum_two_smallest_numbers(n, numbers));

  return 0;
}
