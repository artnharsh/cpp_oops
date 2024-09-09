#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ACMpassManager {
private:
    //function to encrypt the password
    string encryptPassword(const string& password, int key = 5) {
        string encrypted = password;
        for (int i = 0; i < password.size(); ++i) {
            encrypted[i] = password[i] + key; //Shift the character by 'key'
        }
        return encrypted;
    }

    //function to decrypt the password
    string decryptPassword(const string& encryptedPassword, int key = 5) {
        string decrypted = encryptedPassword;
        for (int i = 0; i < encryptedPassword.size(); ++i) {
            decrypted[i] = encryptedPassword[i] - key; // Shift back the character by 'key'
        }
        return decrypted;
    }

public:
    // Function to add a new user
    void addUser() {
        string username, password;
        
        cout << "Enter username: ";
        cin >> username;
        
        cout << "Enter password: ";
        cin >> password;
        
        // Encrypt the password
        string encryptedPassword = encryptPassword(password);
        
        ofstream file("passwords.txt", ios::app);
        if (file.is_open()) {
            file << username << " " << encryptedPassword << endl;
            file.close();
            cout << "User added successfully!" << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    // Function to view all stored users and passwords
    void viewUsers() {
        string username, encryptedPassword;
        
        // Open the file for reading
        ifstream file("passwords.txt");
        if (file.is_open()) {
            cout << "\nStored Users and Passwords:" << endl;
            while (file >> username >> encryptedPassword) {
                // Decrypt the password before displaying
                string decryptedPassword = decryptPassword(encryptedPassword);
                cout << "Username: " << username << " | Password: " << decryptedPassword << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    ACMpassManager m;
    int choice;

    while (true) {
        cout << "\nPassword Manager" << endl;
        cout << "1. Add a new user" << endl;
        cout << "2. View stored usernames and passwords" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                m.addUser();
                break;
            case 2:
                m.viewUsers();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
