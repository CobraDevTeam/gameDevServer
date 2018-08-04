#ifndef STORAGE_HPP
#define STORAGE_HPP


template <typename T>
class DefaultStorage
{
    public:
        using StoredType = T*;
        using PointerType = T*;
        using ReferenceType = T&;

    public:
        DefaultStorage(StoredType ptr) : mPtr(ptr) {} // Constructeur
        DefaultStorage(DefaultStorage<T>& def) : mPtr(def.mPtr) {}

        DefaultStorage& operator=(const DefaultStorage& def)
        {
            if(this != &def)
                mPtr = def.mPtr;
            return *this;
        }

        PointerType operator->() const {return mPtr;}
        ReferenceType operator*() const {return *mPtr;}

        template<typename Deleter>
        void destroy(Deleter d) {d(mPtr); /*std::cout << "ptr destroyed" << std::endl;*/}

    private:
        StoredType mPtr;
};

template <typename T>
class SafeStorage
{
    private:
        class LockingProxy
        {
            public:
                LockingProxy(T* ptr) : mPtr(ptr) {/*std::cout << "lock" << std::endl*/;mPtr->lock();}
                ~LockingProxy() {/*std::cout << "unlock" << std::endl*/;mPtr->unlock();}

                T* operator->() const {return mPtr;}

                LockingProxy& operator=(const LockingProxy&) = delete;
            private:
                T* mPtr;
        };
    public:
        using StoredType = T*;
        using PointerType = LockingProxy;
        using ReferenceType = T&;

    public:
        SafeStorage(StoredType ptr) : mPtr(ptr) {} // Constructeur
        SafeStorage(DefaultStorage<T>& def) : mPtr(def.mPtr) {}

        SafeStorage& operator=(const SafeStorage& def)
        {
            if(this != &def)
                mPtr = def.mPtr;
            return *this;
        }

        PointerType operator->() const {return LockingProxy(mPtr);}
        ReferenceType operator*() = delete;

        template<typename Deleter>
        void destroy(Deleter d) {d(mPtr); /*std::cout << "ptr destroyed" << std::endl;*/}

    private:
        StoredType          mPtr;
};


#endif // STORAGE_HPP
