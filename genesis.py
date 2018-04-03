#!/usr/bin/env python3

"""genesis Project Creation Tool

This tool is only for use with this specific book. It is custom made, and as
such it has very limited use outside of its very limited scope. Not
recommended for use by others.
"""

import os
import shutil
import sys

def usage():
    """Prints the usage text.
    """
    print("./genesis.py #\n")
    print("Creates a new folder, copies skeleton files into it, and modifies "
          "them accordingly.")

def create(number, files, directory, base_directory):
    """Creation.

    Creates the directory, moves skeleton files into it with their new names,
    and modifies them appropriately.
    """
    print("Creating {0}... ".format(directory), end="")

    os.mkdir(directory)

    # copy files to the new directory with their new names
    for file in files:
        shutil.copyfile(base_directory + file[0], directory + file[1])

    # tailor appropriate files for this project
    filename = "{0}/Makefile".format(directory)
    with open(filename) as file:
        modified_text = file.read().replace("file1", "ex{0}".format(number))
    with open(filename, "w") as file:
        file.write(modified_text)

    print("done.")

def main(arguments):
    """Main entry point

    Determines what the program does.
    """
    # represents project number
    number = arguments[1]

    # configuration
    base_directory = "/Users/inxiti/code/c/"
    skeleton_files = [
        ["Makefile.skeleton", "Makefile"],
        ["skeleton.c", "ex{0}.c".format(number)]
    ]
    directory = "{0}ex{1}/".format(base_directory, number)

    # create project, copy files, and tailor them if directory does not exist
    if not os.path.exists(directory):
        create(number, skeleton_files, directory, base_directory)
    else:
        print("{0} already exists.".format(directory))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        usage()
    else:
        main(sys.argv)
