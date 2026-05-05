#ifndef TCP_PACKET_H
#define TCP_PACKET_H

#include "packets/PacketType.h"
#include "packets/Packet.h"

class TcpPacket : public Packet
{
	private:

	public:
		PacketType getType() const override { return PacketType::TCP; }
};

#endif
