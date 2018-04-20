#ifndef SERVER_HPP
#define SERVER_HPP

#include<SFML/Network/TcpSocket.hpp>
#include<SFML/System/NonCopyable.hpp>

#include <list>
#include <map>

#include "connexion/gateway.hpp"
#include "connexion/player.hpp"
#include "headers/waitinginstance.hpp"
/**
 * @brief Classe encapsulant toute la gestion du serveur
 */
class Server : private sf::NonCopyable
{
    public:
        /**
         * @brief Constructeur, devrait grossir au fur et à mesure
         */
        Server();

        /**
         * @brief Boucle principale d'exécution
         */
        void run();

        /**
         * @brief Fonction appelée lorsque mGateway détecte une nouvelle connexion
         * @param newClient la TcpSocket encapsulant la connexion avec le nouveau client
         */
        void handleNewConnection(sf::TcpSocket* newClient);

    private:
        /// La classe permettant d'attendre gérer de nouvelles tentatives de connexion
        Gateway                                                 mGateway;
        /// Le conteneur de tous les threads actifs
        std::list<std::thread>                                  mThreads;
        /// Une map permettant d'associer un id à la position du thread associé dans mThreads
        std::map<unsigned int, decltype(mThreads)::iterator>    mIdMap;

        /// L'instance contenant tous les joueurs en idle
        WaitingInstance::Ptr                                    mWaitingInstance;

};

#endif // SERVER_HPP
