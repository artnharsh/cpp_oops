#include<iostream>
using namespace std;

class geometry{
    private :

    int length, breadth, height, radius, area;

    public :

    geometry(){
        length = 0;
        breadth = 0;
        height = 0;
        radius = 0;
        area = 0;
    }

    void input(); //area of the square
    void input(int l, int b, int h); //volume of cuboid
    void input(int r); // area of circle 

};

void  geometry::input() {
    while(true) {
        cout << "Enter side length of the square: ";
        cin >> length;
        if (length <= 0) {
            cout << "Invalid Input"<< endl;
            continue;
        } else break;
    }

    int area = length * length;
    cout << "Area of Square is: " << area << endl;
}
void geometry :: input(int l , int b , int h ) {
    length = l ;
    breadth = b ;
    height = h ;
    
    float volume = length*breadth*height /1000.0;
    cout << "Volume of Cuboid is: " << volume << " litres" <<endl;
}

void geometry :: input(int r ) {
    radius = r ;
    float area = 3.1415926 * radius *radius;
    cout << "Area of Circle is: " << area << " sq. units" <<endl;
}

int main() {
    // Create object of class Geometry
    geometry geo_obj;
    int rad;
    char ch;
    int len, bre, hei;
    while(true){
       
        cout << "\nMenu:\n1. Area of Square\n2. Volume of Cube/Cuboid\n3. Area of Circle\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch(ch) {
            case '1':
                geo_obj.input();
                break;
            case '2':
                cout<<"Enter length and breadth and height of Cuboid: ";
                cin>>len>>bre>>hei;
                geo_obj.input(len , bre, hei);
                break;
            case '3':
                cout<<"Enter Radius of the circle: ";
                cin>>rad;
                geo_obj.input(rad);
                break;
            case '4':
                return 0;
            default :
                cout << "Wrong Choice!" << endl;
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
        if(ch == 'n')
            return 0;
    }
    return 0;
}
  