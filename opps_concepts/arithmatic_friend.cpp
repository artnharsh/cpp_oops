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
        cout<<"output :\t"<<result<<endl;
        break;
    case '-':
        result = x.a - y.b;
        cout<<"output :\t"<<result<<endl;
        break;
    case '*':
        result = x.a * y.b;
        cout<<"output :\t"<<result<<endl;
        break;
    case '/':
        result = x.a / y.b;
        cout<<"output :\t"<<result<<endl;
        break;    
    default:
        cout<<"Enter the appropriate operator";
        break;
    }
}

int main(){
    mac first;
    win second;
    int g = 1;
    while(g == 1){
        input(first, second);
        calc(first, second);
        cout<<"Enter 0 to end or enter 1 to repeat the task:\t"<<endl;
        cin>>g;
    }
   
    return 0;
}
