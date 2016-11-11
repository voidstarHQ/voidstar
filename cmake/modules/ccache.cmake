# find ccache
find_program(ccache_path ccache)
if (DEFINED ccache_path)
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)

    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()
