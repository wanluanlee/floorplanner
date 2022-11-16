//
// Created by Wan Luan Lee on 10/11/22.
//

#ifndef PA2_NET_HPP
#define PA2_NET_HPP

#include "vector"
#include "block.hpp"
#include "terminal.hpp"

namespace sqp {
    class net {
    public:
        net(const int id, int _num_degree);
        void insert_block(Block* block);
        void insert_terminal(Terminal* term);
        std::vector<Block*> get_connected_block();
        std::vector<Terminal*> get_connected_terminal();
    private:
        const int _id;
        int _num_degree = 0;
        std::vector<Block*> _connected_block = {};
        std::vector<Terminal*> _connected_terminal = {};

    };
}


#endif //PA2_NET_HPP
