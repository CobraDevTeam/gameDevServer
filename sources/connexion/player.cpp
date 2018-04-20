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
    Packet receivedPacket;

    while(connectionActive)
    {
        sf::Socket::Status status = mSocket->receive(receivedPacket);
        switch (status)
        {
            case sf::Socket::Done:
            {
                handlePacket(receivedPacket);
                break;
            }
            case sf::Socket::Disconnected:
                connectionActive = false;
                handleDisconnection();
                break;

            case sf::Socket::Error:
                std::cout << "Error with connection " << mID << std::endl;
                connectionActive = false;
                handleDisconnection();
                break;

            default:
                std::cout << "Problem with connection " << mID << std::endl;
                connectionActive = false;
                handleDisconnection();
                break;
        }
    }
    std::cout << "Thread " << mID << " is ending" << std::endl;
}

void Player::handleDisconnection()
{
    //TODO
}

void Player::handlePacket(Packet receivedPacket)
{
    //TODO
}
