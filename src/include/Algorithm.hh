#pragma once

#include <functional>
#include <string>
#include <map>
#include <memory>

#include <GL/glew.h>

#include <Loader.hh>
#include <Range.hh>

// XXX moved here as a placeholder due to circular dependency #badDesign
enum SceneType {
    SCENE_UNDEFINED,
    SCENE_2D,
    SCENE_3D,
};

class Algorithm {
public:
    Algorithm(size_t min_size=0, size_t max_size=0)
        : min_data_size_(min_size), max_data_size_(max_size),
          loader_(0), range_(0) {}
    virtual ~Algorithm() {}

    virtual SceneType sceneType() const = 0;
    virtual void use(std::shared_ptr<Loader> loader, std::shared_ptr<DataRange> range=NULL);

    const u8* loadDataRange(const DataRange& range, size_t& size);

    inline const u8* loadDataRange(size_t& size) {
        return loadDataRange(*range_, size);
    }
    inline std::shared_ptr<DataRange> range() { return range_; }
    inline std::shared_ptr<Loader> loader() { return loader_; }

protected:
    size_t min_data_size_;
    size_t max_data_size_;
    std::shared_ptr<Loader> loader_;
    std::shared_ptr<DataRange> range_;
};

std::shared_ptr<Algorithm> createAlgorithm(const std::string str);

using AlgorithmFactoryFunc = std::function<std::shared_ptr<Algorithm>()>;
extern const std::map<const std::string, AlgorithmFactoryFunc> algorithms;
