#pragma once

#include <unistd.h>

#include <Types.hh>
#include <Loader.hh>

class FdFileLoader : public Loader {
public:
    FdFileLoader(int fd) : Loader(true), fd_(fd) {}
    virtual ~FdFileLoader() {}

    static std::shared_ptr<FdFileLoader> make(const std::string& uri);
    virtual void load();
    virtual void free();

    virtual const u8* data();
    virtual const u8* dataChunk(size_t pos, size_t size);

protected:
    int fd_;
};
