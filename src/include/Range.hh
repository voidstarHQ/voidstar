#pragma once

#include <Types.hh>

struct DataRange {
    size_t begin;
    size_t end;
    size_t size() const { return end - begin; }
    static std::shared_ptr<DataRange> create(size_t begin, size_t end) {
        if (begin == 0 && end == 0)
            return NULL;
        return std::make_shared<DataRange>(begin, end);
    }
};
