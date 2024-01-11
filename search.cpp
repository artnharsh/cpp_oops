#include<iostream>
using namespace std;
int main(){
    int n;
    int a[n];
    int flag = 0;

    cout<<"Enter the size of the array:\n";
    cin>>n;

    cout<<"Enter the elements of the array:\n";

    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int key;

    cout<<"Enter the element that is to be found:\n";
    cin>>key;

    for(int i = 0; i < n; i++){
        if(a[i] == key){
            
            flag = 1;
        }
    }

    if (flag == 1)
    {
        cout<<"Enter element is present in the array";
    } else{
        cout<<"Entered element is not present in the array";
    }
    
return 0;
    

    
}