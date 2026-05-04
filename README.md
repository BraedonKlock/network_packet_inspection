# cpp_packet_inspection_engine

Linux-based C++ packet inspection engine that parses TCP/IP traffic and detects suspicious network behavior.

## Requirements

This project requires:

- C++20 compiler
- CMake
- Ninja
- libpcap

## Install Dependencies

On Ubuntu/Debian-based Linux systems, install the required tools with:

```bash
sudo apt update
sudo apt install cmake ninja-build libpcap-dev
```

## How to Build and Run

This project uses CMake and Ninja.

### 1. Configure the build

From the project root, run:

```bash
cmake -S . -B build -G Ninja
```

### 2. Build the project

```bash
cmake --build build
```

### 3. Run the program

Packet capture usually requires elevated permissions, so run the executable with `sudo`:

```bash
sudo ./build/PacketInspectionEngine
```
