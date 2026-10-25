#include <iostream>
using namespace std;

void create(int arr[], int size) {
    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void display(int arr[], int size) {
    cout << "Your created array:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int arr[], int pos, int val, int size){
 int a[size+1];
 // Copy elements up to the insertion position
    for (int i = 0; i < pos; i++) {
        a[i] = arr[i];
    }

    // Place the new value at 'pos'
    a[pos] = val;

    // Copy remaining elements, shifting them one position to the right
    for (int i = pos; i < size; i++) {
        a[i + 1] = arr[i];
    }
}

void del(int arr[], int pos, int size){
pos--;
 for(int i=pos;i<=size;i++){
  arr[i]=arr[i+1];
 }
 for (int i = 0; i < size-1; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    int pos,val,delpos;
    int menu;
    cout << "Enter choice: ";
    

    return 0;
}