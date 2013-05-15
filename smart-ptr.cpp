/**
 * a smart pointer template class
 */
#include "counter.cpp"
#include <iostream>
using namespace std;

template < typename T > class SmartPtr
{
    private:
        /**
         * the pointer being wrapped
         */
        T* ptr;

        Counter* reference;

    public:
        SmartPtr() : ptr(0), reference(0)
        {
            reference = new Counter;
            reference->inc();
        }

        SmartPtr(T* value) : ptr(value), reference(0)
        {
            reference = new Counter;
            reference->inc();
        }
        
        /**
         * Copy constructor
         */
        SmartPtr(const SmartPtr<T>& p) : ptr(p.ptr), reference(p.reference)
        {
            reference->inc();
        }

        /**
         * Assignment operator
         */
        SmartPtr<T>& operator= (const SmartPtr<T>& p)
        {
            if (this != &p){

                // delete existing pointers if this is the last reference to them
                if (reference->dec() == 0){
                    cout << "delete ptr " << endl;
                    delete ptr;
                    delete reference;
                }

                // copy the new pointers and increment ref count
                ptr = p.ptr;
                reference = p.reference;
                reference->inc();
            }
            return *this;
        }

        /**
         * Destructor
         * delete the 2 pointers if this is the last reference to them
         */
        ~SmartPtr()
        {
            if (reference->dec() == 0) {
                cout << "delete ptr " << endl;
                delete ptr;
                delete reference;
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
