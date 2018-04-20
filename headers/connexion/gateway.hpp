#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

#include <SFML/System/NonCopyable.hpp>

#include "player.hpp"

#include <thread>

class Server;

/**
 * @brief Classe gérant les connexions entre le serveur et les clients. Toute connexion passe par elle
 *
 * La fonction Gateway::run est une boucle infinie et a vocation a tourner dans un thread a part.
 * Gateway estnon copiable car unique
 */

class Gateway : private sf::NonCopyable
{
    public:
        /**
         * @brief Constructeur de gateway
         * @param server Un pointeur sur le serveur de référence de la gateway
         */
        Gateway(Server* server);

        ///
        void run();

    private:
        /// Une socket particulière écoutant pour les nouvelles demandes de connexion
        sf::TcpListener             mListener;
        /// Le port sur lequel la gateway écoute
        unsigned int                mListeningPort;

        /// Le serveur qui gère cette gateway
        std::shared_ptr<Server>     mServer;
};

#endif // GATEWAY_HPP
