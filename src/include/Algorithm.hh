#pragma once

#include <functional>
#include <string>
#include <map>

#include <GL/glew.h>

#include <Loader.hh>

class Algorithm {
public:
    virtual ~Algorithm() {}
    virtual void use(Loader* loader) { loader_ = loader; }
protected:
    Loader* loader_;
};

using AlgorithmFactoryFunc = std::function<Algorithm*()>;

extern std::map<std::string, AlgorithmFactoryFunc> algorithms;
