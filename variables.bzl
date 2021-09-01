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
    "-Wformat-overflow=2",
    "-Wformat-truncation=2",
    "-Wformat-security",
    "-Wnull-dereference",
    "-Wstack-protector",
    "-Wtrampolines",
    "-Walloca",
    "-Wvla",
    "-Warray-bounds=2",
    "-Wimplicit-fallthrough=3",
    # "-Wtraditional-conversion", conlyopt
    "-Wshift-overflow=2",
    "-Wcast-qual",
    "-Wstringop-overflow=4",
    "-Wconversion",
    # "-Warith-conversion", re-enable on GCC>=10
    "-Wlogical-op",
    "-Wduplicated-cond",
    "-Wduplicated-branches",
    "-Wformat-signedness",
    "-Wshadow",
    "-Wstrict-overflow=4",
    "-Wundef",
    # "-Wstrict-prototypes", conlyopt
    "-Wswitch-default",
    "-Wswitch-enum",
    "-Wstack-usage=1000000",
    "-Wcast-align=strict",
    ###
    "-D_FORTIFY_SOURCE=2",
    ###
    "-fstack-protector-strong",
    # "-fstack-clash-protection", GCC-only
    "-fPIE",
    ###
    # "-Wl,-z,relro", GCC-only
    # "-Wl,-z,now", GCC-only
    # "-Wl,-z,noexecstack", GCC-only
    # "-Wl,-z,separate-code", GCC-only
]
