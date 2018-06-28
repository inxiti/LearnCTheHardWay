CFLAGS=-Wall -g -DNDEBUG -ldl

# TODO: make library separately, then call it from here
all:
	cc -c libex29.c -o libex29.o
	cc -shared -o libex29.so libex29.o
	cc $(CFLAGS) -o ex29 ex29.c

clean:
	rm -f libex29.so
	rm -f libex29.o
	rm -f ex29
	rm -rf ex29.dSYM
