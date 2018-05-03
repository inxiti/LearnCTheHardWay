#!/bin/bash
#

# variables
BASE_DIRECTORY=~/code/c/ex26
TMP_DIRECTORY=~/code/c/ex26/tmp

# begin
set -e

# make, and go somewhere safe
mkdir -p $TMP_DIRECTORY
cd $TMP_DIRECTORY

# get the source to base APR 1.4.6
curl -L -O http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz

# extract it, and go into the source
tar -xzvf apr-1.4.6.tar.gz
cd apr-1.4.6

# configure, make, make install
./configure
make
sudo make install

# reset and clean up
cd $TMP_DIRECTORY
rm -rf apr-1.4.6 apr-1.4.6.tar.gz

# do the same with apr-util
curl -L -O http://archive.apache.org/dist/apr/apr-util-1.4.1.tar.gz

# extract, and go into the source
tar -xzvf apr-util.1.4.1.tar.gz
cd apr-util-1.4.1

# configure, make, make install
./configure --with-apr=/usr/local/apr
make
sudo make install

# cleanup
cd $TMP_DIRECTORY
rm -rf apr-util-1.4.1* apr-1.4.6*
cd $BASE_DIRECTORY
rm -rf $TMP_DIRECTORY


