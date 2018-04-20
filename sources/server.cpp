#include "headers/server.hpp"

#include <thread>

#include <iostream>

Server::Server()
: mGateway(this)
, mThreads()
, mIdMap()
, mWaitingInstance()
{

}

void Server::handleNewConnection(sf::TcpSocket* newClient)
{
    std::cout << "Nouveau client connecté : " << newClient->getRemoteAddress() << std::endl;

    // Construction du nouveau joueur
    Player newPlayer(newClient, mWaitingInstance);

    // On ajoute le thread du jouveau joueur au conteneur
    mThreads.push_back(std::thread(&Player::run, newPlayer));
    // On ajoute le nouveau joueur dans l'instance d'attente
    mWaitingInstance->addPlayer(&newPlayer);
}

void Server::run()
{
    // On lance l'ecoute de la gateway dans un autre thread
    std::thread waitingNewClientsThread([this] {mGateway.run();});

    // Do something

    waitingNewClientsThread.join();
}
