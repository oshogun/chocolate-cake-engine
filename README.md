# chocolate-cake-engine
A simple, extendable 2D game engine

--------------------

Chocolate Cake is a free, open source engine written in C++ and using
the SFML library. While the SFML library by itself is already great
for game development in C++, it still requires users to write their
own game logic and engine. The idea of Chocolate Cake is to go 
beyond that, and provide effective and extendable abstractions so
that the developer may focus on their game designs.

The main goal is to make it easy and productive to make 2d games as long
as you have some knowledge of C++. The engine also needs to be flexible
so that it can be extended and improved as needed.

## Requirements:

This engine uses C++ and the SFML library. It already provides a makefile
for compiling it on Linux systems, but you should be able to compile it 
in Windows systems as well.

In Linux, you will need the g++ compiler that is compatible with the 
C++11 standard, and the SFML libraries. On Debian-based systems (such
as Ubuntu):

1. Install build tools and  g++
	1. *$ sudo apt-get install build-essential*
	2. *$ sudo apt-get install g++*
2. Install SFML:
	1. *$ sudo apt-get install libsfml-dev*
3. Build the code:
	1. *make*

On Fedora:

1. Install g++
	1. *$ sudo dnf install gcc-c++*
2. Install SFML:
	1. *$ sudo dnf install SFML-devel*
3. Build the code:
	1. Make

On Arch Linux:
1. Install g++:
	1. *$ sudo pacman -S g++*
2. Install SFML:
	1. *$ sudo pacman -S sfml*
3. Build the code:
	1. *$ make*