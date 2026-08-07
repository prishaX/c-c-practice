#include <iostream>
#include <string>
using namespace std;

//question4,question5
 class Student{
 //data members
  string name;
  int roll;
  string degree;
  char hostel;
  float cg;
 public:
 //member functions
  void addDetails(string n,int r, string d){           
   name=n;
   roll=r;
   degree=d;
  }
  void updateDetails(string n,int r, string d){
   name=n;
   roll=r;
   degree=d;
  }
  void updateCGPA(float c){
   cg=c;
  }
  void updateHostel(char h){
   hostel=h;
  }
  void displayDetails(){
   cout<<"Name: "<<name<<endl;
   cout<<"Roll Number: "<<roll<<endl;
   cout<<"Degree: "<<degree<<endl;
   cout<<"CGPA: "<<cg<<endl;
   cout<<"Hostel: "<<hostel<<endl;
  }
    };
    
//practice
/* class Shopping{
  int itemid[100];
  int itemprice[100];
  int counter;
 public:
  void initialize(){counter=0;}
  void setDetails(){
   cout<<"Enter id of "<<counter+1<<" item"<<endl;
   cin>>itemid[counter];
   cout<<"Enter price of "<<counter+1<<"item"<<endl;
   cin>>itemprice[counter];
   counter++;
  }
  void displayDetails(){
   for (int g=0;g<counter;g++)
   cout<<"Price of item with id "<<itemid[g]<<" is"<<itemprice[g]<<endl;
  }
 };  */
 
//question 6
 class print{
  int j;
  int l;
  void priv(){
   j=30;
  }
  void setval(int k){
   l=k;
  }
 public: 
  void printing(){
   priv();              //calling of private function in public function
   cout<<j<<endl;
  }
  void passval(){
   setval(j);          //accessed private function in public function 
   cout<<"set val: "<<l<<endl; 
  }
 };

//question 8
namespace ns1{
    void print(){
        cout<<"This print function is from ns1"<<endl;
    }
}
namespace ns2{
    void print(){
        cout<<"This print function is from ns2"<<endl;
    }
}

//question 7
class Complex{
    int a;
    int b;
public:
    void number(int v1 , int v2){
    a=v1;
    b=v2;
    cout<<"the complex number is: "<<a<<" + "<<b<<"i"<<endl;
    }
    void sumofcomplex(Complex n1, Complex n2){
        a=n1.a+n2.a;
        b=n1.b+n2.b;
        cout<<"the sum of both complex is: "<<a<<" + "<<b<<"i"<<endl;
    }

};

int main(){

//question1
 cout<<"Hello, World!\n";
 cout<<"Hello, World!"<<endl;

 
//question2
 float temp;
 cout<<" enter temperature in celsius: ";
 cin>>temp;
 float f;
 f=(9 *temp/5)+32;
 cout<<"temperature in degrees fahrenheit is:"<<f<<endl;
 
//question3
 for (int a=0;a<=10;a++){
  cout<<a<<" ";
 }
 cout<<endl;
 int b=0;
 for (;b<=10;b++){
  cout<<b<<" ";
 }
 cout<<endl;
 int c=0;
 for (;c<=10;){
  cout<<c<<" ";
  c++;
 }
 cout<<endl;
 int d=0;
 while(d<=10){
  cout<<d<<" ";
  d++;
 }
 cout<<endl;
 int e;
 do{
  cout<<e<<" ";
  e++;
 }while(e<=10);
 cout<<endl;
 
//question 4,question5
 Student s1;
 s1.addDetails("Prisha",10,"btech");
 s1.updateCGPA(9.67);
 s1.updateHostel('G');
 s1.displayDetails();

//practice
/* Shopping shop;
 shop.initialize();
 shop.setDetails();
 shop.setDetails();
 shop.setDetails();
 shop.displayDetails(); */
 
 //question 6
 print P;
 P.printing();
 P.passval();

//question8
ns1::print();
ns2::print();

//question 7 
Complex num1;
Complex num2;
Complex sum;

num1.number(1,2);
num2.number(3,4);
sum.sumofcomplex(num1,num2);
 return 0;
}