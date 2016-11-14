#pragma once

#include <fstream>

#include <Types.hh>
#include <Loader.hh>

class FileLoader : public Loader {
public:
    FileLoader(int fd) : Loader(true), fd_(fd) {}
    FileLoader(std::string path) : Loader(false), fd_(-1), path_(path) {}
    virtual ~FileLoader() {}

    virtual void load();
    virtual void free();

    virtual const u8 *data();
    virtual const u8 *dataChunk(size_t pos, size_t size);

protected:
    int fd_;
    std::string path_;
    std::ifstream is_;
    std::string data_;
};

