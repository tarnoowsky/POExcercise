#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    string position;
    int age;

    Employee(string n, string p, int a) : name(n), position(p), age(a) {}

    friend ostream &operator<<(ostream &out, const Employee &emp)
    {
        out << "Name: " << emp.name << ", Position: " << emp.position << ", Age: " << emp.age;
        return out;
    }
};
