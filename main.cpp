#include "smart-ptr.cpp"
#include "person.cpp"

int main()
{
    SmartPtr<Person> p(new Person("Tim", 47));
    p->Display();
    {
        SmartPtr<Person> q = p;
        q->Display();
    }
    // ERROR Person has been deleted
    //p->Display();
    return 0;
}


