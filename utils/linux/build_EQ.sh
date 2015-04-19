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
        cd $EQ_ROOT_DIR/Lunchbox && rm -rf Build;
        cd $EQ_ROOT_DIR/vmmlib && rm -rf Build;
        cd $EQ_ROOT_DIR/Pression && rm -rf Build;
        cd $EQ_ROOT_DIR/Collage && rm -rf Build;
        cd $EQ_ROOT_DIR/Equalizer && rm -rf Build;
        cd $EQ_ROOT_DIR && rm -rf install;
        exit 0;
    else
        echo " Unrecognized target : " $1 " . Valid targets Release, Debug, clobber ."
        exit 1;
    fi
fi

echo " Building Equalizer and its dependencies in : " $BUILD_TYPE " MODE .";

cd $EQ_ROOT_DIR/Lunchbox && mkdir -p Build && cd Build && cmake .. -DCMAKE_INSTALL_PREFIX=$EQ_ROOT_DIR/install -DCMAKE_BUILD_TYPE=$BUILD_TYPE && make install;
cd $EQ_ROOT_DIR/vmmlib && mkdir -p Build && cd Build && cmake .. -DCMAKE_INSTALL_PREFIX=$EQ_ROOT_DIR/install -DCMAKE_BUILD_TYPE=$BUILD_TYPE && make install;
cd $EQ_ROOT_DIR/Pression && mkdir -p Build && cd Build && cmake .. -DCMAKE_INSTALL_PREFIX=$EQ_ROOT_DIR/install -DCMAKE_BUILD_TYPE=$BUILD_TYPE && make install;
cd $EQ_ROOT_DIR/Collage && mkdir -p Build && cd Build && cmake .. -DCMAKE_INSTALL_PREFIX=$EQ_ROOT_DIR/install -DCMAKE_BUILD_TYPE=$BUILD_TYPE && make install;
cd $EQ_ROOT_DIR/Equalizer && mkdir -p Build && cd Build && cmake .. -DCMAKE_INSTALL_PREFIX=$EQ_ROOT_DIR/install -DCMAKE_BUILD_TYPE=$BUILD_TYPE && make install;
