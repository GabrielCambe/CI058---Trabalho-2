#!/bin/bash
if [ -n "$1" ]
then
    make codificador
    make decodificador
    make clean
    echo
    echo "./codificador $1"
    ./codificador $1
    echo
    echo "./decodificador arq_bin.txt"
    ./decodificador arq_bin.txt
    echo
    echo diff corrigido.txt $1
    diff corrigido.txt $1

else
    make decodificador
    make clean
    echo
    echo "./decodificador arq_bin.txt"
    ./decodificador arq_bin.txt
fi