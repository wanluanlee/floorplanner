add_library(sp circuit.cpp block.cpp net.cpp terminal.cpp sequence_pair.cpp)

#target_compile_features(gap INTERFACE cxx_std_17)
set_property(TARGET sp PROPERTY CXX_STANDARD 17)

target_link_options(sp INTERFACE)
target_compile_options(sp INTERFACE -Wall -Wextra -Wfatal-errors)
