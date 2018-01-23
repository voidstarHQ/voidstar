#pragma once

#include <fstream>

#include <Types.hh>
#include <Loader.hh>

class FileLoader : public Loader {
public:
    FileLoader(const std::string& path) : Loader(false), path_(path) {}
    virtual ~FileLoader() {}

    static std::shared_ptr<FileLoader> make(const std::string& uri);
    virtual void load();
    virtual void free();

    virtual const u8* data();
    virtual const u8* dataChunk(size_t pos, size_t size);

protected:
    std::string path_;
    std::ifstream is_;
    std::string data_;
};
