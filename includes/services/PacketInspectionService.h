#ifndef PACKET_INSPECTION_SERVICE_H
#define PACKET_INSPECTION_SERVICE_H

#include "capture/PacketCapture.h"
#include "packets/RawPacket.h"
#include "queue/PacketQueue.h"

#include <string>

class PacketInspectionService
{
	private:
		PacketQueue<RawPacket> packetQueue;
		PacketCapture capture;
	public:
		explicit PacketInspectionService(const std::string& interfaceName);
		
		bool run();
};

#endif
