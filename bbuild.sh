#!/usr/bin/env bash

source cclang-formatter.sh

rm -rf build
cmake -S . -B build -D TARGET_GROUP=$1
cmake --build build