cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(summary-stats)

add_definitions(-Wall --pedantic -std=c++11)

add_executable(summary-stats summary-stats.cc)