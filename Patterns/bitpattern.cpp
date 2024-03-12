#include<iostream>
using namespace std;

int main(){
    int a = 1;
    int i,j;
    int n;
    cin>>n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j < i){
                cout<<" ";
            }else if((i + j) % 2 == 0){
                cout<<1;
                
            }else {
                cout<<0;
            }
        }
        cout<<endl;
    }
}