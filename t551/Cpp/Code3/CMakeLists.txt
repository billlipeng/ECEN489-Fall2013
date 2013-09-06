cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Not very flexible, unfortunately.
add_definitions(-std=c++11)

project(fahrenheit-celsius-converter)

add_executable(temp-conv temp-conv.cc)