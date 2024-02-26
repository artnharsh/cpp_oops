#include<iostream>
using namespace std;

class dynamic_allocation {
    int a[2];
public:
    void input();
    void display();
};

void dynamic_allocation::input() {
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }
}

void dynamic_allocation::display() {
    for (int i = 0; i < 2; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    dynamic_allocation *obj;
    obj = new dynamic_allocation[10];
    cout<<"\nEnter the elements of the dynamic array:\n";
    for (int i = 0; i < 5; i++) {
        obj[i].input();
    }
    cout<<"\nValues you entered are:\n";
    for (int i = 0; i < 5; i++) {
        obj[i].display();
    }

    delete[] obj;
    return 0;
}
