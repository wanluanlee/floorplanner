//
// Created by Wan Luan Lee on 10/11/22.
//

#ifndef PA2_BLOCK_HPP
#define PA2_BLOCK_HPP

#include <vector>
#include "string"

namespace sqp {
  class Block {
  public:
    Block(std::string name, int id, int width, int height);
    std::string get_name();
    void switch_width_hight();
    int get_width();
    int get_height();
    int get_id();
    void set_width(int witdh);
    void set_height(int height);
    int x_slack = 0;
    int y_slack = 0;

  private:
    int _id;
    std::string _name;
    int _width = 0;
    int _height = 0;
  };
}


#endif //PA2_BLOCK_HPP
