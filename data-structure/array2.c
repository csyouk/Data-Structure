#include <stdio.h>
#include <time.h>

clock_t start, end, start2, end2;

double cpu_time_used;
double cpu_time_used2;


int main() {

  // Case 1

  // create element 100,000 array.
  int SIZE = 100000;
  int n[SIZE];

  // initialize
  for (size_t i = 0; i < SIZE - 1; i++) {
    n[i] = i;
  }

  start = clock();
  for (size_t i = 0; i < SIZE; i++) {
    n[i+1] = n[i];
  }
  n[0] = 1000;

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time used in add one element in first of array. %lf\n", cpu_time_used);


  /// Case 2
  int SIZE2 = 1000000;
  int n2[SIZE2];

  // initialize
  for (size_t i = 0; i < SIZE2 - 1; i++) {
    n2[i] = i;
  }

  start2 = clock();
  for (size_t i = 0; i < SIZE2; i++) {
    n2[i+1] = n2[i];
  }
  n2[0] = 1000;
  end2 = clock();
  cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
  printf("Time used in add one element in first of array. %lf\n", cpu_time_used2);


  // Case 1 and Case 2 of executing time is same.
  // It takes time O(1)

  return 0;

}
