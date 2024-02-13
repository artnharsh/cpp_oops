#include<iostream>
#include<string>
using namespace std;

class student{
    int sub_1,sub_2,sub_3,roll_no;
    string name, sir_name;
    int total_marks_obtained;
    int total_max_marks;
    
    public:
    student(){
        sub_1 = 0;
        sub_2 = 0;
        sub_3 = 0;
        total_max_marks = 0;
        total_max_marks = 300;
    }
    void input();
    void calculate();
    void display();
};
void student :: input(){
    cout<<"Enter the name of the student :\n";
    cin>>name>>sir_name;
    cout<<"\nEnter the roll number of the student :\n";
    cin>>roll_no;
}
void student :: calculate(){
    cout<<"Enter the marks of Physics, Multivariate calculas and OOPS respectively :\n";
    cin>>sub_1>>sub_2>>sub_3;
    total_marks_obtained = sub_3 + sub_2 + sub_1;
}
void student :: display(){
    cout<<"Name of the student is :\t"<<name<<" "<<sir_name<<endl;
    cout<<"Marks of Physics :\t"<<sub_1<<endl;
    cout<<"Marks of Multivariate calculas :\t"<<sub_2<<endl;
    cout<<"Marks of OOP's :\t"<<sub_3<<endl;
    cout<<"Total marks obtained :\t"<<total_marks_obtained<<endl;
    cout<<"Total maximum marks :\t"<<total_max_marks<<endl;
}
int main(){
    student s[100];
    int d = 1, i = 0,count = 0;
    while(d == 1){
        s[i].input();
        s[i].calculate();
        i++;
        count++;
        cout<<"Enter 1 for continuing process or enter 0 to end the process :\t";
        cin>>d;
        if(d == 0){
            break;
        }
    }
    for(i = 0; i < count; i++){
        s[i].display();
        cout<<"-----------------------------------"<<endl;
    }
    return 0;
}












