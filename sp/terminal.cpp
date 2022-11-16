//
// Created by Wan Luan Lee on 10/27/22.
//
#include "terminal.hpp"

Terminal::Terminal(std::string name, int x, int y) : _name(name), _x(x), _y(y) {
}

int Terminal::get_x() {
  return _x;
}

int Terminal::get_y() {
  return _y;
}

std::string Terminal::get_name() {
  return _name;
}
