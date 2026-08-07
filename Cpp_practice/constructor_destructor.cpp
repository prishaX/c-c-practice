#include <iostream>
#include <string>
using namespace std;

/* constructor is a special function whose work is to initialize, it (non parameterized) is automatically
 at object creation, so memory allocation happens only when constructor called. it also has no return type */


class Teacher{
    // property attributes or member parameters or data members
private: 
    double salary;

public:
    string name;
    string dept;
    string subject;

//non parameterized constructor 
Teacher (){
    cout << "Hello im non parameterized constructor\n";  
    dept = "cs"; //this line automatically sets dept cs for all the objects that will be created so we can remove dept from main
}

//parameterized constructor 
Teacher (string name, string dept, string subject, double salary) {
    cout << "Hello im parameterized  constructor \n";
    this->name=name; //this pointer points to the variable of the class when the variable name of the function and class are same
    this->dept=dept; 
    this->subject=subject;
    this->salary=salary;
}

//copy constructor
Teacher(Teacher &orgObj){   //here object is passed by reference, so the changes made in this constructor will also change the original object
    cout << "Hello im copy constructor \n";
    this->name=orgObj.name; 
    this->dept=orgObj.dept;
    this->subject=orgObj.subject;
    this->salary=orgObj.salary;
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

//destructor 
~Teacher(){
cout << "Hello i delete everything \n";
} 
//at the end of the main function our compiler notes that the t1 etc are no longer necessary so its automatically called and it deallocates its memory
//to free 

};

int main (){
    //dot function ke through u can assign values to your object
 Teacher t1; //constructor is called automatically
 t1.name="prisha";
 t1.subject="cpp";
 t1.setsalary(25000); //i set salary from this function calling here, i cant use t1.salary as salary is private
 cout << t1.name << endl;
 cout << t1.dept << endl;
 cout << t1.subject << endl;
 cout << t1.getsalary() << endl;

 Teacher t2("stuti", "doctory", "gynac", 150000);
 cout << t2.name << endl;
 cout << t2.dept << endl;
 cout << t2.subject << endl;
 cout << t2.getsalary() << endl;

 Teacher t3(t2);
 cout << t3.name << endl;
 cout << t3.dept << endl;
 cout << t3.subject << endl;
 cout << t3.getsalary() << endl;

return 0;
}