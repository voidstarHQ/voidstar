#pragma once

#include <functional>
#include <string>
#include <map>

#include <GL/glew.h>

#include <Loader.hh>
#include <Range.hh>

class Algorithm {
public:
    virtual ~Algorithm() {}
    virtual void use(Loader *loader, DataRange *range = 0) {
        loader_ = loader;
        if (loader_->size() < min_data_size_)
            throw std::range_error("this algorithm needs more data");
        range_ = range;
        if (!range_) {
            range_ = new DataRange{0, loader_->size()};
        }
    }
    const u8 *loadDataRange(const DataRange& range, size_t& size);

    inline const u8 *loadDataRange(size_t& size) {
        return loadDataRange(*range_, size);
    }
    inline DataRange *range() { return range_; }
    inline Loader *loader() { return loader_; }

protected:
    size_t min_data_size_;
    size_t max_data_size_;
    Loader* loader_;
    DataRange* range_;
};

using AlgorithmFactoryFunc = std::function<Algorithm*()>;

extern std::map<std::string, AlgorithmFactoryFunc> algorithms;
