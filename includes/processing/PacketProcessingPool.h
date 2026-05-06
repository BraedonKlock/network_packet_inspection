#ifndef PACKET_PROCESSING_POOL_H
#define PACKET_PROCESSING_POOL_H

#include "queue/PacketQueue.h"
#include "packets/RawPacket.h"

#include <vector>
#include <thread>

class PacketProcessingPool
{
	private:
		std::vector<std::thread> workers;
		PacketQueue<RawPacket>& packetQueue;

		void workerLoop();
	public:
		explicit PacketProcessingPool(PacketQueue<RawPacket>& packetQueue);
		void start(std::size_t threadCount);
		void stop();

};

#endif
