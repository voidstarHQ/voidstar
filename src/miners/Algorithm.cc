#include <iostream>

#include <Algorithm.hh>
#include <Algo3DCubeContiBnW.hh>
#include <Algo3DCubeContiRainbow.hh>
#include <Algo3DCubeContiFrebet.hh>
#include <Algo2DFourColors.hh>
#include <Algo2DGrayscale.hh>

const u8 *
Algorithm::loadDataRange(const DataRange& range, size_t& size) {
    if (max_data_size_)
        size = std::min<size_t>(range.size(), max_data_size_);
    else
        size = range.size();
    std::cerr << "data " << size << " bytes!" << std::endl;
    return loader_->dataChunk(range.begin, size);
}

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "contibnw", []() { return new Algo3DCubeContiBnW(); } },
    { "contirb", []() { return new Algo3DCubeContiRainbow(); } },
    { "conti", []() { return new Algo3DCubeContiFrebet(); } },
    { "4col", []() { return new Algo2DFourColors(); } },
    { "gray", []() { return new Algo2DGrayscale(); } },
};
