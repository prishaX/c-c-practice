#include <iostream>
#include <string>
using namespace std;

/* 
    We have a base class Animal with two methods, Eat and Sleep, and a protected member name.
    We then create derived classes Dog which inherit from the Animal class.
    These derived classes add their own specific behaviors (Bark for Dog and Meow for Cat).
    Since the visibility mode is public the public method (eat) of the animal can be used from derived class.
    We then create derived classes Cat which inherit from the Animal class.
    Since the visibility mode is private the public method (eat) of the animal can not be used from derived class.
    In the main() function, we create instances of both Dog and Cat, and we call methods from both the base class and the derived classes for each object.
*/



//constructors are called in order from left to right with multiple base class but destructors are called in reverse order from right to left with multiple base classes.
//friend functions, constructors, etc are not inherited by derived class, only member functions and member variables are inherited by derived class.

//Parent class
class Animal{
    protected:
    string name;
    public: 
    Animal(string _name) : name(_name) {}
    void eat(){
        cout<<name<<" is eating"<<endl;
    }
    void sleep(){
        cout<<name<<" is sleeping"<<endl;
    }
};

//Derived class 1
class Dog: public Animal{
   public:
    Dog(string _name) : Animal(_name) {}
    void Bark(){
       cout<<name<<" is barking"<<endl;
    }
};

//Derived class 2
class Cat: private Animal{
    public:
    Cat(string _name) : Animal(_name) {}
    void Meow(){
        cout<<name<<" is meowing"<<endl;
    }
};

// pvt is not inherited but if in base class theres a public function which can access private function and it can be inherited in the derived class
// then we can access the private function of the base class through the public function of the base class in the derived class.
int main(){

    Dog dog("Buddy");
    dog.eat();   // Inherited from Animal class
    dog.sleep(); // Inherited from Animal class
    dog.Bark();  // Specific to Dog class

    Cat cat("Whiskers");
    //cat.eat();   // Not accessible due to private inheritance
    //cat.sleep(); // Not accessible due to private inheritance
    cat.Meow();  // Specific to Cat class
    
    return 0;
}