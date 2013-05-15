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

    {
        SmartPtr<Person> q = p;
        showPerson(*q);
    }

    SmartPtr<Person> r(new Person("Rodger", 7));
    showPerson(*r);

    r = p;
    showPerson(*r);

    return 0;
}

