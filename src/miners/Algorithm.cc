#include <Algorithm.hh>
#include <Algo3DCubeContiBnW.hh>
#include <Algo3DCubeContiRainbow.hh>
#include <Algo3DCubeContiFrebet.hh>
#include <Algo2DFourColors.hh>
#include <Algo2DGrayscale.hh>

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "contibnw", []() { return new Algo3DCubeContiBnW(); } },
    { "contirb", []() { return new Algo3DCubeContiRainbow(); } },
    { "conti", []() { return new Algo3DCubeContiFrebet(); } },
    { "4col", []() { return new Algo2DFourColors(); } },
    { "gray", []() { return new Algo2DGrayscale(); } },
};
