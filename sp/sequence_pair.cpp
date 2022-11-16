//
// Created by Wan Luan Lee on 10/29/22.
//

#include <queue>
#include <iostream>
#include "sequence_pair.hpp"

namespace sqp {
  Sequence_pair::Sequence_pair() {

  }
  Sequence_pair::~Sequence_pair() {
    delete(_source);
    delete(_sink);
  }

  void Sequence_pair::init_graph(int num_block) {
    _num_blocks = num_block;
    _source = new Block("source", 0, 0, 0);
    _sink = new Block("sink", _num_blocks + 1, 0, 0);
  }
    //orientation = 0 for horiztiontal graph
    //ortation = 1 for vertical graph
  void Sequence_pair::_add_edge(Block* from, Block* to, int orientation, std::vector<std::vector<Edge>>& adj_list) {
    Edge new_edge;
    new_edge.from = from;
    new_edge.to = to;
    if(orientation == 0) {
      new_edge.weight = from->get_width() * -1;
      //check if exisit
      bool if_found = false;
      for(auto&& i:adj_list.at(from->get_id())) {
        if(i.from == from && i.to == to) {if_found = true;}
      }
      if(if_found == false) {adj_list.at(from->get_id()).push_back(new_edge);}
    }
    else {
      new_edge.weight = from->get_height() * -1;
      bool if_found = false;
      for(auto&& i : adj_list.at(from->get_id())) {
        if(i.from == from && i.to == to) {if_found = true;}
      }
      if(if_found == false) {adj_list.at(from->get_id()).push_back(new_edge);}}
  }

  int Sequence_pair::_index_in_ps(Block *block, std::vector<Block*>& positive_sequence) {
      for (int i = 0; i < positive_sequence.size(); ++i) {
        if (positive_sequence.at(i)->get_name() == block->get_name()) {
          return i;
        }
      }
      return -1;
  }

  int Sequence_pair::_index_in_ns(Block *block, std::vector<Block*>& negative_sequence) {
      for (int i = 0; i < negative_sequence.size(); ++i) {
        if (negative_sequence.at(i)->get_name() == block->get_name()) {
          return i;
        }
      }
      return -1;
  }

  void Sequence_pair::_add_source_sink(std::map<std::string, Block>& all_blocks) {
    for(auto&& i : all_blocks) {
      Edge horizontal_source_edge = {_source, &i.second, 0};
      Edge vertical_source_edge = {_source, &i.second, 0};
      Edge horizontal_target_edge = {&i.second, _sink, i.second.get_width() * -1};
      Edge vertical_target_edge = {&i.second, _sink, i.second.get_height() * -1};
      _horiztional_adjlist.at(0).push_back(horizontal_source_edge);
      _horiztional_adjlist.at(i.second.get_id()).push_back(horizontal_target_edge);
      _vertical_adjlist.at(0).push_back(vertical_source_edge);
      _vertical_adjlist.at(i.second.get_id()).push_back(vertical_target_edge);
    }
  }

  void Sequence_pair::_reset_adjlist() {
    _horiztional_adjlist.clear();
    _vertical_adjlist.clear();
    _horiztional_adjlist.resize(_num_blocks+2);
    _vertical_adjlist.resize(_num_blocks+2);
  }

    /*create horizontal and vertical edges from sequence pair */
  void Sequence_pair::sequence_to_graph(std::vector<Block*> ps, std::vector<Block*> ns, std::map<std::string, Block>& all_blocks)
  {
    _ps = ps;
    _ns = ns;
    _reset_adjlist();
    for (auto&& i: all_blocks) {
      for (auto&& j: all_blocks) {
        if (i.second.get_name() != j.second.get_name()) {
          int i_index_in_ps = _index_in_ps(&i.second, _ps);
          int i_index_in_ns = _index_in_ns(&i.second, _ns);
          int j_index_in_ps = _index_in_ps(&j.second, _ps);
          int j_index_in_ns = _index_in_ns(&j.second, _ns);
          //if i is after j in both sequence
          if (i_index_in_ps > j_index_in_ps && i_index_in_ns > j_index_in_ns) {
            //j.second.insert_block(&i.second, Position::right);
            _add_edge(&j.second, &i.second, 0, _horiztional_adjlist);
            //i.second.insert_block(&j.second, Position::left);
          }
          else if(i_index_in_ps < j_index_in_ps && i_index_in_ns < j_index_in_ns) {
            //j.second.insert_block(&i.second, Position::left);
            _add_edge(&i.second, &j.second, 0, _horiztional_adjlist);
            //i.second.insert_block(&j.second, Position::right);
          }
          else if (i_index_in_ps < j_index_in_ps && i_index_in_ns > j_index_in_ns) {
            _add_edge(&j.second, &i.second, 1, _vertical_adjlist);
            //i.second.insert_block(&j.second, Position::above);
          }
          //a is below b
          else if(i_index_in_ps > j_index_in_ps && i_index_in_ns < j_index_in_ns) {
            //j.second.insert_block(&i.second, Position::left);
            _add_edge(&i.second, &j.second, 1, _vertical_adjlist);
            //i.second.insert_block(&j.second, Position::right);
          }
        }
      }
    }
    _add_source_sink(all_blocks);
  }

