# devpkg

I did not create this. I merely coded it using sample code, and guidance from the book it's in.

devpkg is a simple C program that installsother software.

Command line options:
- S
    - Sets up a new install on a computer.
- I
    - Installs a piece of software from a URL.
- L
    - Lists all the software that's been installed.
- F
    - Fetches some source code for manual building.
- B
    - Fetches and builds source code and installs it, even if already installed.

Dependecies:
- dbg.h
- [bstrlib.h/bstrlib.c](http://bstring.sourceforge.net/)