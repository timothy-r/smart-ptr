/**
 * a smart pointer template class
 */
template < typename T > class SmartPtr
{

    private:
        /**
         * the pointer being wrapped
         */
        T* ptr;

    public:
        SmartPtr(T* value) : ptr(value)
        {
        }

        ~SmartPtr()
        {
            delete ptr;
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
