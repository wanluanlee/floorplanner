//
// Created by Wan Luan Lee on 10/29/22.
//

#ifndef PA2_SEQUENCE_PAIR_HPP
#define PA2_SEQUENCE_PAIR_HPP

#include "block.hpp"
#include <limits>
#include <random>
#include <algorithm>
#include <map>

namespace sqp {
    struct Edge {
        Block* from;
        Block* to;
        int weight;
    };

    class Sequence_pair {
    public:
        Sequence_pair();
        ~Sequence_pair();
        void init_graph(int num_graph);
        std::vector<int> get_h_distance();
        std::vector<int> get_v_distance();
        std::pair<std::vector<Block*>, std::vector<Block*>> get_new_sequence(std::map<std::string, Block>& all_blocks);
        void sequence_to_graph(std::vector<Block*> ps, std::vector<Block*> ns, std::map<std::string, Block>& all_blocks);
    private:
        int _num_blocks = 0;
        Block* _source;
        Block* _sink;
        std::vector<Block*> _ps;
        std::vector<Block*> _ns;
        std::vector<int> _h_distance;
        std::vector<int> _v_distance;
        std::vector<std::vector<Edge>> _horiztional_adjlist = {};
        std::vector<std::vector<Edge>> _vertical_adjlist = {};
        void _add_edge(Block *from, Block *to, int orientation, std::vector<std::vector<Edge>>& adj_list);
        void _add_source_sink(std::map<std::string, Block>& all_blocks);
        int _index_in_ps(Block *block, std::vector<Block*>& positive_sequence);
        int _index_in_ns(Block *block, std::vector<Block*>& negative_sequence);
        void _reset_adjlist();
        std::vector<int> _longest_path(std::vector<std::vector<Edge>>& adjlist);
    };

}
#endif //PA2_SEQUENCE_PAIR_HPP
