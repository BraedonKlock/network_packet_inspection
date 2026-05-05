#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

#include "queue/PacketQueue.h"
#include "packets/RawPacket.h"

#include <pcap.h>
#include <iostream>
#include <string>

void packetHandler(u_char* userData, const pcap_pkthdr* packetHeader, const u_char* packetData);

class PacketCapture
{
	private:
		std::string interfaceName;
		pcap_t* handle;
		PacketQueue<RawPacket>& packetQueue;
	public:
		PacketCapture(const std::string& interfaceName, PacketQueue<RawPacket>& packetQueue) 
			: interfaceName(interfaceName), handle(nullptr), packetQueue(packetQueue) {}

    		bool open();
    		void start();
		void stop();
		void close();
		
		~PacketCapture()
		{
        		if (handle != nullptr)
			{
            			pcap_close(handle);
        		}
    		}
};

#endif
