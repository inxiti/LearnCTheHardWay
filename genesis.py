#!/usr/bin/env python3

import os, sys

base_directory = "/Users/inxiti/code/c/ex"

def usage():
    print("./genesis.py #\n")
    print("Creates a new folder, copies skeleton files into it, and modifies them accordingly.")

def main(number):
    directory = base_directory + number

    if not os.path.exists(directory):
        print(directory)
        os.mkdir(directory)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        usage()
    else:
        main(sys.argv[1])