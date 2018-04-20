#include "headers/instance.hpp"

Instance::Instance()
{}

void Instance::addPlayer(Player* player)
{
    mPlayersInInstance.insert(mPlayersInInstance.end(), Player::Ptr(player));
}
