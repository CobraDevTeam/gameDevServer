#ifndef SMARTPTR_HPP
#define SMARTPTR_HPP

#include "policies/deleter.hpp"
#include "policies/storage.hpp"
#include "policies/ownership.hpp"


template
<
typename T,
template<class> class OwnershipPolicy = RefCounting,
template<class> class StoragePolicy = DefaultStorage,
template<class> class Deleter = DefaultDeleter
>
class SmartPtr
{
    public:
        explicit SmartPtr(T* ptr) : mOwnPolicy(), mStorageP(ptr) {}
        explicit SmartPtr(SmartPtr& ptr) : mOwnPolicy(ptr.mOwnPolicy), mStorageP(ptr.mStorageP){}

        ~SmartPtr() {clean();}

        SmartPtr& operator=(const SmartPtr& ptr)
        {
            if(this != &ptr)
            {
               clean();
               mStorageP = ptr.mStorageP;
               mOwnPolicy = ptr.mOwnPolicy;
            }
            return *this;
        }

        typename StoragePolicy<T>::PointerType operator->() const {return mStorageP.operator->();}
        typename StoragePolicy<T>::ReferenceType operator*() const {return mStorageP.operator*();}

        void clean()
        {
            if(mOwnPolicy.release())
                mStorageP.destroy(mDeleter);
        }

    private:
        OwnershipPolicy<T*> mOwnPolicy;
        StoragePolicy<T>    mStorageP;
        Deleter<T>          mDeleter;
};

#endif // SMARTPTR_HPP
