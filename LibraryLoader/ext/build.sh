#!/bin/bash

fn_abort()
{
    ERRCODE=$?
    echo >&2 "Error $ERRCODE executing $BASH_COMMAND on line ${BASH_LINENO[0]}"
    exit $ERRCODE
}

trap fn_abort ERR
set -o errtrace -o pipefail

fn_build_cmake()
{
    NAME=$1
    DIR=$2
    CMAKE_ARGS=$3
    MAKE_TARGET=$4
    BASE_DIR=`pwd`
    echo -e " * \\033[1;33m${NAME}\\033[0;39m"
    mkdir "${BASE_DIR}/${DIR}/build"
    cd "${BASE_DIR}/${DIR}/build" && \
    cmake ${CMAKE_ARGS} | grep -v -- '-- Detecting C' | grep -v -- '-- Check for working C' | grep -v -- '-- Looking for ' && \
    make ${MAKE_TARGET}
    cd "${BASE_DIR}"
    echo
}

rm -rf apr

NAME=apr
BASE_DIR=`pwd`
DIR=src/apr-1.6.5/
echo -e " * \\033[1;33m${NAME}\\033[0;39m"
cd "${BASE_DIR}/${DIR}"
./configure --quiet --prefix="${BASE_DIR}/${NAME}"
make --silent
make --silent install
cd "${BASE_DIR}"
echo
