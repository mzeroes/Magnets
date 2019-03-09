#!/bin/bash
cd ..

clang-tidy test.cpp -- -I ./include
