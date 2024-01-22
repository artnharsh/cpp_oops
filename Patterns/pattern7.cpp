#include<iostream>
using namespace std;

int main(){
    int n, i = 1, j = 1;
    cout<<"Enter the range:\t";
    cin>>n;
    char ch = 'a';
    while(i <= n){
        j = 1;
        ch = 'A';
        while(j <= n){
            cout<<ch++<<"\t";
            j++;
        }
        cout<<endl;
        i++;

    }
    return 0;
}