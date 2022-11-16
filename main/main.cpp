#include <iostream>
#include "../sp/circuit.hpp"

int main(int argc, char** argv) {
  sqp::Circuit circuit(std::stod(argv[1]), argv[4]);
  circuit.parse_blocks(argv[2]);
  circuit.parse_nets(argv[3]);
  //double alpha = std::stod(argv[1]);
  circuit.minimize_cost();
  circuit.visual_tool();
  return 0;
}
