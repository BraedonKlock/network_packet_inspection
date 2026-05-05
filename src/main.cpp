#include "services/PacketInspectionService.h"

#include <csignal>
#include <iostream>
#include <string>

PacketInspectionService* servicePtr = nullptr;

void handleSignal(int signal) 
{
	if (signal == SIGINT && servicePtr != nullptr) 
	{
        	servicePtr->requestStop();
    	}
}


int main(int argc, char* argv[])
{
    	if (argc != 2)
    	{
        	std::cerr << "Usage: sudo ./build/NetworkPacketInspection <interface>" << std::endl;
        	std::cerr << "Example: sudo ./build/NetworkPacketInspection wlp2s0f0" << std::endl;
        	return 1;
    	}
	
	std::signal(SIGINT, handleSignal);

    	std::string interfaceName = argv[1];
	
	PacketInspectionService service(interfaceName);

	servicePtr = &service;

    	if (!service.run())
    	{
        	servicePtr = nullptr;
        	return 1;
    	}

    	servicePtr = nullptr;

	return 0;
}
