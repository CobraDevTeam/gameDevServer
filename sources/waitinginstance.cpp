#include "headers/waitinginstance.hpp"

#include <iostream>

WaitingInstance::WaitingInstance() : Instance()
{

}



void WaitingInstance::handleRequest(Instance::Request request, unsigned long playerID)
{
    switch (request) {
        case Instance::Request::searchGame:
            std::cout << "Player " << playerID << " now searches for game" << std::endl;
            break;
        default:
            break;
    }
}
