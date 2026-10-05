#include <iostream>
using namespace std;

class Distance{
     int feet,inches;
     public:
        Distance():feet(0),inches(0){}
        Distance(int f,int i):feet(f),inches(i){}
        void display(){
            cout<<"Feet: "<<feet<<" Inches: "<<inches<<endl;
        }
        /*
        void unary_negative(){
            this->feet=-this->feet;
            this->inches=-this->inches;
        }
        */
        //operator overloading 
        void operator -(){
            this->feet=-this->feet;
            this->inches=-this->inches;
        }
        Distance operator+(Distance d){
            this->feet=this->feet + d.feet; 
            this->inches=this->inches + d.inches;
            //this is adding feet / inches of one object which calls the function + feet / inches of the object passed.
            return *this;
        }

};

// scope resolution, conditional, sizeof and class member access operators cant be overloaded
// other can be overloaded and unary operators remain unary and binary remain binary 
// not associativity harmed and no precedence harmed for all....rule of operator overlading

int main(){

    Distance d1(2,3);
    Distance d2(3,4);
    // -d1;
    // OR 
    //d1.operator-();
    Distance d4(2,7);
    Distance d3 = d1+d2+d4;     // here when d1 + d2...d1 is the object calling the operator so d1 is changed...depends on the funciton...if the function writes d.feet=this->feet+d.feet nd return d then d2 will be chnaged in this example not d1
    //OR                        // now when three summation i.e d1+d2 that changes d1 nd stores in d3..then it becomes d3+d4 then d3 gets modified.
    // d1.operator+(d2);
    cout<<"after summation operator: "<<endl;
    d3.display();
    d1.display();
    d2.display();
    d4.display();
    return 0;
}