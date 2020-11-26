
SRC = src
BIN = bin

CC = g++
FLAGS = -Wall -lglut -lGLU -lGL

all: clear compile

compile:
	$(CC) $(SRC)/* -o main $(FLAGS)

clear:
	rm -rf $(BIN)/*

test:
	$(CC) $(SRC)/test.cpp -o test $(FLAGS)