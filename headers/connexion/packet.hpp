#ifndef PACKET_HPP
#define PACKET_HPP

#include <SFML/Network/Packet.hpp>

/// Inutilisée pour l'instant
class Packet : public sf::Packet
{
    public:
        enum class Flag : sf::Uint16
        {
            requestSearchGame = 0,
            requestStopSearch = 1,
            requestLeaveGame = 2,

            IntMessage
        };
};

#endif // PACKET_HPP
