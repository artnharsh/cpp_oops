#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string file_name;
    cout<<"\nEnter the name of the file: ";
    cin>>file_name;
    cout<<endl;
    ifstream file_read;
    file_read.open(file_name);
    char ch;
    int lines=1,words=0,characters=0;
    while(!file_read.eof()){
        characters++;
        if(ch=='\n'){
            lines++;
        }else if (ch ==' '){
            words++ ;
        }
        file_read.get(ch) ;
        cout<<ch;
    }
    file_read.close();
    cout<<"Number of Lines : " <<lines;
    cout<<"\nNumber of Words : " <<words+lines;
    cout<<"\nNumber of Characters : " <<characters<<endl<<endl;
    
    
}