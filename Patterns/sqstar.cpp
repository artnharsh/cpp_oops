#include<iostream>
using namespace std;
int main(){
    // int n;
    // int i = 1, j = 1;
    // cin>>n;
    // while(i <= n){
    //     j = 1;
    //     while(j <= n){
    //         cout<<"* ";
    //         j++;
    //     }
    //     cout<<"\n";
    //     i++;
    // }

    int n;
    int i = 1, j = 1;
    cin>>n;
    while(i <= n){
        j = 1;
        while(j <= n){
            cout<<i;
            j++;
        }
        cout<<"\n";
        i++;
    }
    return 0;
}