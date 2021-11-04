COPTS = [
    "-Wno-c++98-c++11-compat", # It seems -Wc++98-compat is automatic with Windows host
    ### https://airbus-seclab.github.io/c-compiler-security/#gcc-tldr
    "-O2",
    ###
    "-Werror",
    ###
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "-Wformat=2",
    "-Wformat-security",
    "-Wnull-dereference",
    "-Wstack-protector",
    "-Walloca",
    "-Wvla",
    # "-Wtraditional-conversion", conlyopt
    "-Wcast-qual",
    "-Wconversion",
    "-Wshadow",
    "-Wstrict-overflow=4",
    "-Wundef",
    # "-Wstrict-prototypes", conlyopt
    "-Wswitch-default",
    "-Wswitch-enum",
    ###
    "-fstack-protector-strong",
    "-fPIE",
]
