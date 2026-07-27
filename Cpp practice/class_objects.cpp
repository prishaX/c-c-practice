#include <iostream>
#include <string>
using namespace std;

//difference between struct and class in cpp is that in class everything is private by default and
// instructure everything is public by default

/* since all objects of a class have same member functions, so no different space allocated for them
only space for member variables is allocated seperately  for each object*/

class Teacher{
    // property attributes or member parameters
private: 
    double salary;
public:
    string name;
    string dept;
    string subject;
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

int m = 20;

//encapsulation is basically wrapping up of data and member functions in a single unit called class

class Account {
    //data hiding, using encapsulation
    private:
    double balance;
    string password;

    public:
    string accountId;
    string username;

};

int main (){
 int m = 10;
    //dot function ke through u can assign values to your object
 Teacher t1;
 t1.name="prisha";
 t1.dept="cs";
 t1.subject="cpp";
 t1.setsalary(25000); //i set salary from this function calling here, i cant use t1.salary as salary is private
 cout << t1.name << endl;
 cout << t1.getsalary() << endl;

 cout << "Local = " << m << endl;
 cout << "Global = " << ::m << endl; 
 /* "::" is a scope resolution operator 
 it means look or link in another scope, it links a class name with a member name
 like if any function or if any data type, if its in another class or in another scope so we can link it using this  */ 

 return 0;
}