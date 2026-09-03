#include <iostream>
#include <string>
using namespace std;

/* constructor is a special function whose work is to initialize, it (non parameterized) is automatically
 at object creation, so memory allocation happens only when constructor called. it also has no return type */

class test{
    int *ptr;
public: 
    test();
    test(int);
    void display();
};
test::test(){  //non parameterized constructor
    ptr=new int;
    *ptr=100;
}
test::test(int x){  //parameterized constructor
    ptr=new int;
    *ptr=x;
}
void test::display(){
    cout << "the value of ptr is: " << *ptr << endl;
}

class example{
    char *name;
    int length;
public:
    example(char *);
    void display();
    example();  
};

example::example(){  //non parameterized constructor
    length = 0;
    name = new char[length + 1];
}

example::example(char *n){  //parameterized constructor
    length=strlen(n);
    name=new char[length+1];
    strcpy(name,n);
}

void example::display(){
    cout << "the name is: " << name << endl;
}

class ABC{
    int a;
    public:
    ABC(int x){
        a=x;
    }
    void display(){
        cout << "the value of a is: " << a << endl;
    }
    ~ABC(){
        cout << "Hello i delete everything \n";
    }


};

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
};

//a class can also be made a friend of another class, so that it can access the private data of that class.
//all data members of the class are private by default, so if we want to access them from another class we can make that class a friend of this class

class twoValues{

    int a;
    int b;
public:
    twoValues(int i, int j){
        a=i;
        b=j;
    }
    friend class Min;
};
class Min{
    public:
    int min(twoValues x);

    int min(twoValues x){
    return (x.a<x.b)?x.a:x.b;
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

 Teacher t5;
 t5=t2;             //in copy constructor, conpy constructor is called but here assignment is used and on creation of t5 only default constructor is called
                    // and then assignment operator is used to copy the values of t2 to t5, so copy constructor is not called here.

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
 
test test1;  //non parameterized constructor called automatically
test1.display();
test test2(200);  //parameterized constructor called automatically
test2.display();

char *a="Welcome to"; 
example e1(a), e2("c++"), e3("world");  //parameterized constructor called automatically
e1.display();
e2.display();
e3.display();

ABC obj(10);  //parameterized constructor called automatically
obj.display();

twoValues obj1(10,20);
Min obj2;
cout << "the minimum value is: " << obj2.min(obj1) << endl;

return 0;
}