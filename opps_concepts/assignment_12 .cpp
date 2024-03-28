#include<iostream>

using namespace std;
class employee{
    private :
            string emp_id[100];
            string emp_name[100], emp_sir[100];
            int emp_salary;
            string emp_dept[100];
            int emp_phno[100];
            int emp_age[100];
    public :
            int n = 0;
            void get_details();
            void show_details();
};
void employee :: get_details(){
            int i = 0;
            int digit = 0;
            int min_age = 18;
            cout<<"\nHow many employes you want to add: ";
            cin>>n;
            while(i < n){
                cout<<"\nEnter the name and the sirname of the employee"
                    <<"\n(eg. Harshal Patil)\n";
                cin>>emp_name[i]>>emp_sir[i];
                cout<<"\nEnter the Employee id: ";
                cin>>emp_id[i];
                while(true){
                    try{
                        cout<<"\nEnter the age of the employee: ";
                        cin>>emp_age[i];
                        if(emp_age[i] < min_age){
                            throw min_age;
                        }else{
                            break;
                        }
                    }
                    catch( int k ){
                        cout<<"\nEmployee age cannot be less than"<<min_age;
                        cout<<"\nRe-Enter the age opf the employ !!";
                    }
                }
                cout<<"\nEnter the phone number of the employee: ";
                cin>>emp_phno[i];
                cout<<"\nEnter the dept of the employee: ";
                cin>>emp_dept[i];
                i++;
            }
}
void employee :: show_details(){
    try{
            if (n == 0)
                throw "No Data Found!!!";
            else
                cout<<"\nDetails of the employes are as follows";
                for(int  i = 0; i < n; i++){
                    cout<<"\nName: "<<emp_name[i]<<" "<<emp_sir[i];
                    cout<<"\nDept: "<<emp_dept[i];
                    cout<<"\nAge: "<<emp_age[i];
                    if(emp_age[i] < 30){
                        cout<<"\nSalary: 8000rs.";
                    }else if(emp_age[i] < 50){
                        cout<<"\nSalary: 16000rs.";
                    }else{
                        cout<<"\nSalary: 24000rs.";
                    }
                    cout<<"\nPhone number: "<<emp_phno[i];
                    cout<<"\nId: "<<emp_id[i];
                    cout<<"\n\n------------------------------------------------------------";
                }
                
        }
        catch( int a){
            cout<<"\nEnter the details first ;)";
        }
        
int main(){
    employee obj;
    int ch;
    ch = 0;
    while(ch != 3){
        cout<<"\n1. Enter employee details."
            <<"\n2. Show employee details."
            <<"\n3. Exit.\n";
        cin>>ch;
        switch(ch){
            case 1:
                    obj.get_details();
                    break;
            case 2:
                    obj.show_details();
                    break;
            case 3:
                    cout<<"\nProgram exited!!!";
                    return 0;
            default:
                    cout<<"Incorrect choice.";
                    break;
        }
    }
    return 0;
}
    
