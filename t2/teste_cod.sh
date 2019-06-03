#!/bin/bash
make codificador
make clean
echo
echo "./codificador $1"
./codificador $1