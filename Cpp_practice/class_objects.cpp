#include <iostream>
#include <string>
using namespace std;

//difference between struct and class in cpp is that in class everything is private by default and
// in structure everything is public by default

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
//function helps set salary so setter function
void setsalary (int s){
    salary=s;
}
double getsalary(){ //getter function
    return salary;
}
};

int m = 20;

//encapsulation is basically wrapping up of data and member functions in a single unit called class restricting direct access to data to users,
// functions and all protect the inputs and objects 

class Account {
    //data hiding, using encapsulation
    private:
    double balance;
    string password;

    public:
    string accountId;
    string username;

};

/*Namespaces- used to avoid naming conflicts, usually a container which differentiates between similar name identifiers(variables functions classes etc )*/

namespace ns1{
    void print(){
        cout << "This is from ns1.\n";
    }
}


namespace ns2{
    void print(){
        cout << "This is from ns2.\n";
    }
}

class Shopping {
    int itemid[100];
    int itemprice[100];
    int counter;
public: 
    void initcounter(){counter=0;};
    void setprice();
    void displayprice();
    void totalprice();
};

void Shopping ::setprice(){
    cout<<"Enter id of your " << counter + 1 << " item" <<endl;
    cin>>itemid[counter];
    cout<<"Enter price of your " << counter + 1 << " item"<<endl;
    cin>>itemprice[counter];
    counter++;
}

void Shopping ::displayprice(){  //scope resolution operator for functions is called like this
     for(int i = 0; i < counter; i++){
    cout<<"The price of" << i + 1 << "item is "<< itemprice[i] <<endl;
    }
}

void Shopping ::totalprice(){
    int sum=0;
    for (int i=0; i<counter; i++){
        sum=sum+itemprice[i];
    }
    cout<<"The total sum of the items is: "<<sum<<endl;
}

class Employee{
    int id;
    static int count;
public:
    void setdata(){
        cin>>id;
        count++;
    }
    void getdata(){
        cout<<"The id of the "<<count<<" employee is: "<<id<<endl;
    }
};

int Employee :: count; //default value of static members is zero. so as count is static its count is zero


/*Inside the class:
✅ Public function → Private function
✅ Public function → Private data
✅ Private function → Private data
✅ Private function → Public function (also allowed) */

class Student{
    int marks;
    int roll;
public:
    Student(){
        marks=0;
        roll=0;
    }
    Student(int m, int r){
        marks=m;
        roll=r;
    }
    void show(){
        cout<<"The marks are: "<<marks<<endl;
        cout<<"The roll number is: "<<roll<<endl;
    }
};

int main (){

 Student *s = new Student[2]{{3,5},{7,8}}; //dynamic memory allocation of object s1 of class student
 delete [] s; //deleting the dynamically allocated memory for object s1
 
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

 Teacher *t = new Teacher[2]; //dynamic memory allocation of object t2 of class teacher
 t[0].name="prisha";
 t[0].dept="cs";
 t[1].name="rohan";
 t[1].dept="it";
 cout<<t[0].name<<endl;
 cout<<t[1].name<<endl;

delete [] t; //deleting the dynamically allocated memory for object t

ns1::print();  //calling of the same print function in different namespace
ns2::print();

Shopping s1;
s1.initcounter();
s1.setprice();
s1.setprice();
s1.displayprice();
s1.totalprice();

/* char str[20];
cin.getline(str, sizeof(str)); cin.getline(array_name, size); is the syntax to print a sentene or print strings with spaces.
cout << str << endl; //sizeof(str) returns the actual size of the input as capacity is 20 and size depends on input */

Employee harry,rohan,ritik;
harry.setdata();
harry.getdata(); 
rohan.setdata();
rohan.getdata();    
ritik.setdata();
ritik.getdata();
                    //static is used here bcs if we dont use static the counter always starts from the initial value each time
                    // a new object is created and function is called. static ensures the counter remains one throighout the members of the employee class

int A[2]; //static memory allocation is done at compile time and dynamic memory allocation is done at run time
int B[2]={1,2}; //static memory allocation and initlization is done at compile time
int  *ptr=new int[2](); //dynamic memory allocation is done at run time
int *ptr1=new int[2]{1,2}; //dynamic memory allocation and initialization is done at run time
int *ptr1=new int[2]{1}; //rest elements will be initialized to zero, so ptr1[0]=1, ptr1[1]=0
int n;
cin>>n;
int *newptr=new int[n]; //dynamic memory allocation of n size array at run time 

 return 0;
}
