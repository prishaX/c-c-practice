#include <iostream>
#include <string>
using namespace std;

/*
topics to revise- (12:15 draft)
1. friend functions 
2. passing array in a function and returning array from a function
3. static ke weird questions from gallery 
4. sizeof codes and syntaxes like including padding nd shit 
5. passing objects in a function and returning objects from a function
*/

class Employee {
    string name;
    int id;
    static int count; 
  public:
    Employee(); // Default constructor
    Employee(string name,int id){ // Parameterized constructor
        this->name = name;
        this->id = id;
        count++;
    }
    Employee(Employee &e){ //copy constructor 
        this->name = e.name;
        this->id = e.id;
        count++;
    } 
    static void displaycount();
};

int Employee::count = 0; // Definition of static member
void Employee::displaycount(){
    cout<<count<<endl;
}

class ShoppingCart{
    int itemid[100];
    int itemprice[100];
    static int counter;
public:
    void initializecounter(){counter=0;};
    void setitem(){
        cout<<"Enter id of "<<counter+1<<" item"<<endl;
        cin>>itemid[counter];
        cout<<"Enter price of "<<counter+1<<" item"<<endl;
        cin>>itemprice[counter];
        counter++;
    }
    void getitem(){
        for(int i=0;i<counter;i++){
            cout<<"The id of "<<i+1<<" item is: "<<itemid[i]<<endl;
            cout<<"The price of "<<i+1<<" item is: "<<itemprice[i]<<endl;
        }
    }
};

int main() {
    ShoppingCart cart1; //this is the case for having many items in one object like a shopping cart
    cart1.initializecounter();
    cart1.setitem();
    cart1.setitem();
    cart1.getitem();

    Employee emps[100];    // and employee is the case of having many objects of the same class like many employees in a company
    for (int i=0; i<3; i++){
        string name;
        int id;
        cin>>name>>id;
        emps[i] = Employee(name, id); // Parameterized constructor is called
    }

    //and for dynamic memory allocation of objects we can just use pointers and "new" keyword like this 
    Employee *emp= new Employee[5]; //dynamic memory allocation of 5 objects of class employee
    for (int i=0; i<3; i++){
        string name;
        int id;
        cin>>name>>id;
        emp[i] = Employee(name, id); // Parameterized constructor is called
    }

    // similarly for shopping cart=
    ShoppingCart *cart2=new ShoppingCart;
    cart2->initializecounter();
    cart2->setitem();
    cart2->setitem();         //since pointer here we will use arrow operator to access the members of the class
    cart2->getitem();

//now for copy constructor we can just do this=
    Employee emp1("John", 101);
    Employee emp2(emp1); // Copy constructor is called


    return 0;
}