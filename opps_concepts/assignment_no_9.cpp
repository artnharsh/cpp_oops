#include<iostream>
using namespace std;
class matrix{
    int a[3][3], b[3][3], c[3][3];

    public :
            void enterMatrix();
            void addMatrix();
            void substractMatrix();
            void multiplyMatrix();
            void displayMatrix();
};
void matrix :: enterMatrix(){
    int i,j;
    cout<<"\nEnter the elements of the first matrix :"<<endl;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    cout<<"\nEnter the elements of the second matrix :"<<endl;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cin >> b[i][j];                                         
        }
    }
}
void matrix :: addMatrix(){
    cout<<"\nAddition of the matrices is }:"<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = a[i][j] + b[i][j];        
        }        

    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<c[i][j]<<" ";        
        }cout<<endl;
    }
}
void matrix :: substractMatrix(){
    cout<<"\nSubstraction of the matrices is :"<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = a[i][j] - b[i][j];        
        }
    }
    

    cout<<"\nSubstraction of the matrices is :"<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<c[i][j]<<" ";        
        }        cout<<endl;

    }
}
void matrix :: multiplyMatrix(){
    int i,j,k;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                c[i][j] = a[i][k] + b[k][j];
            }        
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<c[i][j]<<" ";        
        }
        cout<<endl;
    }
}
void matrix :: displayMatrix(){
    
    int choice;
    do{
        

        cout<<"\n1. Enter the matrices."<<"\n2. Add the matrices"
        <<"\n3. Substract the matrices."<<endl<<"4. Multiply the matrices."<<endl<<"5. Exit the program."<<endl;
        cout<<"\n\nEnter your choice : ";
        cin>>choice;

        switch (choice){
            case 1: enterMatrix();
                    break;
            case 2: addMatrix();
                    break;
            case 3: substractMatrix();
                    break;
            case 4: multiplyMatrix();
                    break;
            case 5: cout<<"\nExitting The Program!!!";
                    break;
            default: cout<<"\nPlease enter the correct choice";
                    break;

        }
    }while(choice != 5);
    
    
}
int main(){
    matrix m;
    m.displayMatrix();
    return 0;
}