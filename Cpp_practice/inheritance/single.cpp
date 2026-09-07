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

class Parent {
    protected:
    int a;
    public:
    Parent(){cout<<"Parent constructor called"<<endl;}
    void show(){
        cout<<"Parent a: "<<a<<endl;
    }
    ~Parent(){cout<<"Parent destructor called"<<endl;}
};

class Child: public Parent {
    public:
    Child(){cout<<"Child constructor called"<<endl;}
    void print(){
        show(); //accessing the public member function of parent class
        cout<<"Parent through child: "<<a<<endl;
    }

    ~Child(){cout<<"Child destructor called"<<endl;}
};
//first constructor of parent is called nd then child constructor 
// destructor of child is called first nd then destructor of parent is called

int main(){

    Dog dog("Buddy");
    dog.Eat();   // Inherited from Animal class
    dog.sleep(); // Inherited from Animal class
    dog.Bark();  // Specific to Dog class
    Parent p;
    Child c;

    return 0;
}