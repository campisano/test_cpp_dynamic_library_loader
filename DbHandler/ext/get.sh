#!/bin/bash

fn_abort()
{
    ERRCODE=$?
    echo >&2 "Error $ERRCODE executing $BASH_COMMAND on line ${BASH_LINENO[0]}"
    exit $ERRCODE
}

trap fn_abort ERR
set -o errtrace -o pipefail

fn_get()
{
    NAME=$1
    URL=$2
    BASE_DIR=`pwd`
    mkdir -p "${BASE_DIR}/src"
    echo -e " * \\033[1;33m${URL}\\033[0;39m"
    cd "${BASE_DIR}/src" && curl -L -s "${URL}" -o "${NAME}"
    cd "${BASE_DIR}"
}

fn_get_zip()
{
    URL=$1
    BASE_DIR=`pwd`
    fn_get tmp.zip "${URL}"
    cd "${BASE_DIR}/src" && unzip -q tmp.zip && rm -f tmp.zip
    cd "${BASE_DIR}"
}

fn_get_zip https://codeload.github.com/campisano/GenericMakefile/zip/master
cp -a src/GenericMakefile-master/Makefile.inc .
