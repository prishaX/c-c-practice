#include <iostream>
#include <cstring>
using namespace std;

class triangle{
    int height;
    int base;
    public:
    triangle(int h,int b){
        height=h;
        base=b;
    }
    triangle compareArea(triangle &t1, triangle &t2) {
        double area1 = 0.5 * t1.base * t1.height;
        double area2 = 0.5 * t2.base * t2.height;

        if (area1 > area2)
            return t1;
        else
            return t2;
    }
};

class ShoppingCart {
private:
    int cart_id;
    string customer_name;
    int item_count;

public:
    ShoppingCart(int id, string name, int count) {
        cart_id = id;
        customer_name = name;
        item_count = count;
    }

    ~ShoppingCart() {
        cout << "Thank you, " << customer_name << endl;
    }

    void display_cart() {
        cout << "Cart ID: " << cart_id << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Number of Items in Cart: " << item_count << endl;
    }
};


class Student {
    string name;
    int age;
    public:
    Student(){
        name = "Unknown";
        age=0;
    }
    Student (string name,int age){
        this->name=name;
        this->age=age;
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
    ~Student(){}

};

class Car{
    int speed;
    int fuel;
    public:
    Car(int speed, int fuel) {
        this->speed = speed;
        this->fuel = fuel;
    }
    void display() {
        cout << "Speed: " << speed << endl;
        cout << "Fuel: " << fuel << endl;
    }
};

class HRS{
    public: 
    void display(){
        cout<<"room booked"<<endl;
    }
};

class PRODUCT{
    int id;
    string name;
    public: 
    PRODUCT(int i, string n){
        id=i;
        name=n;
    }
};

class DISCOUNTED_PRODUCT: public PRODUCT{
    double discount;
    public: 
    DISCOUNTED_PRODUCT(int i, string n, int discount) : PRODUCT(i,n){
        this->discount=discount;
    }
    double finalprice(double original){
        return original-(original*discount/100);
    }
};

int main(){

    
    triangle t1(20,30);
    triangle t2(20,40);
    triangle larger= t1.compareArea(t1,t2);

    
    int n;
    cin>>n;
    ShoppingCart** carts= new ShoppingCart*[n];
    for (int i=0;i<n;i++){
        int id; cin>>id;
        string name; cin>>name;
        int count; cin>>count;
        carts[i] = new ShoppingCart(id,name,count);
    }
    //this is like shoppingcart** carts is a double pointer where carts is a pointer to an array of pointers of shopping carts 
        for (int i=0;i<n;i++){
            carts[i]->display_cart();
        }


Student rohan;
Student hitakshi("hitakshi",20);


Car audi(100,2800);
Car maruti(80,400);
audi.display();
maruti.display();

/* 
char name[20] and char *name = new char[n]
here char name[] is used when we know the size of the input before hand bcs it needs to know how much memory to allocate at compile time so we cant do 
char name[n] whereas in dynamic memory allocation we can allocate memory at run time so we can take input of n and allocate memory dynamically  
*/
bool booked;
cin>>booked;
if (booked){
    HRS* booking=new HRS;
    booking->display();
    delete booking;
}

    return 0;
}