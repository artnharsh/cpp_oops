#include<iostream>
using namespace std;
 class gallon{
    private:
        float gallon;
        double cubic_feet;
    public:
        void input(){
            cout<<"Enter the value in gallon:\n";
            cin>>gallon;
        }
        void calculate(){
            cubic_feet = gallon / 7.481;
        }
        void display(){
            cout<<"The value in the cubic feet is:\n"<<cubic_feet;
        }
 };

 int main(){
    gallon cuft;
    cuft.input();
    cuft.calculate();
    cuft.display();
 }
 