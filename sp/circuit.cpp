//
// Created by Wan Luan Lee on 10/11/22.
//

#include "circuit.hpp"
namespace sqp {

    Circuit::Circuit(const float alpha, const std::string& out_path) : _alpha(alpha), _out_path(out_path){
    }

    int Circuit::parse_blocks(const std::string& block_file) {
        std::ifstream infile(block_file);
        std::string str;
        int block_id = 1;
        while (std::getline(infile, str)) {
            std::stringstream line_stream(str);
            std::string word;
            std::vector<std::string> words;
            while (std::getline(line_stream, word, ' ')) {
                if(!word.empty() && (word[word.length() - 1] == '\r' || word[word.length() - 1] == '\n')) {
                    word.erase(word.length() - 1);
                }
                if (word.size() > 0) {
                    words.push_back(word);
                }
            }
            if (words.size() > 0) {
                if (words[0] == "Outline:") {
                    _outline_width = std::stoi(words[1]);
                    _outline_height = std::stoi(words[2]);
                } else if (words[0] == "NumBlocks:") { _num_blocks = std::stoi(words[1]); }
                else if (words[0] == "NumTerminals:") { _num_terminals = std::stoi(words[1]); }
                else if (words[1] == "Terminal") {
                    int x = std::stoi(words[2].substr(0, words[2].find("\t")));
                    words[2].erase(0, words[2].find("\t") + 1);
                    int y = std::stoi(words[2]);
                    Terminal term = Terminal(words[0], x, y);
                    _all_terminals.emplace(words[0], term);
                } else {
                    int width;
                    int height;
                    if(words[0] == "clk") {
                        int z=0;
                    }
                    size_t found = words[1].find("\t");
                    if (found == std::string::npos) {
                        width = std::stoi(words[1]);
                        height = std::stoi(words[2]);
                    } else {
                        if(words.size() == 2) {
                            while (words[1].find("\t") == 0) {
                                words[1].erase(0, 1);
                            }
                            std::cout << words[0] << "\n";
                            std::cout << words[1].substr(0, words[1].find("\t")) << "\n";
                            width = std::stoi(words[1].substr(0, words[1].find("\t")));
                            words[1].erase(0, words[1].find("\t") + 1);
                            height = std::stoi(words[1]);
                        }
                        else {
                            words[1].erase(0, words[1].find("\t") + 1);
                            words[1].erase(0, words[1].find("\t") + 1);
                            //words[1].substr(0, words[1].find("\t"))
                            width = std::stoi(words[1]);
                            words[2].erase(0, words[2].find("\t") + 1);
                            height = std::stoi(words[2]);
                        }
                    }
                    Block block = Block(words[0], block_id, width, height);
                    block_id++;
                    _all_blocks.emplace(words[0], block);
                }
                words.clear();
            }
        }

        _best_width.resize(_num_blocks);
        _best_height.resize(_num_blocks);
        _prev_width.resize(_num_blocks);
        _prev_height.resize(_num_blocks);
        _current_width.resize(_num_blocks);
        _current_height.resize(_num_blocks);
        _sp.init_graph(_num_blocks);
        return 0;
    }

    int Circuit::parse_nets(const std::string& net_file) {
        std::ifstream infile(net_file);
        std::string str;
        int net_id = 0;
        while (std::getline(infile, str)) {
            std::stringstream line_stream(str);
            std::string word;
            std::vector<std::string> words;
            while (std::getline(line_stream, word, ' ')) {
                if (word.size() > 0) {
                    words.push_back(word);
                }
            }
            if (words.size() > 0) {
                if (words[0] == "NumNets:") {
                    _num_nets = std::stoi(words[1]);
                }
                else if (words[0] == "NetDegree:") {
                    net net(net_id, std::stoi(words[1]));
                    _all_nets.push_back(net);
                    net_id++;
                }
                else {
                    if (_all_blocks.find(words[0]) == _all_blocks.end()) {
                        _all_nets.at(net_id - 1).insert_terminal(&_all_terminals.at(words[0]));
                    } else { _all_nets.at(net_id - 1).insert_block(&_all_blocks.at(words[0])); }
                }
                words.clear();
            }
        }
        return 0;
    }

    float Circuit::_calculate_cost(std::vector<int>& xs, std::vector<int>& ys) {
        int chip_width = xs.back();
        int chip_height = ys.back();
        float wirelength = _calculate_wirelength(xs,ys);
        float penalty = _calculate_penalty(xs, ys);
        return _alpha * chip_height * chip_width/_init_area + (1 - _alpha) * wirelength / _init_wirelength
               + _penality_ratio * penalty / _init_penality;
        //return penalty;
    }

    void Circuit::_accept_move() {
        _prev_ps = _current_ps;
        _prev_ns = _current_ns;
        _prev_cost = _current_cost;
        for(auto&& i : _all_blocks) {
            _prev_width[i.second.get_id()] = i.second.get_width();
            _prev_height[i.second.get_id()] = i.second.get_height();
        }
    }

