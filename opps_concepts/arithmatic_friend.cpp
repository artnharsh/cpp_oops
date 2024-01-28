#include<iostream>
using namespace std;

class mac;
class win{
    int b;
    friend void input(mac&, win&);
    friend void calc(mac&, win&);
};

class mac{
    int a;
    friend void input(mac&, win&);
    friend void calc(mac&, win&);
};

void input(mac& x, win& y){
    cout<<"Enter the first and the second variable :\t";
    cin>>x.a>>y.b;
}

void calc(mac& x, win& y){
    char op;
    int result;
    cout<<"Enter the operator(+,-,*,/, any one of this):\t";
    cin>>op;
    switch (op)
    {
    case '+':
        result = x.a + y.b;
        cout<<"output :\t"<<result;
        break;
    case '-':
        result = x.a - y.b;
        cout<<"output :\t"<<result;
        break;
    case '*':
        result = x.a * y.b;
        cout<<"output :\t"<<result;
        break;
    case '/':
        result = x.a / y.b;
        cout<<"output :\t"<<result;
        break;    
    default:
        cout<<"Enter the appropriate operator";
        break;
    }
}

int main(){
    mac first;
    win second;
    input(first, second);
    calc(first, second);

    return 0;
}
