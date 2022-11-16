//
// Created by Wan Luan Lee on 10/27/22.
//

#ifndef PA2_TERMINAL_HPP
#define PA2_TERMINAL_HPP
#include "string"
class Terminal {
public:
  Terminal(std::string name, int x, int y);
  int get_x();
  int get_y();
  std::string get_name();
private:
  std::string _name;
  const int _x;
  const int _y;
};

#endif //PA2_TERMINAL_HPP
