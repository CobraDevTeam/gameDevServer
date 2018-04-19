#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

#include <SFML/System/NonCopyable.hpp>

class Server;

/**
 * @brief Classe gérant les connexions entre le serveur et les clients. Toute connexion passe par elle
 *
 * La fonction Gateway::run est une boucle infinie et a vocation a tourner dans un thread a part
 */

namespace connect
{

class Gateway : private sf::NonCopyable
{
    public:
        Gateway(Server* server);

        ///
        void run();

    private:
        /// Une socket particulière écoutant pour les nouvelles demandes de connexion
        sf::TcpListener     mListener;
        unsigned int        mListeningPort;

        Server*             mServer;
};

}

#endif // GATEWAY_HPP
