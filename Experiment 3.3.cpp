Experiment 3

#include <iostream>
#include <string>

class PoweredDevice {
protected:
    int powerRating;

public:
    PoweredDevice(int pr) : powerRating(pr) {}

    void displayPower() {
        std::cout << "Power Rating: " << powerRating << "W\n";
    }
};

class Scanner : virtual public PoweredDevice {
public:
    Scanner(int pr) : PoweredDevice(pr) {}

    void scan() {
        std::cout << "Scanning document...\n";
    }
};

class Printer : virtual public PoweredDevice {
public:
    Printer(int pr) : PoweredDevice(pr) {}

    void print() {
        std::cout << "Printing document...\n";
    }
};

class Copier : public Scanner, public Printer {
public:
    Copier(int pr) : PoweredDevice(pr), Scanner(pr), Printer(pr) {}
};

class ClassA {
public:
    void show() {
        std::cout << "Function from ClassA\n";
    }
};

class ClassB {
public:
    void show() {
        std::cout << "Function from ClassB\n";
    }
};

class ClassC : public ClassA, public ClassB {
};

int main() {
    std::cout << "--- Hybrid Inheritance with Virtual Inheritance ---\n";
    Copier myCopier(500);
    myCopier.scan();
    myCopier.print();
    myCopier.displayPower(); 
    std::cout << "\n";

    std::cout << "--- Resolving Ambiguity using Scope Resolution Operator ---\n";
    ClassC obj;
    obj.ClassA::show(); 
    obj.ClassB::show(); 

    return 0;
}
