# CUSTOM output executable and lib files
DEFAULT_TARGET :=		debug
TARGET_EXEC :=			dbtest
TARGET_LIB :=
HEADER_EXT :=			.hpp
SOURCE_EXT :=			.cpp

# CUSTOM paths
INC_DIRS :=			inc
INC_EXT_DIRS :=			../LibraryLoader/ext/apr/include
FORMAT_INC_DIRS :=		inc
SRC_DIRS :=			src
TEST_SRC_DIRS :=
FORMAT_SRC_DIRS :=		src
MAIN_SRC :=
LIB_DIRS :=			../LibraryLoader/ext/apr/lib ../LibraryLoader/build/lib ../DbHandler/build/lib
ROOT_BUILD_DIR :=		build

# CUSTOM libs for different targets
RELEASE_LIBS :=			dl apr-1 DynLdr DbHandler
STATIC_LIBS :=			$(RELEASE_LIBS)
LIBRARY_LIBS :=			$(RELEASE_LIBS)
DEBUG_LIBS :=			$(RELEASE_LIBS)
PROFILE_LIBS :=			$(RELEASE_LIBS)
TEST_LIBS :=			$(RELEASE_LIBS)

# finally, include the generic makefile
include ext/Makefile.inc
