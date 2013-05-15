#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:

    int age;
    const string& name;

    public:
        Person(): name(0), age(0)
        {
        }

        Person(const string& name, int age): name(name), age(age)
        {
        }

        ~Person()
        {
        }

        void Display() const
        {
            cout << "Name = " << name << " Age = " << age << endl;
        }
};
