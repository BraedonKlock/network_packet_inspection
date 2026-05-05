# network_packet_inspection

Linux-based C++ network packet inspection that parses TCP/IP traffic and detects suspicious network behavior.

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

### 3. Find your network interface

Before running the program, find the name of the network interface you want to capture packets from:

```bash
ip link
```

Example interface names may include:

```text
wlp2s0f0
wlan0
eth0
enp0s3
```

### 4. Run the program

Packet capture usually requires elevated permissions, so run the executable with `sudo` and provide the interface name as an argument:

```bash
sudo ./build/NetworkPacketInspection <interface-name>
```

Example:

```bash
sudo ./build/NetworkPacketInspection wlp2s0f0
```
## Project Directory Structure

```text
network_packet_inspection/
│
├── CMakeLists.txt
├── includes
│   ├── capture
│   │   └── PacketCapture.h
│   ├── packets
│   │   ├── IcmpPacket.h
│   │   ├── Packet.h
│   │   ├── PacketType.h
│   │   ├── RawPacket.h
│   │   ├── TcpPacket.h
│   │   └── UdpPacket.h
│   ├── parsers
│   │   ├── IcmpParser.h
│   │   ├── Parser.h
│   │   ├── TcpParser.h
│   │   └── UdpParser.h
│   ├── processing
│   │   └── PacketProcessingPool.h
│   ├── queue
│   │   └── PacketQueue.h
│   └── services
│       └── PacketInspectionService.h
├── README.md
├── run.sh
└── src
    ├── capture
    │   └── PacketCapture.cpp
    ├── main.cpp
    └── services
        └── PacketInspectionService.cpp
```

## How It Works

The program captures live network traffic from a specified interface and processes each packet through a structured pipeline.

### Flow

1. The program starts and takes a network interface as input  
2. A `PacketInspectionService` object is created to manage the system  
3. Packet capture begins using libpcap  
4. Each captured packet triggers a callback function (`packetHandler`)  
5. The raw packet data is copied into a `RawPacket` object  
6. The packet is pushed into a thread-safe queue (`PacketQueue`) for processing  

### Architecture

```text
PacketInspectionService
        │
        ├── owns → PacketCapture
        ├── owns → PacketQueue
        │
PacketCapture (producer)
        │
        └── pushes RawPacket → PacketQueue
                           ↓
                     PacketQueue
                           ↓
   (FUTURE)    Worker Threads (consumers)
                           ↓
                pop RawPacket from queue
                           ↓
            classify packet type (TCP/UDP/ICMP)
                           ↓
                 select appropriate parser
                           ↓
          TcpPacketParser / UdpPacketParser / IcmpPacketParser
                           ↓
     create TcpPacket / UdpPacket / IcmpPacket object
