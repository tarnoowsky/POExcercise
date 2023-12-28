#include <iostream>
#include <string>

using std::string; 

class Employee {
public:
    string name;
    string position;
    int age;

    Employee(string n, string p, int a) : name(n), position(p), age(a) {}

    friend std::ostream& operator<<(std::ostream& out, const Employee& emp) {
        out << "Name: " << emp.name << ", Position: " << emp.position << ", Age: " << emp.age;
        return out;
    }
};