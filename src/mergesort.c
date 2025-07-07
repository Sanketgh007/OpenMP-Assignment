#include "mergesort.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + i];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
  free(L);
  free(R);
}

void merge_sort_sequential(int *arr, int left, int right) {
  if (right - left <= 1)
    return;
  int mid = (left + right) / 2;
  merge_sort_sequential(arr, left, mid);
  merge_sort_sequential(arr, mid, right);
  merge(arr, left, mid, right);
}

void merge_sort_parallel_internal(int *arr, int left, int right) {
  if (right - left <= 1)
    return;
  int mid = (left + right) / 2;
#pragma omp task shared(arr)
  merge_sort_parallel_internal(arr, left, mid);
#pragma omp task shared(arr)
  merge_sort_parallel_internal(arr, mid, right);
#pragma omp taskwait
  merge(arr, left, mid, right);
}

void merge_sort_parallel(int *arr, int left, int right) {

// NOTE: This part need not be modified, the parallel and single
// constructs creates the threads.
#pragma omp parallel
#pragma omp single
  {
    // the main sorting logic will be in this function.
    merge_sort_parallel_internal(arr, left, right);
  }
}
