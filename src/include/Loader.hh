#pragma once

#include <Types.hh>

class Loader {
public:
    Loader(bool stream) : stream_(stream) {}
    virtual ~Loader() {}

    virtual void load() = 0;
    virtual void free() = 0;

    virtual const std::string& dataAll() = 0;
    virtual const std::string& dataChunk(size_t size) = 0;

    bool isStream() { return stream_; }

protected:
    bool stream_;
};

class NullLoader : public Loader {
public:
    NullLoader() : Loader(false) {}
    virtual ~NullLoader() {}

    virtual void load() {}
    virtual void free() {}

    virtual const std::string& dataAll() {
        throw std::runtime_error("Unexpected call");
    }
    virtual const std::string& dataChunk(size_t size __unused) {
        throw std::runtime_error("Unexpected call");
    }
};

