//note this is the basic one 
//proper students database program will be uploaded further
#include<iostream>
using namespace std;

class student{
    private :
        int total_marks_obt, sub1, sub2, sub3;
        string name;
        int total_marks;

    public :
        void assign();
        void comput();
        void display();
};

void student :: assign(){
    cout<<"Enter the the name of the student:\n";
        cin>>name;

    cout<<"Enter the marks of the students out of 100:\a\n";
        cin>>sub1>>sub2>>sub3;

}

void student :: comput(){
    
    total_marks_obt = sub1 + sub2 + sub3 ;

    total_marks = 3 * 100;

}

void student :: display(){
    int per;
    per = total_marks_obt / 3;
    cout<<"The students academic details are as follows:\n";
    cout<<"Name:\t"<<name<<endl<<"Math marks:\t"<<sub1<<endl<<"Comp marks:\t"<<sub2<<endl<<"Physics marks:\t"<<sub3<<endl<<"Total marks obtained:\t"<<total_marks_obt<<endl<<"Out of:\t"<<total_marks<<endl<<"Percentage obtained:\t"<<per<<"%"<<endl;
}

int main(){
    student one;
    one.assign();
    one.comput();
    one.display();
    return 0;
}
