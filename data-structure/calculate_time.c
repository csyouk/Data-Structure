#include <stdio.h>
#include <time.h>

clock_t start, end;

double cpu_time_used;


int main() {

  start = clock();
  printf("Hello, World! \n");
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("time used in printing %lf\n", cpu_time_used);
  return 0;
}
