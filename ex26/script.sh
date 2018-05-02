set -e

# go somewhere safe
cd ~/code/c/ex26/tmp

# get the source to base APR 1.4.6
curl -L -O http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz

# extract it and go into the source
tar -xzvf apr-1.4.6.tar.gz
cd apr-1.4.6

# configure, make, make install
./configure
make
sudo make install

# reset and clean up
cd ~/code/c/ex26/tmp
rm -rf apr-1.4.6 apr-1.4.6.tar.gz

# do the same with apr-util
