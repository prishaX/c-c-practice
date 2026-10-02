
  /*  We have a base class Animal with a protected member name.
    We then create an intermediate derived class Mammal that inherits from Animal and adds a protected member numLegs. This class represents a generic mammal.
    Finally, we create the Dog class, which inherits from Mammal. Dog is a specific type of mammal, so it inherits both the name and numLegs members and adds its own method, Bark.
    In the main function, we create an instance of the Dog class named myDog and call methods from all three levels of the inheritance hierarchy (Eat from Animal, Walk from Mammal, and Bark from Dog).   */

#include <iostream>
#include <string>
using namespace std;

class base{
    public: 
    base(){
        cout << "Constructing base\n";
    }
    void display(){
        cout<<"Base class A"<<endl;
    }
    ~base(){ 
        cout << "Destructing base\n"; 
    }
};

class derived: public base{
    public:
    void display2(){
        cout<<"subbase or derived class 1 b"<<endl;
    }
    derived(){
         cout << "Constructing derived1\n"; }
    ~derived()
        { cout << "Destructing derived1\n"; }

};

class derived2 : public derived{
    public: 
    void display3(){
        cout<<"derived class 2 or C"<<endl;
    }
    derived2()
        { cout << "Constructing derived2\n"; }
    ~derived2()
        { cout << "Destructing derived2\n"; }
};

class Animal{
    protected: 
    string name;
    public: 
    Animal(string n) : name(n){}
    void Eat() {
        cout << name << " is eating." << endl;
    }
};

class Mammal: public Animal{
    protected: 
    int numlegs;
    public: 
    Mammal(string n,int numlegs): Animal(n){
        this->numlegs=numlegs;
    }
    void Walk() {
        cout << name << " is walking on " << numlegs << " legs." << endl;
    }
};

class Dog: public Mammal{
    public:
    Dog(string n,int numlegs): Mammal(n,numlegs){}
    void Bark() {
        cout << name << " is barking." << endl;
    }
};

int main(){

    derived2 d;
    d.display();
    d.display2();
    d.display3();

    Dog dog1("Tuffy",4);
    dog1.Eat();
    dog1.Walk();
    dog1.Bark();

    return 0;
}