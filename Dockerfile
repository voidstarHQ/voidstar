FROM debian
WORKDIR /app
COPY . $PWD
RUN set -x \
 && apt-get update
RUN set -x \
 && apt-get install -qqy \
    x11-apps \
    libglew-dev libglm-dev libglfw3-dev pkg-config \
    libc++-dev clang cmake
RUN set -x \
 && ./configure \
 && ls -lha \
 && cd build \
 && make -j7
ENV DISPLAY :0
CMD xeyes
