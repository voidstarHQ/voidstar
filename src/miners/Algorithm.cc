#include <Algorithm.hh>
#include <ContiAlgorithm3D.hh>

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "conti", []() { return new ContiAlgorithm3D(); } },
};

