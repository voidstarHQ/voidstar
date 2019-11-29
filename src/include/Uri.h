#pragma once

#include <string>
#include <algorithm>

template<class T = std::string>
struct Uri {
    T queryString;
    T path;
    T protocol;
    T host;
    T port;

    static Uri parse(const T& uri);
};

template<class T>
Uri<T>
Uri<T>::parse(const T& uri) {
    Uri<T> result;

    if (uri.length() == 0)
        return result;

    auto uriEnd = uri.cend();
    auto queryStart = std::find(uri.cbegin(), uriEnd, '?');
    auto protocolStart = uri.cbegin();
    auto protocolEnd = std::find(protocolStart, uriEnd, ':');

    if (protocolEnd != uriEnd) {
        T prot = &*(protocolEnd);
        if ((prot.length() > 3) && (prot.substr(0, 3) == "://")) {
            result.protocol = T(protocolStart, protocolEnd);
            protocolEnd += 3;
        } else {
            protocolEnd = uri.cbegin();
        }
    } else {
        protocolEnd = uri.cbegin();
    }

    auto hostStart = protocolEnd;
    auto pathStart = std::find(hostStart, uriEnd, '/');
    auto hostEnd = std::find(protocolEnd,
        (pathStart != uriEnd) ? pathStart : queryStart, ':');

    result.host = T(hostStart, hostEnd);

    if ((hostEnd != uriEnd) && ((&*(hostEnd))[0] == ':'))  // we have a port
    {
        hostEnd++;
        auto portEnd = (pathStart != uriEnd) ? pathStart : queryStart;
        result.port = T(hostEnd, portEnd);
    }

    if (pathStart != uriEnd)
        result.path = T(pathStart, queryStart);

    if (queryStart != uriEnd)
        result.queryString = T(queryStart, uri.end());

    return result;
}
