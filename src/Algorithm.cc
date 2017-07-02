#include <iostream>

#include <Manager.hh>

#include <Algorithm.hh>
#include <Algo2DEntropy.hh>
#include <Algo2DFourColors.hh>
#include <Algo2DGrayscale.hh>
#include <Algo3DCubeFull.hh>
#include <Algo3DCubeContiBnW.hh>
#include <Algo3DCubeContiRainbow.hh>
#include <Algo3DCubeContiFrebet.hh>
#include <Algo3DSphereFull.hh>
#include <Algo3DSphereContiBnW.hh>
#include <Algo3DSphereContiRainbow.hh>
#include <Algo3DSphereContiFrebet.hh>

void
Algorithm::use(std::shared_ptr<Loader> loader, std::shared_ptr<DataRange> range) {
    // XXX this might be problematic in the future
    // XXX delete loader prior to creating a new one (same for range)
    if (loader_ && loader != loader_)
        std::cerr << "deleting loader" << std::endl;
    loader_ = loader;
    // FIXME: implement sliding window for stream based input
    if (loader_->size() < min_data_size_)
        throw std::range_error("this algorithm needs more data");
    if (range_ && range_ != range)
        std::cerr << "deleting range" << std::endl;
    range_ = range;
    if (!range_) {
        range_ = std::make_shared<DataRange>(0, loader_->size());
    }
}

const u8*
Algorithm::loadDataRange(const DataRange& range, size_t& size) {
    if (max_data_size_)
        size = std::min<size_t>(range.size(), max_data_size_);
    else
        size = range.size();
    std::cerr << "read " << Manager::size2str(size) << " bytes" << std::endl;
    return loader_->dataChunk(range.begin, size);
}

std::shared_ptr<Algorithm>
createAlgorithm(const std::string& str) {
    auto it = algorithms.find(str);
    if (it == algorithms.end()) {
        return 0;
    }
    return it->second();
}

using AlgorithmFactoryFunc = std::function<std::shared_ptr<Algorithm>()>;

const std::map<const std::string, AlgorithmFactoryFunc> algorithms = {
    {"entropy", []() { return std::make_shared<Algo2DEntropy>(); }},
    {"4col", []() { return std::make_shared<Algo2DFourColors>(); }},
    {"gray", []() { return std::make_shared<Algo2DGrayscale>(); }},
    {"cube", []() { return std::make_shared<Algo3DCubeFull>(); }},
    {"contibnw", []() { return std::make_shared<Algo3DCubeContiBnW>(); }},
    {"contirb", []() { return std::make_shared<Algo3DCubeContiRainbow>(); }},
    {"conti", []() { return std::make_shared<Algo3DCubeContiFrebet>(); }},
    {"sphere", []() { return std::make_shared<Algo3DSphereFull>(); }},
    {"sphere_bnw", []() { return std::make_shared<Algo3DSphereContiBnW>(); }},
    {"sphere_rb", []() { return std::make_shared<Algo3DSphereContiRainbow>(); }},
    {"sphere_frebet", []() { return std::make_shared<Algo3DSphereContiFrebet>(); }},
};
