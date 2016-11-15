#include <Algorithm.hh>
#include <ContiAlgorithm3D.hh>
#include <Algorithm2DFourColors.hh>
#include <Algorithm2DGrayscale.hh>

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "conti", []() { return new ContiAlgorithm3D(); } },
    { "4col", []() { return new Algorithm2DFourColors(); } },
    { "gray", []() { return new Algorithm2DGrayscale(); } },
};
