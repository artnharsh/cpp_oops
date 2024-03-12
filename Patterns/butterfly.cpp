#include<iostream>
using namespace std;

int main(){
    int i,j,n;
    cin>>n;
    //dividing pattern into squares
    for(i = 0; i < n; i++){
        //printing first square of upper half
        for(j = 0; j < n; j++){
            if(j > i){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
        //printing second square of upper half
            for(j = 0; j <= n; j++){
                if(j < n - i){
                    cout<<" ";
                }else{
                    cout<<"*";
                }
            }
        cout<<endl;
    }
    //printing lower half squares
    for(i = 0; i < n; i++){
        //1st lower half square
        for(j = 0; j <= n; j++){
            if(j >= n-i){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
    //2nd lower half square
            for(j = 0; j < n; j++){
                if(j < i){
                    cout<<" ";
                }else{
                    cout<<"*";
                }
            }

        cout<<endl;
    }
}
