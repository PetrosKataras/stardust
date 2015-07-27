#!/bin/bash

set -e

EQ_ROOT_DIR=$PWD/../../libs/equalizer
BUILD_TYPE=Release

if [ -n "$1" ];then
    if [ "$1" = "Release" ];then
        BUILD_TYPE=Release;
    elif [ "$1" = "Debug" ];then
        BUILD_TYPE=Debug;
    elif [ "$1" = "clobber" ];then
        echo "Clobber - Cleaning Equalizer and dependencies......................................." 
        cd $EQ_ROOT_DIR && rm -rf Build \
                           rm -rf Pression \
                           rm -rf vmmlib \
                           rm -rf Servus \
                           rm -rf Collage \
                           rm -rf Lunchbox;
        cd $EQ_ROOT_DIR && rm -rf install;
        exit 0;
    else
        echo " Unrecognized target : " $1 " . Valid targets Release, Debug, clobber ."
        exit 1;
    fi
fi

echo " Building Equalizer and its dependencies in : " $BUILD_TYPE " MODE .";


cd $EQ_ROOT_DIR && mkdir -p Build && cd Build && cmake .. -DCMAKE_INSTALL_PREFIX=$EQ_ROOT_DIR/install \
                                                                    -DCMAKE_OSX_ARCHITECTURES=x86_64 \
                                                                    -DCMAKE_BUILD_TYPE=$BUILD_TYPE && make install;



