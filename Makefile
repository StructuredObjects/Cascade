.PHONY: all

all: build

build:
	gcc main.c -o net -pthread -Wall