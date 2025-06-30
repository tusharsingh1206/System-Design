// Pure virtual function:
// Has no implementation in the parent class (declared with = 0).
// Derived classes must override it, or they’ll also be abstract.
//Must define the methods


#include <iostream>
using namespace std;

class Base {
public:
    virtual void greet() {
        cout << "Hello from Base" << endl;
    }
};

class Derived : public Base {
    // No override here
};

int main() {
    Derived d;
    d.greet();  // Output: Hello from Base
    return 0;
}

//Pure virtual function:
// Has no implementation in the parent class (declared with = 0).
// Derived classes must override it, or they’ll also be abstract.

#include <iostream>
using namespace std;

class Base {
public:
    virtual void greet() = 0;  // Pure virtual function — no implementation
};

class Derived : public Base {
public:
    void greet() override {
        cout << "Hello from Derived" << endl;
    }
};

int main() {
    // Base b;  // ❌ Error: Cannot instantiate abstract class
    Derived d;
    d.greet();  // Output: Hello from Derived
    return 0;
}
