#ifndef RAW_PACKET_H
#define RAW_PACKET_H

#include <vector>
#include <cstddef>
#include <cstdint>

struct RawPacket
{
	std::vector<std::uint8_t> bytes;
	std::size_t length;
};

#endif
