#include <iostream>
#include <string>
using namespace std;

//base class
class Employee{
    int id;
    float salary;
public:
    Employee(int inpID){
        id=inpID;
        salary=34.2;
    }
    void getsalary(){
        cout<<salary<<"  "<<id<<endl;
    }
    Employee
};

//derived class
/*class {{derived-class_name}} : {{visibility mode}} {{base-class_name}}{
class members/methods etc are written here
}
visibility mode = it means the way we want to inherit our class, if we inherit publically, our base class public members become public, and if we inherit privately,
our base class's public members become our derived class's private members, i.e private members of the base class are NEVER inheritted
##### by default our visibility mode is private.*/

class Programmer : Employee{    //programmer is the derived class employee is the base class
    public:
    int language_code = 9;
public:
    Programmer(int inpid){
         id=inpid;
    }
};


int main(){

/* INHERITANCE- 
  there are different types of inheritance-
  1. single inheritance- a derived class with only 1 base class
  2. multiple inheritance - a derived class with more than one base class 
  3. hierarchical inheritance- several derived classes from a single base class 
  4. multi level inheritance- deriving a class from already a derived class
  5. hybrid inheritance- combination of multiple and multi level inheritance */

Employee harry(10293), rohan(93291);
harry.getsalary();
rohan.getsalary();

Programmer skillf(1);

    return 0;
}