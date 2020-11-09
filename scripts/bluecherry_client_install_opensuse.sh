#!/bin/bash

export BUILD_DIR=/tmp/bluecherry-build
zypper -n install git dpkg-devel dpkg debhelper dh-autoreconf cmake libqt4-devel yasm zlib-devel libSDL2-devel mpv-devel libass-devel libva-devel libXv-devel libXss-devel alsa-devel MPlayer
mkdir -p $BUILD_DIR
cd $BUILD_DIR
git clone https://github.com/google/breakpad.git $BUILD_DIR/breakpad
cd $BUILD_DIR/breakpad
git clone https://chromium.googlesource.com/linux-syscall-support ./src/third_party/lss
./configure && make; make install
git clone https://github.com/bluecherrydvr/bluecherry-client.git $BUILD_DIR/bluecherry-client
cd $BUILD_DIR/bluecherry-client
cp linux-user.cmake user.cmake
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ../
make install