    void Circuit::_reverse_move() {
        _current_ps = _prev_ps;
        _current_ns = _prev_ns;
        _current_cost = _prev_cost;

        for(auto&& i : _all_blocks) {
            _current_width[i.second.get_id()] = i.second.get_width();
            _current_height[i.second.get_id()] = i.second.get_height();
        }
    }

    void Circuit::_update_all() {
        _current_ps = _best_ps;
        _current_ns = _best_ns;
        _current_cost = _best_cost;
        _prev_ps = _best_ps;
        _prev_ns = _best_ns;
        _prev_cost = _best_cost;

        for(auto&& i : _all_blocks) {
            _current_height[i.second.get_id()] = i.second.get_height();
            _current_width[i.second.get_id()] = i.second.get_width();
            _prev_height[i.second.get_id()] = i.second.get_height();
            _prev_width[i.second.get_id()] = i.second.get_width();
        }
    }

    void Circuit::_update_best() {
        _best_ps = _current_ps;
        _best_ns = _current_ns;
        _best_cost = _current_cost;

        for(auto&& i : _all_blocks) {
            _best_height[i.second.get_id()] = i.second.get_height();
            _best_width[i.second.get_id()] = i.second.get_width();
        }
    }

    void Circuit::minimize_cost() {
        std::default_random_engine generator (_seed);
        std::uniform_real_distribution<double> distribution (0,1);
        std::pair<std::vector<Block*>, std::vector<Block*>> seq_pair = _get_init_solution();
        _current_ps = seq_pair.first;
        _current_ns = seq_pair.second;
        _sp.sequence_to_graph(seq_pair.first, seq_pair.second, _all_blocks);
        std::vector<int> h_distance = _sp.get_h_distance();
        std::vector<int> v_histance = _sp.get_v_distance();
        _current_cost = _calculate_cost(h_distance,v_histance);
        _init_wirelength = _calculate_wirelength(h_distance,v_histance);
        _init_penality = _calculate_penalty(h_distance,v_histance);
        _init_area = h_distance.back() * v_histance.back();
        _update_best();
        _update_all();
        int it = 0;
        float frozen_t = 0.0005;
        bool in_bound = false;
        int it_count = 0;
        while(!in_bound && it_count < 15) {
            float temperature = 5000;
            while (temperature > frozen_t) {
                std::pair<std::vector<Block *>, std::vector<Block *>> ps_ns_pair = _sp.get_new_sequence(
                                                                                                        _all_blocks);
                _current_ps = ps_ns_pair.first;
                _current_ns = ps_ns_pair.second;
                _sp.sequence_to_graph(_current_ps, _current_ns, _all_blocks);
                h_distance = _sp.get_h_distance();
                v_histance = _sp.get_v_distance();
                _current_cost = _calculate_cost(h_distance, v_histance);
                std::cout << "_current cost " << _current_cost << std::endl;
                std::cout << "_prev cost " << _prev_cost << std::endl;
                if ((_current_cost - _prev_cost) <= 0) {
                    _accept_move();
                    if (_current_cost < _best_cost) {
                        //find better move
                        _update_best();
                    }
                } else {
                    if (double(distribution(generator)) < exp((_current_cost - _prev_cost) * -1 / temperature)) {
                        //compare cost to new cost
                        std::cout << "del cost: " << _current_cost - _prev_cost << std::endl;
                        _accept_move();
                    } else {
                        _reverse_move();
                    }
                }
                temperature = temperature * 0.95;
                std::cout << "it :" << it << std::endl;
                it++;
            }
            //check if the final solution is in bound
            _update_all();
            _sp.sequence_to_graph(_best_ps, _best_ns, _all_blocks);
            h_distance = _sp.get_h_distance();
            v_histance = _sp.get_v_distance();
            if(h_distance.back() <= _outline_width && v_histance.back() <= _outline_height) {
                in_bound = true;
                std::cout << "IN BOUND \n ";
            }
            std::cout << "it count " << it_count << std::endl;
            it_count++;
            _penality_ratio *= 2;
        }
        dump(_out_path);
    }

    float Circuit::_calculate_penalty(std::vector<int>& xs, std::vector<int>& ys) {
        int chip_width = xs.back();
        int chip_height = ys.back();

        /***calculate execessive length***/
        int outbound_length = 0;
        for(auto&& i : _all_blocks) {
            //check if x2 and y2 is out of bound
            int x2 = xs[i.second.get_id()] + i.second.get_width();
            int y2 = ys[i.second.get_id()] + i.second.get_height();
            int length = 0;
            if(y2 <= _outline_height && x2 > _outline_width) {
                length = sqrt(x2 - _outline_width);
            }
            else if(y2 > _outline_height && x2 <= _outline_width) {
                length = sqrt(y2 - _outline_height);
            }
            else if(y2 > _outline_height && x2 > _outline_width) {
                length = sqrt(y2 - _outline_height) + sqrt(x2 - _outline_width);
            }
            outbound_length += length;
        }

        /***calculate A'***/
        int area_penality = 0;
        if(chip_height <= _outline_width && chip_width > _outline_width) {
            area_penality = (chip_width - _outline_width) * _outline_height;
        }
        else if(chip_height > _outline_width && chip_width <= _outline_width) {
            area_penality = (chip_height - _outline_height) * _outline_width;
        }
        else if(chip_height > _outline_width && chip_width > _outline_width) {
            area_penality = chip_height * chip_width - _outline_height * _outline_width;
        }
        int penalty = area_penality + outbound_length;

        return penalty;
    }

