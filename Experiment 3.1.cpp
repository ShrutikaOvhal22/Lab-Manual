
#include <iostream>
using namespace std;

// Single Inheritance
class Person {
public:
    string name;
    int age;

    void getPersonDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int rollNo;

    void getStudentDetails() {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudentDetails() {
        displayPersonDetails();
        cout << "Roll Number: " << rollNo << endl;
    }
};

// Multilevel Inheritance
class Vehicle {
public:
    string brand;

    void getVehicleDetails() {
        cout << "Enter vehicle brand: ";
        cin >> brand;
    }

    void displayVehicleDetails() {
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
public:
    string model;

    void getCarDetails() {
        cout << "Enter car model: ";
        cin >> model;
    }

    void displayCarDetails() {
        displayVehicleDetails();
        cout << "Model: " << model << endl;
    }
};

class ElectricCar : public Car {
public:
    int batteryCapacity;

    void getElectricCarDetails() {
        cout << "Enter battery capacity (kWh): ";
        cin >> batteryCapacity;
    }

    void displayElectricCarDetails() {
        displayCarDetails();
        cout << "Battery Capacity: "
             << batteryCapacity << " kWh" << endl;
    }
};

int main() {
    cout << "=== Single Inheritance ===" << endl;

    Student s;
    s.getPersonDetails();
    s.getStudentDetails();

    cout << "\nStudent Details:" << endl;
    s.displayStudentDetails();

    cout << "\n=== Multilevel Inheritance ===" << endl;

    ElectricCar e;
    e.getVehicleDetails();
    e.getCarDetails();
    e.getElectricCarDetails();

    cout << "\nElectric Car Details:" << endl;
    e.displayElectricCarDetails();

    return 0;
}
