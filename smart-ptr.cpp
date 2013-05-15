/**
 * a smart pointer template class
 */
#include "counter.h"

// debugging
#include <iostream>
using namespace std;

template < typename T > class SmartPtr
{
    private:
        /**
         * the pointer being wrapped
         */
        T* ptr;
        
        /**
         * Counter used to maintain a reference count
         * to this ptr instance
         */
        Counter* ref;

    public:
        SmartPtr() : ptr(0), ref(0)
        {
            ref = new Counter;
            ref->inc();
        }

        SmartPtr(T* value) : ptr(value), ref(0)
        {
            ref = new Counter;
            ref->inc();
        }
        
        /**
         * Copy constructor
         * keep a reference to the pointer and increment the shared reference counter
         */
        SmartPtr(const SmartPtr<T>& p) : ptr(p.ptr), ref(p.ref)
        {
            ref->inc();
        }

        /**
         * Assignment operator
         */
        SmartPtr<T>& operator= (const SmartPtr<T>& p)
        {
            if (this != &p){

                // delete the existing pointer if this is the last reference to them
                if (ref->dec() == 0){
                    cout << "delete ptr " << endl;
                    delete ptr;
                    delete ref;
                }

                // keep a reference to the pointer and increment the shared reference counter
                ptr = p.ptr;
                ref = p.ref;
                ref->inc();
            }
            return *this;
        }

        /**
         * Destructor
         * delete the 2 pointers if this is the last reference to them
         */
        ~SmartPtr()
        {
            if (ref->dec() == 0) {
                cout << "delete ptr " << endl;
                delete ptr;
                delete ref;
            }
        }
        
        /**
         * dereference
         */
        T& operator* ()
        {
            return *ptr;
        }

        T* operator-> ()
        {
            return ptr;
        }
};