    float Circuit::_calculate_wirelength(std::vector<int>& xs, std::vector<int>& ys) {
        float wirelength = 0;
        for(auto&& i : _all_nets) {
            std::vector<int> connected_xs = {};
            std::vector<int> connected_ys = {};
            for(auto* j : i.get_connected_block()) {
                connected_xs.push_back(2*xs.at(j->get_id()) + j->get_width());
                //connected_xs.push_back(xs.at(j->get_id()) + j->get_width() );
                connected_ys.push_back(2*ys.at(j->get_id()) + j->get_height());
                //connected_ys.push_back(ys.at(j->get_id()) + j->get_height());
            }
            for(auto* j : i.get_connected_terminal()) {
                connected_xs.push_back(2*j->get_x());
                connected_ys.push_back(2*j->get_y());
            }
            //find HPWL
            std::sort(connected_xs.begin(), connected_xs.end());
            std::sort(connected_ys.begin(), connected_ys.end());
            int del_x = connected_xs.back() - connected_xs.front();
            int del_y = connected_ys.back() - connected_ys.front();
            int HPWL = del_x + del_y;
            wirelength += HPWL/2;
        }
        return wirelength;
    }

    std::pair<std::vector<Block*>, std::vector<Block*>> Circuit::_get_init_solution() {
        std::vector<Block*> ps;
        std::vector<Block*> ns;
        for (auto&& i: _all_blocks) {
            ps.push_back(&i.second);
            ns.push_back(&i.second);
        }
        std::pair<std::vector<Block*>, std::vector<Block*>> seq_pair = std::make_pair(ps, ns);
        return seq_pair;
    }

    void Circuit::dump(const std::string& out_file_name) {
        //
        //find best solution info
        //set blocks widths and heights to the best
        for(auto&&i : _all_blocks) {
            i.second.set_width(_best_width[i.second.get_id()]);
            i.second.set_height(_best_height[i.second.get_id()]);
        }
        _sp.sequence_to_graph(_best_ps, _best_ns, _all_blocks);
        std::vector<int> h_distance = _sp.get_h_distance();
        std::vector<int> v_distance = _sp.get_v_distance();
        std::ofstream out_file;
        out_file.open(out_file_name);
        out_file << _best_cost << "\n";
        out_file << _calculate_wirelength(h_distance,v_distance) << "\n";
        int area = h_distance.back() * v_distance.back();
        out_file << area << "\n";
        out_file << h_distance.back() << " " << v_distance.back() << "\n";

        for(auto&& i : _all_blocks) {
            int x1 = h_distance[i.second.get_id()];
            int y1 = h_distance[i.second.get_id()];
            int x2 = x1 + i.second.get_width();
            int y2 = y1 + i.second.get_height();
            out_file << i.second.get_name() << " " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        }
        out_file.close();
    }

    void Circuit::visual_tool() {
        std::ifstream infile(_out_path);
        //std::ifstream infile("/Users/wanluanlee/Downloads/apte.out");
        std::string str;
        int width;
        int height;
        std:: vector<std::string> block_names = {};
        std:: vector<std::string> block_xs = {};
        std:: vector<std::string> block_ys = {};
        std:: vector<std::string> block_widths = {};
        std:: vector<std::string> block_heights = {};
        while (std::getline(infile, str)) {
            std::stringstream line_stream(str);
            std::string word;
            std::vector<std::string> words;
            while (std::getline(line_stream, word, ' ')) {
                if (word.size() > 0) {
                    words.push_back(word);
                }
            }
            if (words.size() == 2) {
                width = std::stoi(words[0]);
                height = std::stoi(words[1]);
            }
            else if(words.size() == 5) {
                block_names.push_back(words[0]);
                block_xs.push_back(words[1]);
                block_ys.push_back(words[2]);
                int block_width = std::stoi(words[3]) - std::stoi(words[1]);
                int block_height = std::stoi(words[4]) - std::stoi(words[2]);
                block_widths.push_back(std::to_string(block_width));
                block_heights.push_back(std::to_string(block_height));
            }
            words.clear();
        }
        std::ofstream out_file;
        out_file.open("/Users/wanluanlee/CLionProjects/PA2/out/visual_tool");
        int area = width * height;
        out_file << "{\"block_number\":" << block_names.size() << ",\"llx\":0,\"lly\":0,\"urx\":" << width << ",\"ury\":"
                 << height << ",\"area\":" << area<< ",\"coordinates\":[";
        for(int i = 0; i < block_names.size(); ++i) {
            std::string x1 = block_xs[i];
            std::string y1 = block_ys[i];
            out_file << "{\"idx\":\"" << block_names[i] << "\",\"llx\":" << x1 << ",\"lly\":" << y1 << ",\"width\":"
                     << block_widths[i] << ",\"height\":" << block_heights[i] << "},";
        }
        out_file.close();
    }
}
