
#include <iostream>
#include <string>
using namespace std;

class StaticExample {
    static int count;

public:
    StaticExample() {
        count++;
    }

    static void showCount() {
        cout << "Total objects created: " << count << endl;
    }
};

int StaticExample::count = 0;

class ClassB;

class ClassA {
    int value;

public:
    ClassA(int v) {
        value = v;
    }

    friend void compareValues(ClassA, ClassB);
};

class ClassB {
    int value;

public:
    ClassB(int v) {
        value = v;
    }

    friend void compareValues(ClassA, ClassB);
};

void compareValues(ClassA a, ClassB b) {
    cout << "Value in ClassA: " << a.value << endl;
    cout << "Value in ClassB: " << b.value << endl;

    if (a.value > b.value)
        cout << "ClassA value is greater" << endl;
    else if (b.value > a.value)
        cout << "ClassB value is greater" << endl;
    else
        cout << "Both values are equal" << endl;
}

class SecretData {
    string password;
    int secretNumber;

public:
    SecretData(string p, int n) {
        password = p;
        secretNumber = n;
    }

    friend class FriendClassExample;
};

class FriendClassExample {
public:
    void displaySecret(SecretData s) {
        cout << "Password: " << s.password << endl;
        cout << "Secret Number: " << s.secretNumber << endl;
    }
};

int main() {
    cout << "=== Static Members ===" << endl;

    StaticExample s1, s2, s3;
    StaticExample::showCount();

    cout << "\n=== Friend Function ===" << endl;

    ClassA a(50);
    ClassB b(30);
    compareValues(a, b);

    cout << "\n=== Friend Class ===" << endl;

    SecretData secret("myPassword123", 999);
    FriendClassExample friendObj;
    friendObj.displaySecret(secret);

    return 0;
}
