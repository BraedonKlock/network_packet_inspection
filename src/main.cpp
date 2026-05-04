#include "PacketCapture.h"

int main(int argc, char* argv[])
{
    	if (argc != 2)
    	{
        	std::cerr << "Usage: sudo ./build/PacketInspectionEngine <interface>" << std::endl;
        	std::cerr << "Example: sudo ./build/PacketInspectionEngine wlp2s0f0" << std::endl;
        	return 1;
    	}

    	std::string interfaceName = argv[1];
	PacketCapture capture(interfaceName);

	if (!capture.open())
	{
		std::cerr << "Failed to open capture interface." << std::endl;
		return 1;
	}

	std::cout << "Starting packet capture.." << std::endl;
	capture.start();

	return 0;
}
