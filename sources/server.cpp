#include "headers/server.hpp"

#include <thread>

#include <iostream>

Server::Server()
: mGateway(this)
{

}

void Server::handleNewConnection(sf::TcpSocket& newClient)
{
    // fais quelque chose avec newClient
}

void Server::run()
{
    // On lance l'ecoute de la gateway dans un autre thread
    std::thread waitingNewClientsThread([this] {mGateway.run();});

    // Do something

    waitingNewClientsThread.join();
}
