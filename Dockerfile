FROM debian:9
WORKDIR /app
COPY . $PWD
RUN set -x \
 && apt update \
 && apt install -y \
    x11-apps \
    libc++-dev clang cmake
RUN set -x \
 && ./configure \
 && cd build \
 && make -j7
ENV DISPLAY :0
ENTRYPOINT ["/app/build/voidstar"]
