//
// Created by Wan Luan Lee on 10/11/22.
//

#include "net.hpp"

namespace sqp {

  net::net(const int id, int num_degree) : _id(id), _num_degree(num_degree) {}

  void net::insert_block(Block *block) {
    _connected_block.push_back(block);
  }

  void net::insert_terminal(Terminal* term) {
    _connected_terminal.push_back(term);
  }

  std::vector<Block*> net::get_connected_block() {
    return _connected_block;
  }

  std::vector<Terminal*> net::get_connected_terminal() {
    return _connected_terminal;
  }
}
