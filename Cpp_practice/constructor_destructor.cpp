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

/* an object can have as many constructors as possible but with different arguments, whenever a constructor or object is invoked in the main function
the constructor with matching arguments is called. i.e this is called constructor overloading */

//destructor 
~Teacher(){
cout << "Hello i delete everything \n";
} 
//at the end of the main function our compiler notes that the t1 etc are no longer necessary so its automatically called and it deallocates its memory
//to free 

};

class Employee{
    int id;
    int salary;
public:
    void setid(){
        cout<<"enter id of the employee"<<endl;
        cin>>id;
    }
    void getid(){
        cout<<"The id of the employee is: "<<id<<endl;
    }
}; 

class Complex{
    int a;
    int b;
public:
    void number(int v1 , int v2){
    a=v1;
    b=v2;
    }
    friend Complex sumofcomplex(Complex n1, Complex n2);      //sends declaration to compilor that the function can access class private data. 
    friend Complex addref(Complex &n1, Complex &n2);
    void printnumber(){
        cout<<"the complex number is: "<<a<<" + "<<b<<"i"<<endl;
    }
};

    //function whose return type is complex and arguments are also complex
    // These are friend functions. 
    // function cant access private data of the class so it needs a declaration from class to tell compilor to access data
    // this doesnt make the function a member function of the class. i.e not in scope.
    // so cant be called from objects of that class, i.e num1.sumofcomplex()==invalid
    // can be declared in public or private part of the class

Complex sumofcomplex(Complex n1, Complex n2){          //function who returns an object and takes objects as arguments 
    Complex o3;    //creating another object 
    o3.number((n1.a+n2.a),(n1.b+n2.b));             
      return o3;                                     
}   

Complex addref(Complex &n1,Complex &n2){
    Complex o3;
    o3.number((n1.a+n2.a),(n2.b+n2.b));
    return o3;
}
class Bank{
    int principal;
    int years;
    float interestRate;
    float returnvalue;
public:
    Bankdeposit(){}
    Bankdeposit(int p, int y, float r){//r can be a float value like 0.04
    principal=p;
    years=y;
    interestRate=r;
    returnvalue=principal;
    for (int i=0;i<y;i++){
        returnvalue=returnvalue*(1+r);
    }
    Bankdeposit(int p, i nt y, int r); //r can be an integer value
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
 cout << t1.subject << endl;
 cout << t1.getsalary() << endl;

 Teacher t2("stuti", "doctory", "gynac", 150000);  //parameterized function implicit call
 cout << t2.name << endl;
 cout << t2.dept << endl;
 cout << t2.subject << endl;
 cout << t2.getsalary() << endl;
 
 Teacher t4 = Teacher("prisha", "coe", "engineering", 5000000); //explicit call of parameterized function
 cout << t4.name << endl;
 cout << t4.dept << endl;                          
 cout << t4.subject << endl;
 cout << t4.getsalary() << endl;

 Teacher t3(t2);
 cout << t3.name << endl;
 cout << t3.dept << endl;
 cout << t3.subject << endl;
 cout << t3.getsalary() << endl;

Employee mars[10];       //array of objects created..especially used when there are alot of employees for one company etc type things
for (int i=0;i<10;i++){
    mars[i].setid();
}
for (int i=0;i<10;i++){
    mars[i].getid();
}

Complex num1;
Complex num2;
Complex sum;
Complex sumref;

num1.number(1,4);
num1.printnumber();
num2.number(5,8);
num2.printnumber();
sum = sumofcomplex(num1,num2);  //called like this as we need to store the returned value in sum object, as the function returns an object
sum.printnumber();              //this is passby value sum
sumref=addref(num1,num2);       //this is pass by reference sum
sumref.printnumber();            
 
return 0;
}