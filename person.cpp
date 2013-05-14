#include <iostream>
using namespace std;

class Person
{
    protected:

    int age;
    char *name;

    public:
        Person(): name(0), age(0)
        {
        }

        Person(char* name, int age): name(name), age(age)
        {
        }

        ~Person()
        {
        }

        void Display()
        {
            cout << "Name = " << name << " Age = " << age << endl;
        }
};
