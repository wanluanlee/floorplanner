//
// Created by Wan Luan Lee on 10/11/22.
//

#ifndef PA2_CIRCUIT_HPP
#define PA2_CIRCUIT_HPP
#include <string>
#include <map>
#include "block.hpp"
#include "net.hpp"
#include "terminal.hpp"
#include "sequence_pair.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <chrono>
#include <algorithm>

namespace sqp {
    class Circuit {

    public:
        Circuit(const float alpha, const std::string& out_path);
        int parse_blocks(const std::string& block_file);
        int parse_nets(const std::string& net_file);
        void minimize_cost();
        void dump(const std::string& out_file_name);
        void visual_tool();

    private:

        int _outline_width = 0;
        int _outline_height = 0;
        int _num_blocks = 0;
        int _num_terminals = 0;
        int _num_nets = 0;
        int _init_area = 1; //sum of all block areas
        int _init_wirelength = 1;
        float _init_penality = 1;
        float _penality_ratio = 1;
        const float _alpha;
        const std::string _out_path;

        std::vector<Block*> _current_ps = {};
        std::vector<Block*> _current_ns = {};
        std::vector<int> _current_height = {};
        std::vector<int> _current_width = {};
        int _current_cost;

        std::vector<Block*> _prev_ps = {};
        std::vector<Block*> _prev_ns = {};
        std::vector<int> _prev_height = {};
        std::vector<int> _prev_width = {};
        int _prev_cost;

        std::vector<Block*> _best_ps = {};
        std::vector<Block*> _best_ns = {};
        std::vector<int> _best_height = {};
        std::vector<int> _best_width = {};
        int _best_cost;

        Sequence_pair _sp;
        unsigned _seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::map<std::string, Block> _all_blocks = {};
        std::map<std::string, Terminal> _all_terminals = {};
        std::vector<net> _all_nets = {};
        float _calculate_wirelength(std::vector<int>& xs, std::vector<int>& ys); //use HPWL to estimate
        float _calculate_cost(std::vector<int>& xs, std::vector<int>& ys);
        float _calculate_penalty(std::vector<int>& xs, std::vector<int>& ys);
        std::pair<std::vector<Block*>, std::vector<Block*>>  _get_init_solution();
        std::pair<std::vector<Block*>, std::vector<Block*>>  _get_new_solution(int num_attemp);
        void _accept_move();
        void _reverse_move();
        void _update_all();
        void _update_best();

    };

}
#endif //PA2_CIRCUIT_HPP
