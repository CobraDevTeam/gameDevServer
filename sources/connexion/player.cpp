#include "headers/connexion/player.hpp"
#include "headers/instance.hpp"

#include <iostream>

// On initialise la variable statique
unsigned long Player::ID::_nextID = 0;

Player::Player(sf::TcpSocket* socket, std::shared_ptr<Instance> instance)
: mSocket(socket)
, mCurrentInstance(instance)
, mID()
{}

void Player::changeInstance(std::shared_ptr<Instance> nextInstance)
{
    mCurrentInstance = nextInstance;
}

void Player::run()
{
    std::cout << "Player " << mID << " started to run" << std::endl;

    bool connectionActive(true);
    sf::Packet receivedPacket;

    while(connectionActive)
    {
        sf::Socket::Status status = mSocket->receive(receivedPacket);
        switch (status)
        {
            case sf::Socket::Done:
            {
                // Ici on traite le paquet, comme par exemple ci-dessous
                //sf::Uint16 request;
                //receivedPacket >> request;
                //std::cout << request << std::endl;
                break;
            }
            case sf::Socket::Disconnected:
                connectionActive = false;
                break;

            case sf::Socket::Error:
                std::cout << "Error with connection " << mID << std::endl;
                connectionActive = false;
                break;
            default:
                std::cout << "Problem with connection " << mID << std::endl;
                connectionActive = false;
                break;
        }
    }
    std::cout << "Thread " << mID << " is ending" << std::endl;
}

