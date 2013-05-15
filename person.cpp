#include "person.h"

Person::Person(): name(0), age(0){}

Person::Person(const string& name, int age): name(name), age(age){}

Person::~Person(){}

void Person::Display() const
{
    cout << "Name = " << name << " Age = " << age << endl;
}
