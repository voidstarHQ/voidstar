# syntax=docker/dockerfile:1.2@sha256:e2a8561e419ab1ba6b2fe6cbdf49fd92b95912df1cf7d313c3e2230a333fdbcc

FROM ubuntu:20.04@sha256:82becede498899ec668628e7cb0ad87b6e1c371cb8a1e597d83a47fac21d6af3 AS base
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
        curl \
        git \
        unzip \
        tar \
        gzip \
        python3 \
        libgl1-mesa-dev \
        xorg-dev \
        software-properties-common \
 && update-alternatives --install /usr/bin/python python /usr/bin/python3 1
RUN \
    --mount=type=cache,target=/var/cache/apt \
    --mount=type=cache,target=/var/lib/apt \
    set -ux \
 && add-apt-repository -y ppa:openjdk-r/ppa \
 && apt update \
 && apt install -y --no-install-recommends \
        openjdk-8-jdk
ARG BAZEL_VERSION=4.0.0
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
    #17 sha256:40d4dd8f67b52312e1515cc06559ee703c9944322416f9aa5c0566f1c541d836
    #17 0.441 container_linux.go:367: starting container process caused: exec: "/bin/sh": stat /bin/sh: no such file or directory
    #17 ERROR: executor failed running [/bin/sh -c /buildifier -lint=fix /resolved.bzl]: exit code: 1
    --mount=from=whilp/buildifier,source=/buildifier,target=/buildifier \
    set -ux \
 && /buildifier -lint=fix resolved.bzl
FROM scratch AS sync
COPY --from=sync-then-fmt /app/resolved.bzl /

# voidstar
FROM base AS builder
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    set -ux \
 && bazel build voidstar \
 # Necessary as COPY --from does not follow symlinks
 && cp /app/bazel-bin/voidstar/voidstar /
FROM scratch AS voidstar
COPY --from=builder /voidstar /
