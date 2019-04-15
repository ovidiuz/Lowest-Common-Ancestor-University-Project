#!/bin/bash

build:
	g++ -Wall TarjanLCA.cpp -o TarjanLCA
	g++ -Wall LCA_using_RMQ.cpp -o LCA_using_RMQ

generator:
	g++ -Wall generator.cpp -o generator

BruteForceLCA:
	g++ -Wall BruteForceLCA.cpp -o BruteForceLCA

clean:
	rm -rf TarjanLCA LCA_using_RMQ 