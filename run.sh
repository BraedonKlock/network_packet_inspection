#!/bin/bash

set -e

INTERFACE=$1

if [ -z "$INTERFACE" ]; then
    echo "Usage: ./run.sh <interface>"
    echo "Example: ./run.sh wlp2s0f0"
    exit 1
fi

cmake -S . -B build -G Ninja
cmake --build build

sudo ./build/NetworkPacketInspection "$INTERFACE"
