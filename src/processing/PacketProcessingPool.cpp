#include "processing/PacketProcessingPool.h"

PacketProcessingPool::PacketProcessingPool(PacketQueue<RawPacket>& packetQueue) : packetQueue(packetQueue) 
{
}

void PacketProcessingPool::start(std::size_t threadCount)
{
	std::cout << "Processing pool started" << std::endl;

	for (std::size_t i = 0; i < threadCount; ++i)
	{
		workers.emplace_back(&PacketProcessingPool::workerLoop, this);
	}
}

void PacketProcessingPool::stop()
{
	packetQueue.stop();
	
	for (std::thread& worker : workers)
	{
        	if (worker.joinable())
        	{
            		worker.join();
        	}
    	}

	workers.clear();
	std::cout << "Processing pool stopped\n";
}

void PacketProcessingPool::workerLoop()
{
	RawPacket packet;
	while(packetQueue.pop(packet))
	{
		std::cout << "Worker processed packet of size: " << packet.bytes.size() << " bytes\n";
	}
}
