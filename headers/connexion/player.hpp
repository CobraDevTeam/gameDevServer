#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Network/TcpSocket.hpp>

#include <memory>
#include <ostream>

#include "headers/connexion/packet.hpp"

class Instance;

/**
 * @brief Classe encapsulant la connexion entre un joueur et le serveur
 *
 * Cette classe a vocation a tourner dans un thread séparé
 */
class Player
{
    public:
        /// Un alias de pointeur sur Player
        using Ptr = std::unique_ptr<Player>;

        /**
         * @brief Une struct encapsulant un identifiant de joueur
         * Peut être utiliser du strong typing générique à terme
         */
        struct ID
        {
                ID():_id(_nextID++) {}

                unsigned long get() const
                {
                    return _id;
                }

                friend std::ostream& operator<<(std::ostream& flux, ID id)
                {
                    flux << id._id;
                    return flux;
                }

            private:
                unsigned long _id;
                static unsigned long _nextID;
        };

    public:
                /**
                 * @brief Constructeur de player
                 * @param socket la connexion avec le client
                 * @param instance l'instance initiale dans laquelle se trouve le joueur
                 */
                Player(sf::TcpSocket* socket, std::shared_ptr<Instance> instance);

                /**
                 * @brief Permet de déplacer le joueur d'une instance à l'autre
                 * @param nextInstance la nouvelle instance dans laquelle se trouver le joueur
                 */
        void    changeInstance(std::shared_ptr<Instance> nextInstance);

                /**
                 * @brief Méthode appelée lorsqu'une deconnexion est constatée
                 */
        void    handleDisconnection();

                /**
                 * @brief Méthode appelée lorsqu'un parquet est correctement reçu et doit être traité
                 * @param receivedPacket le paquet reçu
                 */
        void    handlePacket(Packet receivedPacket);

                /**
                 * @brief boucle principale d'exécution du thread du joueur
                 */
        void    run();

    private:
        /// La socket encapsulant la connexion avec le joueur
        sf::TcpSocket*                  mSocket;
        /// Un pointeur sur l'instance de référence actuelle du joueur
        std::shared_ptr<Instance>       mCurrentInstance;

        /// L'identifiant du joueur : doit absolument être unique
        ID                              mID;
};

#endif // PLAYER_HPP
