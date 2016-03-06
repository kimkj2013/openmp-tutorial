#include <iostream>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./forhello [INTLITERAL]" << std::endl;
    return EXIT_FAILURE;
  }

  #pragma omp parallel for
  for (int i = 1; i <= std::atoi(argv[1]); i++) {
    std::cout << "Hello, world! " << i << " time(s)." << std::endl;
  }
  return 0;
}
