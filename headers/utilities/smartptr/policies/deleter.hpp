#ifndef DELETER_HPP
#define DELETER_HPP

template <typename T>
class DefaultDeleter
{
    public:
        void operator()(T* p) {delete p;}
};


#endif // DELETER_HPP
