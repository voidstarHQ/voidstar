# syntax=docker.io/docker/dockerfile:1@sha256:865e5dd094beca432e8c0a1d5e1c465db5f998dca4e439981029b3b81fb39ed5

FROM --platform=$BUILDPLATFORM docker.io/library/ubuntu:22.04@sha256:0e5e4a57c2499249aafc3b40fcd541e9a456aab7296681a3994d631587203f97 AS ubuntu

ARG BUILDOS
ARG BUILDARCH

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
        bc \
        build-essential \
        ca-certificates \
        clang \
        curl \
        ffmpeg \
        git \
        gzip \
        libgl1-mesa-dev \
        python-is-python3 \
        python3-urllib3 \
        software-properties-common \
        tar \
        unzip \
        xauth \
        xorg-dev \
        xvfb
COPY .bazelversion .
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    --mount=type=cache,target=/root/.cache/bazelisk \
    set -ux \
 && curl -#fsSLo /bazelisk https://github.com/bazelbuild/bazelisk/releases/download/v1.22.1/bazelisk-$BUILDOS-$BUILDARCH \
 && chmod +x /bazelisk \
 && cd /usr/local/bin \
 && ln -s /bazelisk bazel \
 && bazel version
COPY . .

# buildifier
FROM base AS buildifier
RUN \
    set -ux \
 && curl -#fsSLo /buildifier "https://github.com/bazelbuild/buildtools/releases/download/v$(cat .bazelversion)/buildifier-$BUILDOS-$BUILDARCH" \
 && chmod +x /buildifier

# sync
FROM base AS sync-then-fmt
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    --mount=type=cache,target=/root/.cache/bazelisk \
    set -ux \
 && bazel sync \
 && grep -v -F \"definition_information\": resolved.bzl >resolved.bzl~ \
 && mv resolved.bzl~ resolved.bzl
RUN \
    --mount=from=buildifier,source=/buildifier,target=/buildifier \
    set -ux \
 && /buildifier -lint=fix resolved.bzl
FROM scratch AS sync
COPY --from=sync-then-fmt /app/resolved.bzl /

# voidstar Clang
FROM base AS builder-clang
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    --mount=type=cache,target=/root/.cache/bazelisk \
    set -ux \
 && bazel build voidstar --repo_env=CC=clang \
 && strip /app/bazel-bin/voidstar/voidstar \
 # Necessary as COPY --from does not follow symlinks
 && cp /app/bazel-bin/voidstar/voidstar /

# voidstar GCC
FROM base AS builder-gcc
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    --mount=type=cache,target=/root/.cache/bazelisk \
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
ARG OUT=mp4
RUN ./xvfb.sh
FROM scratch AS video-gcc
COPY --from=xvfb-gcc /app/video.* /

# xvfb Clang
FROM builder-clang AS xvfb-clang
ARG WxHxD=800x600x24
ARG BIN=/voidstar
ARG FILE=./data/BigPictureBG.tga
ARG OUT=mp4
RUN ./xvfb.sh
FROM scratch AS video-clang
COPY --from=xvfb-clang /app/video.* /


FROM scratch AS voidstar-clang
COPY --from=builder-clang /voidstar /

FROM scratch AS voidstar
COPY --from=builder-gcc /voidstar /
