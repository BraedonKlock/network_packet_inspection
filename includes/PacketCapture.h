#include <pcap.h>
#include <iostream>
#include <string>

void packetHandler(u_char* userData, const pcap_pkthdr* packetHeader, const u_char* packetData);

class PacketCapture
{
	private:
		std::string interfaceName;
		pcap_t* handle;
	public:
		PacketCapture(const std::string& interfaceName) : interfaceName(interfaceName), handle(nullptr) {}

    	bool open()
	{
        	char errorBuffer[PCAP_ERRBUF_SIZE];

        	handle = pcap_open_live(interfaceName.c_str(), BUFSIZ, 1, 1000, errorBuffer);

        	if (handle == nullptr) {
            		std::cerr << "Error opening interface: " << errorBuffer << "\n";
            		return false;
        	}

        	return true;
    	}

    	void start()
	{
        	if (handle == nullptr)
		{
            		std::cerr << "Cannot start capture. Interface is not open.\n";
            		return;
        	}

        	pcap_loop(handle, -1, packetHandler, nullptr);
    	}

    	~PacketCapture()
    	{
        	if (handle != nullptr)
		{
            		pcap_close(handle);
        	}
    	}
};

void packetHandler( u_char* userData, const pcap_pkthdr* packetHeader, const u_char* packetData) 
{
	std::cout << "Captured packet of length: " << packetHeader->len << " bytes\n";
}
