#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <list>
#include <memory>
#include <thread>

#include "headers/connexion/packet.hpp"
#include "headers/connexion/player.hpp"

/**
 * @brief Une classe dérivée de Instance (Instance est abstraite) instancie une instance de jeu de de salon
 * Un classe instance regrupe typiquement tous les joueurs en matchmaking, ou en attente, ou dans la meme instance de jeu
 */
class Instance
{
    public:
        /// Un alias de pointeur sur instance
        using Ptr = std::shared_ptr<Instance>;

    public:
        Instance();

        /**
         * @brief Enumerateur non utilisé pour l'instant
         * Servira à matcher les requêtes des joueurs
         */
        enum class Request
        {
            searchGame,
            stopSearch,
            leaveGame
        };

    public:
                /**
                 * @brief Fonction virtuelle pure permettant à l'instance de gérer les requêtes envoyées par les joueurs
                 * @param request la requête envoyée par un joueur
                 * @param playerID l'ID du joueur ayant envoyé la requête
                 */
        virtual void    handleRequest(Request request, unsigned long playerID) =0;

                /**
                 * @brief Ajoute un nouveau joueur dans la liste des joueurs de l'instance
                 * @param player Un pointeur sur le joueur à ajouter
                 */
                void    addPlayer(Player* player);

                //void    moveTo(Instance::Ptr);

    private:
        /// La liste des joueurs dans l'instance
        std::list<Player::Ptr>    mPlayersInInstance;

};

#endif // INSTANCE_HPP
