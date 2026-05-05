#include "PacketCapture.h"

void packetHandler(u_char* userData, const pcap_pkthdr* packetHeader, const u_char* packetData)
{
	std::cout << "Captured packet of length: " << packetHeader->len << " bytes\n";
	
	auto* packetQueue = reinterpret_cast<PacketQueue<RawPacket>*>(userData);
	RawPacket packet;
	packet.bytes.assign(packetData, packetData + packetHeader->len);
	packetQueue->push(packet);
}

bool PacketCapture::open()
{
	char errorBuffer[PCAP_ERRBUF_SIZE];

	handle = pcap_open_live(interfaceName.c_str(), BUFSIZ, 1, 1000, errorBuffer);

	if (handle == nullptr)
	{
		std::cerr << "Error opening interface: " << errorBuffer << "\n";
		return false;
	}

	return true;
}

void PacketCapture::start()
{
	if (handle == nullptr)
	{
		std::cerr << "Cannot start capture. Interface is not open.\n";
		return;
	}

	pcap_loop(handle, -1, packetHandler, reinterpret_cast<u_char*>(&packetQueue));
}
