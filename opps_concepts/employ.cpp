#include<iostream>
using namespace std;

class employ{
    string name;
    int id, salary;

    public:
    
    void input();
    void display();

};

void employ :: input(){
    cout<<"Enter the name, id and the salary of the employ respectively :\n";
    cin>>name>>id>>salary;
}

void employ :: display(){
    cout<<"Name :\t"<<name;
    cout<<"ID :\t"<<id;
    cout<<"Salary :\t";
}

int main(){
    int n;
    employ a[n];

    cout<<"Enter the total numbers of the employs whose data is to be entered :\n";
    cin>>n;

    for(int i = 0; i < n; i++){
        a[i].input();
    }

    cout<<"Here is the data of the employs :\n";

    for(int i = 0; i < n; i++){
        a[i].display();
        cout<<"-----------------------------------\n";
    }
    return 0;
}