  std::vector<int> Sequence_pair::get_h_distance() {
    _h_distance = _longest_path(_horiztional_adjlist);
    for(int i = 0; i < _h_distance.size(); ++i) {
      int current_x = _h_distance.at(i);
      _h_distance.at(i) = current_x * -1;
    }
    return _h_distance;
  }

  std::vector<int> Sequence_pair::get_v_distance() {
    _v_distance = _longest_path(_vertical_adjlist);
    for(int i = 0; i < _v_distance.size(); ++i) {
      int current_y = _v_distance.at(i);
      _v_distance.at(i) = current_y * -1;
    }
    return _v_distance;
  }

  std::vector<int> Sequence_pair::_longest_path(std::vector<std::vector<Edge>>& adjlist) {
    std::vector<int> dist;
    std::vector<int> in_queue;
    dist.resize(_num_blocks+2,std::numeric_limits<int>::max());
    in_queue.resize(_num_blocks+2,false);
    //set source distance = 0;
    dist.at(0) = 0;
    std::queue<Block*> queue;
    queue.push(_source);
    in_queue.at(0) = true;
    while(!queue.empty()) {
      Block* block = queue.front();
      queue.pop();
      in_queue.at(block->get_id()) = false;
      for(auto i : adjlist.at(block->get_id())) {
        if((dist.at(i.from->get_id()) + i.weight) < dist.at(i.to->get_id())) {
          dist.at(i.to->get_id()) = dist.at(i.from->get_id()) + i.weight;
          if(in_queue.at(i.to->get_id()) == false) {
            queue.push(i.to);
            in_queue.at(i.to->get_id()) = true;
          }
        }
      }
    }
    return dist;
  }

  std::pair<std::vector<Block*>, std::vector<Block*>> Sequence_pair::get_new_sequence(std::map<std::string, Block>& all_blocks) {
    //generate random index
    std::vector<int> sol = {0,1,2,3};
    std::vector<Block*> candidates = {};
    for(auto&& i : all_blocks) {
      candidates.push_back(&i.second);
    }
    std::random_shuffle(sol.begin(), sol.end());
    std::random_shuffle(candidates.begin(), candidates.end());
    int solution = sol.at(2);
    Block* first_block = candidates.at(0);
    Block* second_block = candidates.at(1);
    int first_index_ps = _index_in_ps(first_block, _ps);
    int second_index_ps = _index_in_ps(second_block, _ps);
    int first_index_ns = _index_in_ns(first_block, _ns);
    int second_index_ns = _index_in_ns(second_block, _ns);
    if(solution == 0) {
      _ps.at(first_index_ps) = second_block;
      _ps.at(second_index_ps) = first_block;
    }
    if(solution == 1) {
      _ns.at(first_index_ns) = second_block;
      _ns.at(second_index_ns) = first_block;
    }
    //solution = 1, swap a random pair of modules in both sequence
    else if(solution == 2) {
      _ps.at(first_index_ps) = second_block;
      _ps.at(second_index_ps) = first_block;
      _ns.at(first_index_ns) = second_block;
      _ns.at(second_index_ns) = first_block;
    }
    //solution = 2, rotate a randomly selected module
    else if(solution == 3) {
      int first_index_ps = _index_in_ps(first_block, _ps);
      _ps.at(first_index_ps)->switch_width_hight();
    }
    std::pair<std::vector<Block*>,std::vector<Block*>> ps_ns_pair = std::make_pair(_ps, _ns);
    return ps_ns_pair;
  }

}
