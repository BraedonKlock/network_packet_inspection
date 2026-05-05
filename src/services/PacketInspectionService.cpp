#include "services/PacketInspectionService.h"

#include <iostream>

PacketInspectionService::PacketInspectionService(const std::string& interfaceName) 
	: packetQueue(), capture(interfaceName, packetQueue), processingPool(packetQueue)
{
}

bool PacketInspectionService::run()
{
	processingPool.start(4);

	if (!capture.open())
	{
        	std::cerr << "Failed to open capture interface." << std::endl;
        	return false;
    	}

    	std::cout << "Starting packet capture.." << std::endl;
    	capture.start();
	
	processingPool.stop();
	capture.close();
	
	std::cout << "Packet inspection service stopped cleanly\n";
    	
	return true;
}

void PacketInspectionService::requestStop() 
{
	if (stopRequested.exchange(true))
	{
        	return;
    	}

    	std::cout << "\nShutdown requested...\n";

    	capture.stop();
}
