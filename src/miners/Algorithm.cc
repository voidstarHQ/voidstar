#include <Algorithm.hh>
#include <ContiAlgorithm.hh>

std::map<std::string, AlgorithmFactoryFunc> algorithms = {
    { "conti", []() { return new ContiAlgorithm(); } },
};

