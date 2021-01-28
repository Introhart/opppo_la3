#!/bin/bash
echo "BUILDING"
echo "***************"

clang++ main.cpp -o lab3.out

if [ $? -eq 0 ]
    then
        echo "RUN"
        echo "***************"
        ./lab3.out
fi





