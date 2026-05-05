#ifndef PACKET_INSPECTION_SERVICE_H
#define PACKET_INSPECTION_SERVICE_H

#include "capture/PacketCapture.h"
#include "packets/RawPacket.h"
#include "queue/PacketQueue.h"
#include "processing/PacketProcessingPool.h"

#include <string>
#include <atomic>

class PacketInspectionService
{
	private:
		PacketQueue<RawPacket> packetQueue;
		PacketCapture capture;
		PacketProcessingPool processingPool;
		std::atomic<bool> stopRequested;

	public:
		explicit PacketInspectionService(const std::string& interfaceName);
		
		bool run();
		void requestStop();
};

#endif
