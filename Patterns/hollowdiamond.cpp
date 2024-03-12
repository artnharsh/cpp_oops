#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j == n - i - 1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }

        for(j = 1; j <= i; j++){
            if(j == i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j == i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }

        for(j = 0; j < n - 1; j++){
            if(j == n - i -2){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}