#include <iostream>
#include <string>
using namespace std;
/* constructors are called in order from left to right with multiple base class but destructors are called in reverse order from right to left with multiple base classes.
 friend functions, constructors, etc are not inherited by derived class, only member functions and member variables are inherited by derived class.
 pvt is not inherited but if in base class theres a public function which can access private function and it can be inherited in the derived class
 then we can access the private function of the base class through the public function of the base class in the derived class. */

 class member{
    char gender[10];
    int age;
    public:
    void get(){
        cout<<"enter age: "; cin>>age;
        cout<<"Gender: "; cin>>gender;
    }
    void disp(){
        cout << "Age: " << age << endl; 
        cout << "Gender: " << gender << endl; 
    }
 };
 
 class stud: public member{
    char level[20];
    public: 
    void getdata(){
        member::get();
        cout<<"enter class: ";
        cin>>level;
    }
    void disp2(){
        member::disp();
        cout<<"level: "<<level<<endl;
    }
 };

  class staff: public member{
    float salary;
    public:
    void getdata() { member::get();
        cout << "Salary: Rs.";
        cin >> salary; 
    }
    void disp3() { 
        member::disp();
        cout << "Salary: Rs." << salary << endl;
    } 
  };
 
class Animal {
protected:
    string name;

public:
    Animal(string _name) : name(_name) {}

    void Eat() {
        cout << name << " is eating." << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    Dog(string _name) : Animal(_name) {}

    void Bark() {
        cout << name << " is barking." << endl;
    }
};

// Derived class 2
class Cat : private Animal {
public:
    Cat(string _name) : Animal(_name) {}

    void Meow() {
        cout << name << " is meowing." << endl;
    }
};


int main(){
    
    staff S;
    stud s;
    s.getdata();
    S.getdata();
    s.disp2();
    S.disp3();

    Cat cat("Whiskers");
    //cat.eat();   // Not accessible due to private inheritance
    cat.Meow();  // Specific to Cat class
    Dog dog("tuffy");
    dog.Bark();
    dog.Eat(); //can access as it was inherited publically

    return 0;
}

    
    