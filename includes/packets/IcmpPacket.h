#ifndef ICMP_PACKET_H
#define ICMP_PACKET_H

#include "packets/PacketType.h"
#include "packets/Packet.h"

class IcmpPacket : public Packet
{
	private:

	public:
		PacketType getType() const override { return PacketType::ICMP; }
};

#endif

