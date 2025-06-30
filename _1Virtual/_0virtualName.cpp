//Code without using the virtual
// If you do NOT use virtual, then calling a method through a parent class pointer/reference will always invoke the parent’s method, no matter what the actual object is.
#include<iostream>
using namespace std;
class Parent {
public:
    void show() 
    {  // Not virtual
        cout << "Parent show" << endl;
    }
};
class Child : public Parent {
public:
    void show() 
    {
        cout << "Child show" << endl;
    }
};
int main()
{
Parent* p = new Child();
p->show();  // Output: Parent show (calls parent version)
}

//Code with using the virtual
//If you DO use virtual in the parent class method, then calling it through a parent pointer/reference will invoke the child’s overridden method if the object is actually of the child class.

// #include<iostream>
// using namespace std;
// class Parent 
// {
// public:
//     virtual void show() 
//     {  // Virtual function
//         cout << "Parent show" << endl;
//     }
// };
// class Child : public Parent 
// {
// public:
//     void show() override 
//     {
//         cout << "Child show" << endl;
//     }
// };
// int main()
// {
// Parent* p = new Child();
// p->show();  // Output: Child show (calls child version)
// }
