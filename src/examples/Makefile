# compiler
CC = g++
# for building plugins (as shared libs)
SHARED = -fPIC -shared
# build dir for examples
BUILDPREFIX = ../build/plugins/main/


all: div fib prime gcd fact


# examples
# building with target examples

div:
	$(CC) $(SHARED) div.cpp -o "$(BUILDPREFIX)div"


fib:
	$(CC) $(SHARED) fib.cpp -o "$(BUILDPREFIX)fib"

gcd:
	$(CC) $(SHARED) gcd.cpp -o "$(BUILDPREFIX)gcd"

prime:
	$(CC) $(SHARED) prime.cpp -o "$(BUILDPREFIX)prime"

fact:
	$(CC) $(SHARED) fact.cpp -o "$(BUILDPREFIX)fact"
