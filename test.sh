#!/bin/sh
clear
make debug
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#./push_swap $@
./push_swap $@ | ./checker -v $@
