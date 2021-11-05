# syntax=docker.io/docker/dockerfile:1@sha256:42399d4635eddd7a9b8a24be879d2f9a930d0ed040a61324cfdf59ef1357b3b2

FROM --platform=$BUILDPLATFORM docker.io/whilp/buildifier@sha256:67da91fdddd40e9947153bc9157ab9103c141fcabcdbf646f040ba7a763bc531 AS buildifier
FROM --platform=$BUILDPLATFORM docker.io/library/ubuntu:20.04@sha256:82becede498899ec668628e7cb0ad87b6e1c371cb8a1e597d83a47fac21d6af3 AS ubuntu

FROM ubuntu AS base
WORKDIR /app
ENV DEBIAN_FRONTEND=noninteractive
RUN \
    set -ux \
    # https://github.com/moby/buildkit/blob/df49b648c8bfef657ba99543390516a3f518d22a/frontend/dockerfile/docs/syntax.md#example-cache-apt-packages
 && rm -f /etc/apt/apt.conf.d/docker-clean \
 && echo 'Binary::apt::APT::Keep-Downloaded-Packages "true";' >/etc/apt/apt.conf.d/keep-cache
RUN \
    --mount=type=cache,target=/var/cache/apt \
    --mount=type=cache,target=/var/lib/apt \
    set -ux \
 && apt update \
 && apt install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        clang \
        curl \
        ffmpeg \
        git \
        gzip \
        libgl1-mesa-dev \
        python3 \
        software-properties-common \
        tar \
        unzip \
        xauth \
        xorg-dev \
        xvfb \
 && update-alternatives --install /usr/bin/python python /usr/bin/python3 1
RUN \
    --mount=type=cache,target=/var/cache/apt \
    --mount=type=cache,target=/var/lib/apt \
    set -ux \
 && add-apt-repository -y ppa:openjdk-r/ppa \
 && apt update \
 && apt install -y --no-install-recommends \
        openjdk-8-jdk
ARG BAZEL_VERSION=4.2.1
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    set -ux \
 && mkdir /bazel \
 && curl -fsSLo /bazel/installer.sh "https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-installer-linux-x86_64.sh" \
 && curl -fsSLo /bazel/LICENSE.txt "https://raw.githubusercontent.com/bazelbuild/bazel/master/LICENSE" \
 && chmod +x /bazel/installer.sh \
 && /bazel/installer.sh \
 && rm /bazel/installer.sh \
 && bazel version
COPY . .

# sync
FROM base AS sync-then-fmt
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    set -ux \
 && bazel sync \
 && grep -v -F \"definition_information\": resolved.bzl >resolved.bzl~ \
 && mv resolved.bzl~ resolved.bzl
RUN \
    # Ideally we'd be executing buildifier from within the context of its
    # container but it turns out to need a shell:
    #17 [sync-fmt 2/2] RUN     --mount=from=sync-nofmt,source=/app/resolved.bzl,target=/resolved.bzl,readwrite   /buildifier -lint=fix /resolved.bzl
    #17 0.441 container_linux.go:367: starting container process caused: exec: "/bin/sh": stat /bin/sh: no such file or directory
    #17 ERROR: executor failed running [/bin/sh -c /buildifier -lint=fix /resolved.bzl]: exit code: 1
    --mount=from=buildifier,source=/buildifier,target=/buildifier \
    set -ux \
 && /buildifier -lint=fix resolved.bzl
FROM scratch AS sync
COPY --from=sync-then-fmt /app/resolved.bzl /

# voidstar Clang
FROM base AS builder-clang
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    set -ux \
 && bazel build voidstar --repo_env=CC=clang \
 && strip /app/bazel-bin/voidstar/voidstar \
 # Necessary as COPY --from does not follow symlinks
 && cp /app/bazel-bin/voidstar/voidstar /

# voidstar GCC
FROM base AS builder-gcc
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    set -ux \
 && bazel build voidstar \
 && strip /app/bazel-bin/voidstar/voidstar \
 # Necessary as COPY --from does not follow symlinks
 && cp /app/bazel-bin/voidstar/voidstar /


# xvfb GCC
FROM builder-gcc AS xvfb-gcc
ARG WxHxD=800x600x24
ARG BIN=/voidstar
ARG FILE=./data/BigPictureBG.tga
ARG OUT=webm
RUN ./xvfb.sh
FROM scratch AS video-gcc
COPY --from=xvfb-gcc /app/video.* /

# xvfb Clang
FROM builder-clang AS xvfb-clang
ARG WxHxD=800x600x24
ARG BIN=/voidstar
ARG FILE=./data/BigPictureBG.tga
ARG OUT=webm
RUN ./xvfb.sh
FROM scratch AS video-clang
COPY --from=xvfb-clang /app/video.* /


FROM scratch AS voidstar-clang
COPY --from=builder-clang /voidstar /

FROM scratch AS voidstar
COPY --from=builder-gcc /voidstar /
