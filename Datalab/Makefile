# Student's Makefile for the CS:APP Data Lab
TEAM = ac00
VERSION = 1
HANDINDIR = .

CC = gcc
CFLAGS = -g -O -Wall

btest: btest.c bits.c decl.c tests.c btest.h bits.h
	$(CC) $(CFLAGS) -o btest bits.c btest.c decl.c tests.c

handin:
	cp bits.c $(HANDINDIR)/$(TEAM)-$(VERSION)-bits.c

clean:
	rm -f *.o btest

