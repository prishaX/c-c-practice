#include <iostream>
#include <string>
using namespace std;

/* constructor is a special function whose work is to initialize, it (non parameterized) is automatically
 at object creation, so memory allocation happens only when constructor called. it also has no return type */


class Teacher{
    // property attributes or member parameters
private: 
    double salary;

public:
    string name;
    string dept;
    string subject;

//non parameterized constructor 
Teacher (){
    cout << "Hello im constructor ";  
    dept = "cs"; //this line automatically sets dept cs for all the objects that will be created so we can remove dept from main
}

//member functions
void changedept(string newdept){
    dept=newdept;
}
//function ke through salary public kr skte
void setsalary (int s){
    salary=s;
}
double getsalary(){
    return salary;
}

};

int main (){
    //dot function ke through u can assign values to your object
 Teacher t1; //constructor is called automatically
 t1.name="prisha";
 t1.subject="cpp";
 t1.setsalary(25000); //i set salary from this function calling here, i cant use t1.salary as salary is private
 cout << t1.name << endl;
 cout << t1.dept << endl;
 cout << t1.getsalary() << endl;

return 0;
}