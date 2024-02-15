#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter two Numbers\n";
    cin>>m>>n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //i == 0 || j == 0 || i == m-1 || j == n-1 ? cout<<" * ":cout<<"    ";
            if(i == 0 || j == 0 || j == n-1 || i == m-1){
                cout<<" * ";
            }else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
}
