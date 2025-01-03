cmake_minimum_required(VERSION 3.29)
project(Github)

set(CMAKE_CXX_STANDARD 20)

include_directories(StarWorkshop/StarWorkshop/algorithms)
include_directories(StarWorkshop/StarWorkshop/intermediate)

add_executable(Github
    StarWorkshop/StarWorkshop/algorithms/dp.cpp
    StarWorkshop/StarWorkshop/intermediate/intermediate.cpp
    StarWorkshop/StarWorkshop/main.cpp) # no need to include header


target_include_directories(Github PRIVATE
    StarWorkshop/StarWorkshop/algorithms
    StarWorkshop/StarWorkshop/intermediate)



