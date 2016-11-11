#-----------------------------------------------------------------------------
#                               CPACK
#-----------------------------------------------------------------------------
# VARIABLES COMMON to all GENERATORS
#===================================

# Possible Values :
#   - TGZ       Tar GZip
#   - TZ        Tar Compress
#   - TBZ2      Tar BZip2
#   - STGZ      Self Extracting TGZ
#   - ZIP       ZIP Format
#   - NSIS      Null Soft Installer
#   - DEB       Debian
#   - RPM       Red hat
# GENERATOR
set(CPACK_GENERATOR "TGZ")

# PACKAGE NAME
#   project name by default
set(CPACK_PACKAGE_NAME "")

# FILE NAME
#   Name of the package to generate, without extension
set(CPACK_PACKAGE_FILE_NAME "")

# VERSION
set(CPACK_PACKAGE_VERSION_MAJOR "")
set(CPACK_PACKAGE_VERSION_MINOR "")
set(CPACK_PACKAGE_VERSION_PATCH "")
set(CPACK_PACKAGE_VERSION "")

# DESCRIPTION
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "")
set(CPACK_PACKAGE_DESCRIPTION_FILE "")

# VENDOR
set(CPACK_PACKAGE_VENDOR "")

# EXECUTABLES
set(CPACK_PACKAGE_EXECUTABLES "")

# LICENCE
set(CPACK_RESOURCE_FILE_LICENSE "")

# finally include CPack
include(CPack)
