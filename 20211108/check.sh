#!/bin/bash
while true; do
  ./data > data.in
    ./1312 <data.in >std.out
    ./1312_R <data.in >Todobe.out
    if diff std.out Todobe.out; then
        printf "AC\n"
    else
        printf "WA\n"
        exit 0
    fi
  done