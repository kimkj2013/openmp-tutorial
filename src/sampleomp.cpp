/*
Codes are copied-pasted from Wikipedia for testing and educational purpose.

http://en.wikipedia.org/wiki/OpenMP#C.2B.2B

Must be compiled using this command: g++ -std=c++11 -Wall -Wextra -Werror -fopenmp sampleomp.cpp -o sampleomp
*/

#include <iostream>
#include <omp.h>

int main()
{
  int th_id, nthreads;
  #pragma omp parallel private(th_id) shared(nthreads)
  {
    th_id = omp_get_thread_num();
    #pragma omp critical
    {
      std::cout << "Hello World from thread " << th_id << '\n';
    }
    #pragma omp barrier

    #pragma omp master
    {
      nthreads = omp_get_num_threads();
      std::cout << "There are " << nthreads << " threads" << '\n';
    }
  }

  return 0;
}
