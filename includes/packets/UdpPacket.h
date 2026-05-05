#ifndef UDP_PACKET_H
#define UDP_PACKET_H

#include "packets/PacketType.h"
#include "packets/Packet.h"

class UdpPacket : public Packet
{
	private:

	public:
		PacketType getType() const override { return PacketType::UDP; }
};

#endif

