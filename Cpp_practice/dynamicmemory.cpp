#include <iostream>
using namespace std;

class Data {
public :
int m ;
};

void show ( int x ) {
cout << " Value : " << x << endl ;
}

int main () {
Data obj ;
Data * objPtr = & obj ;
obj . m = 25;
// Pointer to data member m


int Data ::* ptr = & Data :: m;
// Remember which DATA MEMBER of the class I'm interested in, without choosing a particular object yet and point to it.

cout << " Value using object and data member " << obj.m << endl ;
cout << " Value using object and pointer to data member " << obj.*ptr << endl ;
cout << " Value using object pointer and pointer to data member : "<< objPtr->*ptr << endl ;
// obj.*ptr means: Take this object obj, and access the data member that ptr refers to.
// objPtr->*ptr means go to the object pointed to by objPtr, and access the member represented by ptr.

//and similarly for a function---
// Pointer to function taking int and returning void
void (*funcPtr) (int) = &show ;
// Invoking the function via pointer
funcPtr(50);

return 0;
}