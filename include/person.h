#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:

        const string name;
        int age;

    public:
        Person();

        Person(const string& name, int age);

        ~Person();

        void Display()const;
};
