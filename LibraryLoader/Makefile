# CUSTOM output executable and lib files
DEFAULT_TARGET :=		library
TARGET_EXEC :=
TARGET_LIB :=			libDynLdr.so
HEADER_EXT :=			.hpp
SOURCE_EXT :=			.cpp

# CUSTOM paths
INC_DIRS :=			inc
INC_EXT_DIRS :=			ext/apr/include
FORMAT_INC_DIRS :=		inc
SRC_DIRS :=			src
TEST_SRC_DIRS :=
FORMAT_SRC_DIRS :=		src
MAIN_SRC :=
LIB_DIRS :=			ext/apr/lib
ROOT_BUILD_DIR :=		build

# CUSTOM libs for different targets
RELEASE_LIBS :=
STATIC_LIBS :=			$(RELEASE_LIBS)
LIBRARY_LIBS :=			$(RELEASE_LIBS)
DEBUG_LIBS :=			$(RELEASE_LIBS)
PROFILE_LIBS :=			$(RELEASE_LIBS)
TEST_LIBS :=			$(RELEASE_LIBS)

# finally, include the generic makefile
include ext/Makefile.inc
