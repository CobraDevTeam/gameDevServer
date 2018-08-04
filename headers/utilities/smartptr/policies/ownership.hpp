#ifndef OWNERSHIP_HPP
#define OWNERSHIP_HPP

#include <mutex>

template <typename P>
class RefCounting
{
    public:
        RefCounting() : mCount(new unsigned int(1)) {}
        RefCounting(RefCounting<P>& ref) : mCount(ref.acquire()) {}

        RefCounting& operator=(const RefCounting<P>& ref)
        {
            if(this != &ref)
            {
                mCount = ref.acquire();
            }
            return *this;
        }

        unsigned int* acquire()
        {
            ++*mCount;
            return mCount;
        }

        bool release()
        {
            if(!--*mCount)
            {
                delete mCount;
                return true;
            }
            return false;
        }

    private:
        unsigned int* mCount;
};

template <typename P>
class SafeRefCounting
{
    public:
        SafeRefCounting() : mCount(new unsigned int(1)), mLock(new std::mutex) {}
        SafeRefCounting(const SafeRefCounting<P>& ref) : mCount(ref.acquire()), mLock(ref.mLock) {}

        SafeRefCounting& operator=(const SafeRefCounting<P>& ref)
        {
            if(this != &ref)
            {
                mLock = ref.mLock;
                mCount = ref.acquire();
            }
            return *this;
        }

        unsigned int* acquire()
        {
            std::lock_guard<std::mutex> guard(*mLock);
            ++*mCount;
            return mCount;
        }

        bool release()
        {
            std::lock_guard<std::mutex> guard(*mLock);
            if(!--*mCount)
            {
                delete mCount;
                return true;
            }
            return false;
        }

    private:
        unsigned int*   mCount;
        std::mutex*     mLock;

};


#endif // OWNERSHIP_HPP
