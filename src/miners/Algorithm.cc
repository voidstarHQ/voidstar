#include <Algorithm.hh>
#include <Algorithm3DContiBnW.hh>
#include <Algorithm2DFourColors.hh>
#include <Algorithm2DGrayscale.hh>

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "contibnw", []() { return new Algorithm3DContiBnW(); } },
    { "4col", []() { return new Algorithm2DFourColors(); } },
    { "gray", []() { return new Algorithm2DGrayscale(); } },
};
