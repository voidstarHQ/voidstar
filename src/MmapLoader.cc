#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include <MmapLoader.hh>
#include <Uri.hh>

std::shared_ptr<MmapLoader>
MmapLoader::make(const std::string& uri) {
    struct stat info;
    if (Uri<>::parse(uri).protocol.empty())
        if (!stat(uri.c_str(), &info))
            if (~info.st_mode & S_IFDIR)
                return std::make_shared<MmapLoader>(uri);
    return nullptr;
}

void
MmapLoader::load() {
    if (fd_ < 0) {
        fd_ = open(path_.c_str(), O_RDONLY);
        if (fd_ < 0)
            throw std::runtime_error("Impossible to read file");
    }

    size_ = lseek(fd_, 0, SEEK_END);
    lseek(fd_, 0, SEEK_SET);

    auto base = mmap(0, size_, PROT_READ, MAP_PRIVATE, fd_, 0);
    if (nullptr == base) {
        close(fd_);
        throw std::runtime_error("Failed to map data");
    }
    data_ = reinterpret_cast<u8*>(base);
}

void
MmapLoader::free() {
    munmap(data_, size_);
    offset_ = 0;
    data_ = 0;
    size_ = 0;
    // fd?
    // close(fd_)
}

const u8*
MmapLoader::data() {
    return data_;
}

const u8*
MmapLoader::dataChunk(size_t offset, size_t size) {
    if (size_ < offset + size)
        throw std::out_of_range("Trying to read data out of bound");
    return data() + offset;
}
