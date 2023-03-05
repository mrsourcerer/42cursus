#!/bin/bash
ARG=$1;
make
echo "------------------------------------"
./push_swap $ARG
echo "------------------------------------"
./push_swap $ARG | wc -l
echo "------------------------------------"
./push_swap $ARG | ./checker_linux $ARG
