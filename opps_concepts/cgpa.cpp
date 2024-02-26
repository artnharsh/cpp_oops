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
    int n;
    cout<<"\nEnter the numbers of the student: \n";
    cin>>n;
    obj = new dynamic_allocation[n];
    cout<<"\nEnter the SGPA of the first and second term of the student:\n";
    for (int i = 0; i < 5; i++) {
        cout<<"\nStudent: "<<i + 1<<endl;
        obj[i].input();
    }
    cout<<"\nSGPA's you entered are:\n";
    for (int i = 0; i < 5; i++) {
        obj[i].display();
    }

    delete[] obj;
    return 0;
}
