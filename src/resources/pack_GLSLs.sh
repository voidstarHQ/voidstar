#!/bin/bash

# Combine surrounding GLSL files into C++ data

[[ $# -ne 1 ]] && echo "Usage: $0  <path to target header file>" && exit 1

hh="$1"
hh_dir="$(dirname "$0")"

pack_GLSL() {
    local glsl="$1"
    local name="$(basename "$glsl" .glsl)"
    echo >>"$hh"
    echo "static const std::string shader__${name} = R\"(\\" >>"$hh"
    cat "$glsl" >>"$hh"
    echo ')";' >>"$hh"
    echo >>"$hh"
}

echo '#pragma once' >"$hh"
echo '#include <string>' >>"$hh"
for glsl in "$hh_dir"/*.glsl; do
    pack_GLSL "$glsl"
done
