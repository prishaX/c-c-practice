#include <iostream>
#include <string>
using namespace std;

class base1{
    protected:
    int x;
    public:
    void showx(){
        cout<<"x: "<<x<<endl;
    }
    base1()
        { cout << "Constructing base1\n"; }
    ~base1()
        { cout << "Destructing base1\n"; }
};

class base2{
    protected:
    int y;
    public:
    void showy(){
        cout<<"y: "<<y<<endl;
    }
    base2()
        { cout << "Constructing base2\n"; }
    ~base2()
        { cout << "Destructing base2\n"; }
    
};

class derived: public base1,public base2{
    public: 
    void set(int i,int j){
        x=i;
        y=j;
    }
};

class Animal{
    protected: 
    string name;
    public: 
    Animal(string n){
        name=n;
    }
    void Eat(){
        cout<<name<<" is eating"<<endl;     
    }
};

class FlyingCreature{
    protected: 
    int altitude;
    public:
    FlyingCreature(int a) : altitude(a) {}
    void Fly(){
        cout<<"Flying at altitude "<<altitude<<endl;
    }
};


/* now this is where things get interesting....our previous inheritance examples were not using constructors
    whenever we use create an object for a derived class, to initialize the base class members...our object first calls 
    the constructor from the base class like in the previous examples the default constructor was called easily.
    but now in this example we have already createn a parameterized constructor for the base class so on creating an object 
    our derived class will not be able to call the base class constructor if we dont explicitly give it parameters and call it in the derived class
    so we have to explicitly call the base class constructor in the derived class constructor using the syntax below
    derived_class_name(parameters) : base_class_name(parameters) {
        // derived class constructor body
    }
*/

class Bird : public Animal, public FlyingCreature {
    public: 
    Bird(string n, int a): Animal(n), FlyingCreature(a) {} //explicitly calling the base class constructors
    void Chirp() {
        cout << name << " is chirping." << endl;
    }
};

class Shape{
    protected:
    int width;
    int height;
    public: 
    void setwidth(int w){
        width=w;
    }
    void setheight(int h){
        height = h;
    }
};

class PaintCost{
    public:
    int getcost(int area){
        return area*70;
    }
};

class Rectangle : public Shape, public PaintCost{
    public: 
    int getarea(){
        return width*height;
    }

};

int main(){

    derived d; //since constructor calling is from left to right...base1 calls first then base2 as written while inheriting classes (line 32)
    d.set(5,10); //from derived class
    d.showx(); //from base1 class
    d.showy(); //from base2 class

    Bird Sparrow("Sparrow", 100);
    Sparrow.Eat();   // Inherited from Animal class
    Sparrow.Fly();   // Inherited from FlyingCreature class
    Sparrow.Chirp(); // Specific to Bird class

    Rectangle rect;
    rect.setwidth(30);
    rect.setheight(40);
    int area = rect.getarea();
    int cost=rect.getcost(area);
    cout<< "the total cost for painting is: "<<cost<<endl;
    
    return 0;

}