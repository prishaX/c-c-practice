
  /*  We have a base class Animal with a protected member name.
    We then create an intermediate derived class Mammal that inherits from Animal and adds a protected member numLegs. This class represents a generic mammal.
    Finally, we create the Dog class, which inherits from Mammal. Dog is a specific type of mammal, so it inherits both the name and numLegs members and adds its own method, Bark.
    In the main function, we create an instance of the Dog class named myDog and call methods from all three levels of the inheritance hierarchy (Eat from Animal, Walk from Mammal, and Bark from Dog).   */

#include <iostream>
#include <string>
using namespace std;

//Parent class
class Animal {
protected:
    string name;
public:
    Animal(string _name) : name(_name) {}
};

//Intermediate derived class
class Mammal : public Animal {
    protected:
    int numlegs;
public:
    Mammal(string _name, int _numlegs) : Animal(_name){
        numlegs = _numlegs;
    }
};

//Derived class
class Dog : public Mammal {
    public:
    Dog(string _name, int _numlegs) : Mammal(_name, _numlegs) {}
    void Bark() {
        cout << "Woof! Woof!" << endl;
    }   
};

int main(){
    Dog mydog("Buddy", 4);
    mydog.Bark();   // Inherited from Dog class 
    return 0;
}