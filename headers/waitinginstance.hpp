#ifndef WAITINGINSTANCE_HPP
#define WAITINGINSTANCE_HPP

#include "headers/instance.hpp"

class WaitingInstance : public Instance
{
    public:
        using Ptr = std::shared_ptr<WaitingInstance>;

    public:
        WaitingInstance();

        void handleRequest(Instance::Request request, unsigned long playerID);
};

#endif // WAITINGINSTANCE_HPP
