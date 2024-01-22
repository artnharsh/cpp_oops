#include<iostream>
using namespace std;

int main(){
    int n ,i = 1, j = 1;
    cout<<"Enter the range:\t";
    cin>>n;

    char ch = 'A';

    while(i <= n){
        j = 1;
        while(j <= n){
            cout<<ch<<"\t";
            j++;
        }
        ch++;
        cout<<endl;
        i++;
    }
    return 0;
}