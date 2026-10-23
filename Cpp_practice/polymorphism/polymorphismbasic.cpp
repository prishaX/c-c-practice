#include <iostream>
using namespace std;

/* Function overloading is the process of using the same name for two or more functions.
The happens such that each redefinition of the function must use either different types of parameters or a different number of parameters.
but this is an error:
int myfunc(int i);
float myfunc(int i);
Error: differing return types are insufficient when overloading.
For example, consider the following declarations.
void f(int *p);
void f(int p[]); // error, *p is same as p[]
Remember, to the compiler *p is the same as p[ ]. Therefore, although the two prototypes appear
to differ in the types of their parameter, in actuality they do not.
*/

int myfunc(int i); 
double myfunc(double i); // these differ in types of parameters
int myfunc(int i, int j); //these differ in number of parameters

//example for function overloading in class 
class printData {
public:
    void print(int i) {
        cout << "Printing int: " << i << endl;
    }

    void print(double f) {
        cout << "Printing float: " << f << endl;
    }

    void print(char* c) {
        cout << "Printing character: " << c << endl;
    }
};

//issue of name hiding explained: (this is also called function overriding as function in derived/child class is overridden by the child)
class base {
    int a;
public:
    void showData(int x) {
        a = x;
        cout << "a:" << a << endl;
    }
};

class derived : public base {
    int b;
public:
    void showData() {
        b = 7;
        cout << "b:" << b << endl;
    }
};
// to fix this issue we can add using base::showData; in derived class to make it unhidden 

int main(){

cout << myfunc(10) << " "; // calls myfunc(int i)
cout << myfunc(5.4); // calls myfunc(double i)

printData pd;
// Call print to print integer
pd.print(5);
// Call print to print float
pd.print(500.263);
// Call print to print character
pd.print("Hello C++");

base base_ob;
base_ob.showData(5);
derived derived_ob;
derived_ob.showData();
// This will cause an error derived_ob.showData(6); as the base classes function are hidden now and the derived class function doesnt take a parameter 

return 0;
}

double myfunc(double i){
    return i;
}
int myfunc(int i){
    return i;
}
int myfunc(int i, int j){
    return i*j;
}
