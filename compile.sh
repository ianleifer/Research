#!/bin/bash

#g++ *.cpp -lgraph -L/usr/local/lib -lX11 -o model
g++ *.cpp -DTRACE -g -pedantic -Wall -Wextra -lgraph -L/usr/local/lib -lX11 -o model
test $? -eq 0 && clear
