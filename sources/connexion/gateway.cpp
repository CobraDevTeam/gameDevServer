#include "headers/connexion/gateway.hpp"

#include "headers/server.hpp"

Gateway::Gateway(Server* server)
: mListener()
// Port abritraire temporaire
, mListeningPort(50001)
, mServer(server)
{

}

void Gateway::run()
{
    mListener.listen(mListeningPort);

    // Endless loop that waits for new connections
    while(true)
    {
        sf::TcpSocket client;
        // Si un nouveau client demande à se connecter
        if(mListener.accept(client) == sf::Socket::Done)
        {
            // La socket est initialisée pour la nouvelle connexion, et envoyée en traitement au serveur
            (*mServer).handleNewConnection(client);
        }
    }

}
