COPTS = [
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
    # "-Wswitch-default", @fmt complains
    "-Wswitch-enum",
    ###
    "-fstack-protector-strong",
    "-fPIE",
]
