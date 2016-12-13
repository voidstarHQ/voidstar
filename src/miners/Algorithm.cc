#include <Algorithm.hh>
#include <Algorithm3DContiBnW.hh>
#include <Algorithm3DContiRainbow.hh>
#include <Algorithm3DContiFrebet.hh>
#include <Algorithm2DFourColors.hh>
#include <Algorithm2DGrayscale.hh>

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "contibnw", []() { return new Algorithm3DContiBnW(); } },
    { "contirb", []() { return new Algorithm3DContiRainbow(); } },
    { "conti", []() { return new Algorithm3DContiFrebet(); } },
    { "4col", []() { return new Algorithm2DFourColors(); } },
    { "gray", []() { return new Algorithm2DGrayscale(); } },
};
