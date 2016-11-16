#pragma once

#include <string>
#include <Loader.hh>

class MmapFileLoader : public Loader {
public:
    MmapFileLoader(int fd) : Loader(true), fd_(fd) {}
    MmapFileLoader(std::string path) : Loader(false), fd_(-1), path_(path) {}
    virtual ~MmapFileLoader() {}

    virtual void load();
    virtual void free();

    virtual const u8* data();
    virtual const u8* dataChunk(size_t pos, size_t size);

protected:
    int fd_;
    std::string path_;
    size_t size_;
    u8 *data_;
};
