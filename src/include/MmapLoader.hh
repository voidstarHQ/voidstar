#pragma once

#include <string>
#include <Loader.hh>

class MmapFileLoader : public Loader {
public:
    MmapFileLoader(int fd) : Loader(true), fd_(fd), data_(nullptr) {}
    MmapFileLoader(const std::string& path) : Loader(false), fd_(-1), data_(nullptr), path_(path) {}
    virtual ~MmapFileLoader() { if (data_) free(); }

    virtual void load();
    virtual void free();

    virtual const u8* data();
    virtual const u8* dataChunk(size_t pos, size_t size);

protected:
    int fd_;
    u8* data_;
    std::string path_;
};
