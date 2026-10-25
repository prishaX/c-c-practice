#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal constructor" << endl;
    }

    virtual void sound() = 0;

    virtual ~Animal() {
        cout << "Animal destructor" << endl; 
    }
};

// Making sound() virtual does not automatically make the destructor virtual. 
// Every member function has its own declaration, so you must explicitly write virtual for the base destructor when polymorphic deletion is intended.
// making the destructor virtual gives output - Animal constructor Dog constructor Woof Dog destructor Animal destructor
// virtual allows the correct overridden function to be selected at runtime. = 0 makes the function pure virtual, which makes the class abstract and requires concrete derived classes to implement it. 

// for abstract class like animal...u cant create an object normally as it has no definition of its virtual funciton.  Classes inheriting an Abstract Class must implement all pure virtual functions, or else they will become Abstract too.
// we can also give a small definition (outside the class) when creating the pure virtual function which we want all the inherited classes to have. 
//like example - void Animal::sound() { cout << "Generic animal sound" << endl;} so the derived classes will also add a line in their sound function  Animal::sound();  // to call the parent's implementation

// A virtual function (also known as virtual methods) is a member function that is declared within a base class and is re-defined (overridden) by a derived class. 

// When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the method.

// The resolving of a function call is done at runtime

// They are always defined in the base class and overridden in a derived class. 

// When a virtual function is inherited, its virtual nature is also inherited. This means that when a derived class that has inherited a virtual function is itself used as a base class for
// another derived class, the virtual function can still be overridden. like in multi level a is base b is inherited from a and c is inherited from b..if a func is virtual in a so its virtual for c asw as b

class Dog : public Animal {
public:
    Dog() {
        cout << "Dog constructor" << endl;
    }

    void sound() override {
        cout << "Woof" << endl;
    }

    ~Dog() {
        cout << "Dog destructor" << endl;
    }
};

int main() {
    Animal* obj = new Dog;

    obj->sound();

    delete obj;

    return 0;
}