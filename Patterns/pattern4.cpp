#include<iostream>
using namespace std;
int main(){
    int n;
    int i = 1, j = 1;
    int count = 1;
    cout<<"Enter n:\n";
    cin>>n;

    while(i <= n){
        
        j = 1;
        count = i;
        while(j <= i){
            cout<<count<<"\t";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}