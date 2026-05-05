#ifndef PACKET_H
#define PACKET_H

#include "packets/PacketType.h"

class Packet
{
	private:
	

	public:
		virtual PacketType getType() const = 0;

		virtual ~Packet() = default;
};

#endif
