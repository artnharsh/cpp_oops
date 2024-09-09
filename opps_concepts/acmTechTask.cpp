#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

using namespace std;

class ACMpassManager {
private:
    // Function to encrypt the password
    string encryptPassword(const string& password, int key = 5) {
        string encrypted = password;
        for (int i = 0; i < password.size(); ++i) {
            encrypted[i] = password[i] + key; // Shift the character by 'key'
        }
        return encrypted;
    }

    // Function to decrypt the password
    string decryptPassword(const string& encryptedPassword, int key = 5) {
        string decrypted = encryptedPassword;
        for (int i = 0; i < encryptedPassword.size(); ++i) {
            decrypted[i] = encryptedPassword[i] - key; // Shift back the character by 'key'
        }
        return decrypted;
    }

    // Function to generate a strong password
    string generateStrongPassword(int length = 12) {
        const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "0123456789"
                                   "!@#$%^&*()_+[]{}|;:,.<>?";
        string password;
        srand(static_cast<unsigned>(time(0))); // Seed the random number generator
        for (int i = 0; i < length; ++i) {
            password += characters[rand() % characters.size()];
        }
        return password;
    }

public:
    // Function to add a new user
    void addUser() {
        string username, password;
        char choice;

        cout << "Enter username: ";
        cin >> username;

        cout << "Do you want to generate a strong password? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            // Generate a strong password
            password = generateStrongPassword();
            cout << "Generated strong password: " << password << endl;
        } else {
            cout << "Enter your password: ";
            cin >> password;
        }

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

    // Function to delete a user by username
    void deleteUser() {
        string usernameToDelete;
        cout << "Enter the username to delete: ";
        cin >> usernameToDelete;

        vector<pair<string, string>> users; // To store all users except the one to be deleted
        string username, encryptedPassword;
        bool found = false;

        // Open the file for reading
        ifstream file("passwords.txt");
        if (file.is_open()) {
            while (file >> username >> encryptedPassword) {
                if (username != usernameToDelete) {
                    // Add all users except the one to delete
                    users.push_back({username, encryptedPassword});
                } else {
                    found = true;
                }
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
            return;
        }

        if (found) {
            // Rewrite the file without the deleted user
            ofstream outFile("passwords.txt", ios::trunc); // Truncate the file
            if (outFile.is_open()) {
                for (const auto& user : users) {
                    outFile << user.first << " " << user.second << endl;
                }
                outFile.close();
                cout << "User '" << usernameToDelete << "' deleted successfully!" << endl;
            } else {
                cout << "Unable to open file for writing!" << endl;
            }
        } else {
            cout << "User '" << usernameToDelete << "' not found!" << endl;
        }
    }

    // Function to update a user's password
    void updateUser() {
        string usernameToUpdate, newPassword;
        cout << "Enter the username to update: ";
        cin >> usernameToUpdate;

        cout << "Enter the new password: ";
        cin >> newPassword;

        vector<pair<string, string>> users; // To store all users and update the specified user
        string username, encryptedPassword;
        bool found = false;

        // Open the file for reading
        ifstream file("passwords.txt");
        if (file.is_open()) {
            while (file >> username >> encryptedPassword) {
                if (username == usernameToUpdate) {
                    // Encrypt the new password
                    encryptedPassword = encryptPassword(newPassword);
                    found = true;
                }
                // Add the user to the list
                users.push_back({username, encryptedPassword});
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
            return;
        }

        if (found) {
            // Rewrite the file with updated password
            ofstream outFile("passwords.txt", ios::trunc); // Truncate the file
            if (outFile.is_open()) {
                for (const auto& user : users) {
                    outFile << user.first << " " << user.second << endl;
                }
                outFile.close();
                cout << "Password for user '" << usernameToUpdate << "' updated successfully!" << endl;
            } else {
                cout << "Unable to open file for writing!" << endl;
            }
        } else {
            cout << "User '" << usernameToUpdate << "' not found!" << endl;
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
        cout << "3. Delete a user" << endl;
        cout << "4. Update a user's password" << endl;
        cout << "5. Exit" << endl;
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
                m.deleteUser();
                break;
            case 4:
                m.updateUser();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
