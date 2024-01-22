#include<iostream>
using namespace std;

class set_2;  // Forward declaration

class set_1 {
    int a;
    string b;

public:
    void input();
    friend void display(set_1, set_2);
    friend void swap(set_1&, set_2&);
};

class set_2 {
    int c;
    string d;

public:
    void input_1();
    friend void display(set_1, set_2);
    friend void swap(set_1&, set_2&);
};

void set_1::input() {
    cout << "Enter the integer value and the string:\n";
    cin >> a >> b;
}

void set_2::input_1() {
    cout << "Enter the integer value and the string of the second class:\n";
    cin >> c >> d;
}

void swap(set_1 &x, set_2 &y) {
    int temp = x.a;
    x.a = y.c;
    y.c = temp;

    // Swap the strings
    string temp2 = x.b;
    x.b = y.d;
    y.d = temp2;
}

void display(set_1 m, set_2 k) {
    cout << "After swapping the elements:\n";
    cout << "a:\t" << m.a << endl << "b:\t" << m.b << endl << "c:\t" << k.c << endl << "d:\t" << k.d << endl;
}

int main() {
    set_1 i;
    set_2 j;
    i.input();
    j.input_1();
    swap(i, j);
    display(i, j);

    return 0;
}
