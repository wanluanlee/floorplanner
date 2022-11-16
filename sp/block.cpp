//
// Created by Wan Luan Lee on 10/11/22.
//

#include "block.hpp"

namespace sqp {
    Block::Block(std::string name, int id, int width, int height): _name{name}, _id{id}, _width{width}, _height{height}{

    }

    std::string Block::get_name() {
        return _name;
    }

    int Block::get_id() {
        return _id;
    }

    int Block::get_width() {
        return _width;
    }

    int Block::get_height() {
        return _height;
    }

    void Block::switch_width_hight() {
        int width = _width;
        _width = _height;
        _height = width;
    }

    void Block::set_width(int width) {
        _width = width;
    }

    void Block::set_height(int height) {
        _height = height;
    }
}