#include "services/PacketInspectionService.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    	if (argc != 2)
    	{
        	std::cerr << "Usage: sudo ./build/NetworkPacketInspection <interface>" << std::endl;
        	std::cerr << "Example: sudo ./build/NetworkPacketInspection wlp2s0f0" << std::endl;
        	return 1;
    	}

    	std::string interfaceName = argv[1];
	
	PacketInspectionService service(interfaceName);

	if (!service.run()) return 1;

	return 0;
}
