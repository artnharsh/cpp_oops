#include<iostream>
using namespace std;
int main(){
    int n;
    int i = 1, j = 1;

    cout<<"Enter n:\n";
    cin>>n;

    while(i <= n){
        
        j = 1;
        while(j <= i){
            cout<<"*"<<"\t";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}