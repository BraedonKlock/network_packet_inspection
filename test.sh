#!/bin/bash

set -e

INTERFACE=$1

if [ -z "$INTERFACE" ]; then
    echo "Usage: ./test.sh <interface>"
    echo "Example: ./test.sh wlp2s0f0"
    exit 1
fi

echo "========== Normal Build =========="
cmake -S . -B build -G Ninja
cmake --build build

echo
echo "========== Valgrind Memory Leak Test =========="
sudo valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    ./build/NetworkPacketInspection "$INTERFACE"

echo
echo "========== Valgrind Thread Race Test =========="
sudo valgrind \
    --tool=helgrind \
    ./build/NetworkPacketInspection "$INTERFACE"

echo
echo "========== Performance Test =========="
sudo perf stat ./build/NetworkPacketInspection "$INTERFACE"
