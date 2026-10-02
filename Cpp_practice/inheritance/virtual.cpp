#include <iostream>
using namespace std;

/*
As you can see, the keyword virtual precedes the rest of the inherited
class‘specification.
• Now that both derived1 and derived2 have inherited base as virtual,
any multiple inheritance involving them will cause only one copy of
base to be present.
• Therefore, in derived3, there is only one copy of base and ob.i = 10 is
perfectly valid and unambiguous
*/

class base
{
public:
    int i;
};
// derived1 inherits base as virtual.
class derived1 : virtual public base
{
public:
    int j;
};
// derived2 inherits base as virtual.
class derived2 : virtual public base
{
public:
    int k;
};
class derived3 : public derived1, public derived2
{
public:
    int sum;
};
int main()
{
    derived3 ob;
    ob.i = 10; // now unambiguous
    ob.j = 20;
    ob.k = 30;
    // unambiguous
    ob.sum = ob.i + ob.j + ob.k;
    // unambiguous
    cout << ob.i << " ";
    cout << ob.j << " " << ob.k << " ";
    cout << ob.sum;
    return 0;
}
