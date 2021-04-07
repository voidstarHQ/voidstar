# syntax=docker/dockerfile:1.2

FROM ubuntu:20.04 AS base
WORKDIR /app
ENV DEBIAN_FRONTEND=noninteractive
RUN set -ux \
 && apt update \
 && apt install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        curl \
        # ffmpeg \
        git \
        wget \
        unzip \
        tar \
        gzip \
        # python3-dev \
        python3 \
        # python3-opencv \
        # python3-pip \
        mesa-common-dev \
        libegl1-mesa-dev \
        libgles2-mesa-dev \
        mesa-utils \
        # libopencv-core-dev \
        # libopencv-highgui-dev \
        # libopencv-imgproc-dev \
        # libopencv-video-dev \
        # libopencv-calib3d-dev \
        # libopencv-features2d-dev \
        software-properties-common \
 && update-alternatives --install /usr/bin/python python /usr/bin/python3 1 \
 && add-apt-repository -y ppa:openjdk-r/ppa \
 && apt update \
 && apt install -y --no-install-recommends \
        openjdk-8-jdk
# RUN set -ux \
#  && pip3 install --upgrade setuptools \
#  && pip3 install wheel \
#  && pip3 install future \
#  && pip3 install six==1.14.0
#  # && pip3 install tensorflow==1.14.0 \
#  # && pip3 install tf_slim
ARG BAZEL_VERSION=3.4.1
RUN set -ux \
 && mkdir /bazel \
 && wget --no-check-certificate -O /bazel/installer.sh "https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-installer-linux-x86_64.sh" \
 && wget --no-check-certificate -O /bazel/LICENSE.txt "https://raw.githubusercontent.com/bazelbuild/bazel/master/LICENSE" \
 && chmod +x /bazel/installer.sh \
 && /bazel/installer.sh \
 && rm /bazel/installer.sh
COPY . .

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

FROM base AS builder
# ENV DRI_PRIME=1
# ARG USE_BAZEL_VERSION=3.4.0
RUN \
    --mount=type=cache,target=/root/.cache/bazel \
    # --mount=type=cache,target=/root/.cache/bazelisk \
    set -ux \
 # && USE_BAZEL_VERSION=${USE_BAZEL_VERSION} make
 && bazel build voidstar

FROM scratch AS voidstar
COPY --from=builder ./bazel-bin/voidstar/voidstar /
