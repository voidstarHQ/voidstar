#pragma once

#include <Types.hh>

class Loader {
public:
    Loader(bool stream) : stream_(stream) {}
    virtual ~Loader() {}

    virtual void load() = 0;
    virtual void free() = 0;

    virtual const u8* data() = 0;
    virtual const u8* dataChunk(size_t offset, size_t size) = 0;
    virtual const u8* nextDataChunk(size_t size) {
        auto chunk = dataChunk(offset_, size);
        offset_ += size;
        return chunk;
    }

    void offset(size_t offset) { offset_ = offset; }
    size_t offset() const { return offset_; }

    size_t size() const { return size_; }

    bool isStream() { return stream_; }

protected:
    bool stream_;
    size_t size_;
    size_t offset_;
};

class NullLoader : public Loader {
public:
    NullLoader() : Loader(false) {}
    virtual ~NullLoader() {}

    virtual void load() {}
    virtual void free() {}

    virtual const u8* data() {
        throw std::runtime_error("Unexpected call");
    }
    virtual const u8* dataChunk(size_t offset __unused, size_t size __unused) {
        throw std::runtime_error("Unexpected call");
    }
};

Loader* loaderFromUri(const std::string& uri);
