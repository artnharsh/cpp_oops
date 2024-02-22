#include<iostream>
#include<iomanip>
using namespace std;

class book {
    int price[100], stock[100], n;
    string author[100], author_s[100], publisher[100], title[100];
    int i = 0;
public:
    void enter_data() {
        int d = 1;
        cout << "\nEnter the no . of books : ";
        cin >> n;
        while (d == 1) {
            cout << "\nEnter the title:\n";
            cin >> title[i];
            cout << "\nEnter the author:\n";
            cin >> author[i] >> author_s[i];
            cout << "\nEnter the publisher:\n";
            cin >> publisher[i];
            cout << "\nEnter the price:\n";
            cin >> price[i];
            cout << "\nEnter the current stock of that book:\n";
            cin >> stock[i];

            cout << "\nDo you want to continue (yes 1 | no 0):\n";
            cin >> d;
            if (d == 0) {
                break;
            }
            else {
                i++;
                if (i >= n) {
                    break;
                }
            }
        }
    }

    void buy_book() {
        int m = 1;
        while (m == 1) {
            cout << "\nEnter the title of the book that you want:\n";
            string t;
            cin >> t;
            bool bookFound = false;
            for (int j = 0; j < n; j++) {
                if (title[j] == t) {
                    bookFound = true;
                    cout << "Title : " << title[j] << endl;
                    cout << "Author : " << author[j] << " " << author_s[j] << endl;
                    cout << "Publisher : " << publisher[j] << endl;
                    cout << "Price : " << price[j] << endl;
                    cout << "Stock :" << stock[j] << endl;

                    int num;
                    cout << "\nHow many books do you want:\n";
                    cin >> num;
                    if (num < 1) {
                        cout << "\nEnter valid input!!";
                    }
                    else if (num > stock[j]) {
                        cout << "\nWe only have " << stock[j] << " books of " << title[j] << endl;
                        int d = 0;
                        cout << "\nDo you want " << stock[j] << " books (yes 1 | no ):\n";
                        cin >> d;

                        if (d == 1) {
                            int payment;
                            payment = price[j] * stock[j];
                            stock[j] = 0;
                            char c;
                            cin >> c;
                            if (c == 'y' || c == 'Y') {
                                cout << "Payment Successful. Your transaction has been recorded. Thank You!\n";
                            }
                            else if (c == 'n' || c == 'N') {
                                cout << "Transaction Cancelled.\n";
                            }
                            else {
                                cout << "Invalid Input. Please enter 'yes' or 'no'. Try again.\n";
                            }
                            
                        }
                    }
                    else if (num > 1 && num <= stock[j]) {
                        int payment = price[j] * num;
                        stock[j] -= num;
                        cout << "Total amount to pay : RM" << payment << ". Do you wish to proceed? (yes/no) \n";
                        char c;
                        cin >> c;
                        if (c == 'y' || c == 'Y') {
                            cout << "Payment Successful. Your transaction has been recorded. Thank You!\n";
                        }
                        else if (c == 'n' || c == 'N') {
                            cout << "Transaction Cancelled.\n";
                        }
                        else {
                            cout << "Invalid Input. Please enter 'yes' or 'no'. Try again.\n";
                        }
                    }
                }
            }
            if (!bookFound) {
                cout << "No such book found.\n";
            }

            cout << "\nDO YOU WANT TO BUY ANOTHER BOOK (yes 1 | no 0):\n";
            cin >> m;
            if (m == 0) {
                break;
            }
        }
    }

    void display() {
        cout << "\nCurrent status of the stocks of the books:\n";
        for (int j = 0; j < n; j++) {
            cout << "\nTitle :" << setw(10) << title[j] << endl;
            cout << "Price :" << setw(8) << price[j] << endl;
            cout << "Stock :" << setw(6) << stock[j] << endl;
        }
    }
};

int main() {
    book obj;
    int m;
    int n;
    m = 1;
    while (m == 1) {
        cout << "\n1. Enter the data of books" << endl
            << "2. Buy a book" << endl
            << "3. Display current stocks" << endl;
        cout << "\nEnter your choice: ";
        cin >> n;
        switch (n) {
        case 1:
            obj.enter_data();
            break;
        case 2:
            obj.buy_book();
            break;
        case 3:
            obj.display();
            break;
        default:
            cout << "\nWrong choice! Try again.";
        }
        cout << "\n\nDo you want to display choices again (1/0)? ";
        cin >> m;
        if (m == 0) {
            break;
        }
    }
    return 0;
}
