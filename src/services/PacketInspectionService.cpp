#include "services/PacketInspectionService.h"

#include <iostream>

PacketInspectionService::PacketInspectionService(const std::string& interfaceName) 
	: packetQueue(), capture(interfaceName, packetQueue)
{
}

bool PacketInspectionService::run()
{
	if (!capture.open())
	{
        	std::cerr << "Failed to open capture interface." << std::endl;
        	return false;
    	}

    	std::cout << "Starting packet capture.." << std::endl;
    	capture.start();

    	return true;
}
