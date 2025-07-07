#include "mergesort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_SIZE 10
#define SEED 42

bool check_sorted(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

void print_array(const int *arr, int size) {
  printf("[");
  for (int i = 0; i < size - 1; i++)
    printf("%d ", arr[i]);
  printf("%d]\n", arr[size - 1]);
}

void test(int seed) {}
int main(int argc, char *argv[]) {
  printf("[ INFO ] Running Test with %d elements:\n", TEST_SIZE);

  // constructing array for tests
  int serial_arr[TEST_SIZE], parallel_arr[TEST_SIZE];
  srand(SEED);
  for (int i = 0; i < TEST_SIZE; i++) {
    int v = rand() % 100;
    serial_arr[i] = parallel_arr[i] = v;
  }

#ifdef DEBUG
  printf("[ DEBUG ] Original:\t\t");
  print_array(serial_arr, TEST_SIZE);
#endif

  // NOTE: Serial Test
  merge_sort_sequential(serial_arr, 0, TEST_SIZE);

  if (check_sorted(serial_arr, TEST_SIZE)) {
    printf("[ SUCCESS ] Serial Sort Verified\n");
  } else {
    printf("[ FAIL ] Serial Array was not sorted\n");
  }
#ifdef DEBUG
  printf("[ DEBUG ] Serial Sort:\t\t");
  print_array(serial_arr, TEST_SIZE);
#endif

  // NOTE: Parallel Test
  merge_sort_parallel(parallel_arr, 0, TEST_SIZE);

  if (check_sorted(parallel_arr, TEST_SIZE)) {
    printf("[ SUCCESS ] Parallel Sort Verified\n");
  } else {
    printf("[ FAIL ] Parallel Array was not sorted\n");
  }

#ifdef DEBUG
  printf("[ DEBUG ] Parallel Sort:\t");
  print_array(serial_arr, TEST_SIZE);
#endif

  return 0;
}
