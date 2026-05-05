#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

#include <pcap.h>
#include <iostream>
#include <string>

void packetHandler(u_char* userData, const pcap_pkthdr* packetHeader, const u_char* packetData);

class PacketCapture
{
	private:
		std::string interfaceName;
		pcap_t* handle;
	public:
		PacketCapture(const std::string& interfaceName) : interfaceName(interfaceName), handle(nullptr) {}

    		bool open();

    		void start();
		
		~PacketCapture()
		{
        		if (handle != nullptr)
			{
            			pcap_close(handle);
        		}
    		}
};

#endif
