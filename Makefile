CC=g++
OUTDIR=bin
INCLUDEDIR=include 
SRCDIR=src

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:build

build:
	$(CC) $(SRCDIR)/*.cpp -I$(INCLUDEDIR) -o $(OUTDIR)/cake $(LIBS)

clean:
	rm bin/*


