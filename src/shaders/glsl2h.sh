#!/bin/bash -eu

# Combine surrounding GLSL files into C++ data

[[ $# -ne 2 ]] && echo "Usage: $0  <path to GLSL file> <path to target header file>" && exit 1

src="$1"
dst="$2"

echo '#pragma once' >"$dst"
echo '#include <string>' >>"$dst"
echo >>"$dst"
printf 'static const std::string shader__%s = R"(\\\n' "$(basename "$src" .glsl)" >>"$dst"
cat "$src" >>"$dst"
echo ')";' >>"$dst"
echo >>"$dst"
