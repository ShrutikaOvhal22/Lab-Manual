
#include <iostream>
#include <string>
using namespace std;

// Multiple Inheritance
class PersonalDetails {
public:
    string name;
    int age;

    void getPersonalDetails() {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayPersonalDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class SalaryDetails {
public:
    float salary;

    void getSalaryDetails() {
        cout << "Enter salary: ";
        cin >> salary;
    }

    void displaySalaryDetails() {
        cout << "Salary: " << salary << endl;
    }
};

class Employee : public PersonalDetails, public SalaryDetails {
public:
    void displayEmployee() {
        displayPersonalDetails();
        displaySalaryDetails();
    }
};

// Hierarchical Inheritance
class Shape {
public:
    void displayShape() {
        cout << "This is a shape." << endl;
    }
};

class Circle : public Shape {
public:
    float radius;

    void getRadius() {
        cout << "Enter circle radius: ";
        cin >> radius;
    }

    void area() {
        cout << "Area of Circle: "
             << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape {
public:
    float length, breadth;

    void getDimensions() {
        cout << "Enter length and breadth: ";
        cin >> length >> breadth;
    }

    void area() {
        cout << "Area of Rectangle: "
             << length * breadth << endl;
    }
};

int main() {
    cout << "=== Multiple Inheritance ===" << endl;

    Employee e;
    e.getPersonalDetails();
    e.getSalaryDetails();

    cout << "\nEmployee Details:" << endl;
    e.displayEmployee();

    cout << "\n=== Hierarchical Inheritance ===" << endl;

    Circle c;
    c.displayShape();
    c.getRadius();
    c.area();

    Rectangle r;
    r.displayShape();
    r.getDimensions();
    r.area();

    return 0;
}
