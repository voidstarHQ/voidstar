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
    # "-Wformat-overflow=2", TODO: GCC-only
    # "-Wformat-truncation=2", TODO: GCC-only
    "-Wformat-security",
    "-Wnull-dereference",
    "-Wstack-protector",
    # "-Wtrampolines", TODO: GCC-only
    "-Walloca",
    "-Wvla",
    # "-Warray-bounds=2", TODO: GCC-only
    # "-Wimplicit-fallthrough=3", TODO: GCC-only
    # "-Wtraditional-conversion", conlyopt
    # "-Wshift-overflow=2", TODO: GCC-only
    "-Wcast-qual",
    # "-Wstringop-overflow=4", TODO: GCC-only
    "-Wconversion",
    # "-Warith-conversion", TODO: re-enable on GCC>=10
    # "-Wlogical-op", TODO: GCC-only
    # "-Wduplicated-cond", TODO: GCC-only
    # "-Wduplicated-branches", TODO: GCC-only
    # "-Wformat-signedness", TODO: GCC-only
    "-Wshadow",
    "-Wstrict-overflow=4",
    "-Wundef",
    # "-Wstrict-prototypes", conlyopt
    "-Wswitch-default",
    "-Wswitch-enum",
    # "-Wstack-usage=1000000", TODO: GCC-only
    # "-Wcast-align=strict", TODO: GCC-only
    ###
    # "-D_FORTIFY_SOURCE=2", TODO: use when not already =1
    ###
    "-fstack-protector-strong",
    # "-fstack-clash-protection", TODO: GCC-only
    "-fPIE",
    ###
    # "-Wl,-z,relro", TODO: GCC-only
    # "-Wl,-z,now", TODO: GCC-only
    # "-Wl,-z,noexecstack", TODO: GCC-only
    # "-Wl,-z,separate-code", TODO: GCC-only
]
