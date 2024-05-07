#include <src/pws/MPI/hello_mpi.hpp>
#include <src/pws/lib.hpp>

#include <fmt/format.h>

#include <iostream>
#include <tuple>
#include <vector>

int main(int argc, char **argv) {
  std::vector<double> input = {1.2, 2.3, 3.4, 4.5};

  auto [mean, moment] = accumulate_vector(input);

  fmt::print("Mean: {}, Moment: {}\n", mean, moment);

  hello_mpi(argc, argv);

  return 0;
}
