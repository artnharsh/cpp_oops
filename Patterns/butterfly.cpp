#include<iostream>
using namespace std;

int main(){
    int i,j,n;
    cin>>n;

    for(i = 0; i < n; i++){

        for(j = 0; j < n; j++){
            if(j > i){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
            for(j = 0; j <= n; j++){
                if(j < n - i){
                    cout<<" ";
                }else{
                    cout<<"*";
                }
            }
        cout<<endl;
    }
    
    for(i = 0; i < n; i++){
        
        for(j = 0; j <= n; j++){
            if(j >= n-i){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }

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
