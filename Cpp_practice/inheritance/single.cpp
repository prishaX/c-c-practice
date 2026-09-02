#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;

    Animal(string name){
        this->name = name;
    }

    void Eat() {
        cout << name << " is eating." << endl;
    }
    void sleep() {
        cout << name << " is sleeping." << endl;
    }
};

// Derived class (observe the syntax)
class Dog : public Animal {
public:
    // calling constructor of Animal with name as parameter
    Dog(string name) : Animal(name) {}

    void Bark() {
        cout << "Woof! Woof!" << endl;
    }
};

int main(){

    Dog dog("Buddy");
    dog.Eat();   // Inherited from Animal class
    dog.sleep(); // Inherited from Animal class
    dog.Bark();  // Specific to Dog class

    return 0;
}