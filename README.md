# cpp_packet_inspection_engine

Linux-based C++ packet inspection engine that parses TCP/IP traffic and detects suspicious network behavior.

## How to Build and Run

This project uses CMake and Ninja.

### 1. Configure the build

From the project root, run:

```bash
cmake -S . -B build -G Ninja
cmake --build build
sudo ./build/PacketInspectionEngine
