#include <iostream>
#include <string>
using namespace std;

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
    //dot function ke through u can assign values to your object
 Teacher t1;
 t1.name="prisha";
 t1.dept="cs";
 t1.subject="cpp";
 t1.setsalary(25000); //i set salary from this function calling here, i cant use t1.salary as salary is private
 cout << t1.name << endl;
 cout << t1.getsalary() << endl;
   
 return 0;
}