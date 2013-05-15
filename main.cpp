#include "smart-ptr.cpp"
#include "person.cpp"

void showPerson(const Person &p)
{
    p.Display();
}

int main()
{
    SmartPtr<Person> p(new Person("Tim", 47));
    showPerson(*p);

    //p->Display();
    {
        SmartPtr<Person> q = p;
        showPerson(*q);
        //q->Display();
    }

    SmartPtr<Person> r(new Person("Rodger", 7));
    //r->Display();
    showPerson(*r);

    r = p;
    showPerson(*r);
    //r->Display();

    return 0;
}

