#include <iostream>
#include <cstring>
using namespace std;

/* 
1. basic to user defined type conversion- primitive type to class type (struct type)
    this is done either by using constructor or by operator overloading 
2. user defined to basic- class type to primitive type 
3. 
*/

class Distance{
    private: 
    int feet;
    float inches;
    public: 
//BASIC TO USER DEFINED EXAMPLE USING CONSTRUCTORS 
    /*Distance(int meters){
        feet=meters*3.281;
        inches=(meters*3.281-feet)*12;
    }*/

//BASIC TO USER DEFINED BY OVERLOADING OPERATORS
    Distance( int f=0, float i=0): feet(f),inches(i){}
    Distance& operator=(int meters){
        feet=meters*3.281;
        inches=(meters*3.281-feet)*12;
        return *this;
    }
    void display(){
        cout<<feet<<" "<<inches<<endl;
    }
};

int main(){
    //BASIC TO USER DEFINED EXAMPLE USING CONSTRUCTORS 
    int distance;
    cout<<"enter distance in metres"<<endl;
    cin>>distance;
    Distance d=distance;
    //assignment (=) implicit conversion from int to Distance...i.e distance is sent to parameterized constructor i.e initialization is happening. if it were Distance d; d=5; then first the object has been initialized then its assigned.
    d.display();
//BASIC TO USER DEFINED BY OVERLOADING OPERATORS
    Distance d1; //default calling 
    int metres;
    cout<<"enter distance in metres"<<endl;
    cin>>metres;
    d1=metres;
    d1.display();

    return 0;
}

//BASIC TO USER DEFINED BY OVERLOADING OPERATORS
