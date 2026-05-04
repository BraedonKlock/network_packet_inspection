#include "PacketCapture.h"

int main()
{
	PacketCapture capture("wlp2s0f0");

	if (!capture.open())
	{
		std::cerr << "Failed to open capture interface." << std::endl;
		return 1;
	}

	std::cout << "Starting packet capture.." << std::endl;
	capture.start();

	return 0;
}
