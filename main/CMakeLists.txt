add_executable(main main.cpp)

# options/flags pass to the compiler
#target_compile_features(qsat INTERFACE cxx_std_17)
#target_compile_options(qsat INTERFACE -Wall -Wextra -Wfatal-errors)

# include and libary linking
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(main LINK_PUBLIC sp)


