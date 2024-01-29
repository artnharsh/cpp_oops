#include<iostream>
using namespace std;

class arr{
    int a[5];
    public :
    void input();
    void dothis();
    void display();
};

void arr :: input(){
    cout<<"Enter the elements of the array:\n";

    int i = 0;
    for(i = 0; i < 5; i++){
        cin >> a[i];
    }
}

void arr :: dothis(){
    int min;
    int i , j;
    for(i = 0; i < 5; i++){
        
        for(j = i + 1; j < 5; j++){
            if(a[i] > a[j]){ // for decending order we just have to put the "<" this sign
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void arr :: display(){
    int i;
    cout<<"The array in the sorted manner is:\n\a";
    for(i = 0; i < 5; i++){
        cout<<a[i]<<endl;
    }
}
int main(){
    arr asc;
    asc.input();
    asc.dothis();
    asc.display();
    return 0;
}