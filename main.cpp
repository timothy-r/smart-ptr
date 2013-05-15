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

    SmartPtr<Person> r(new Person("Rodger", 7));
    r->Display();

    r = p;
    r->Display();

    return 0;
}


