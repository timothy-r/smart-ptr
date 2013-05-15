#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:

    int age;
    const string& name;

    public:
        Person();

        Person(const string& name, int age);

        ~Person();

        void Display()const;
};
