#pragma once

#include <memory>

#include <Types.hh>

class Loader {
public:
    Loader(bool stream)
        : stream_(stream), size_(0), offset_(0)
        {}
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

    static std::shared_ptr<Loader> fromURI(const std::string& uri);

    void offset(size_t offset) { offset_ = offset; }
    size_t offset() const { return offset_; }
    size_t size() const { return size_; }
    bool isStream() { return stream_; }

protected:
    bool stream_;
    size_t size_;
    size_t offset_;
};
