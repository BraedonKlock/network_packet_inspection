#ifndef PACKET_INSPECTION_SERVICE_H
#define PACKET_INSPECTION_SERVICE_H

#include "PacketCapture.h"
#include "RawPacket.h"

#include <string>

class PacketInspectionService
{
	private:
		PacketCapture capture;
	public:
		explicit PacketInspectionService(const std::string& interfaceName);
		
		bool run();
};

#endif
