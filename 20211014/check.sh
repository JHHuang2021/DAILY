#!/bin/bash
while true; do
  ./data > data.in
    ./20211025T3 <data.in >std.out
    ./20211025T3_Revised <data.in >Todobe.out
    if diff std.out Todobe.out; then
        printf "AC\n"
    else
        printf "WA\n"
        exit 0
    fi
  done