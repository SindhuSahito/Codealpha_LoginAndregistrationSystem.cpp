#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// Load all user credentials from file
unordered_map<string, string> loadCredentials() {
    unordered_map<string, string> users;
    ifstream file("users.txt");
    string username, password;

    while (file >> username >> password) {
        users[username] = password;
    }

    file.close();
    return users;
}

// Register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    unordered_map<string, string> users = loadCredentials();

    if (users.find(username) != users.end()) {
        cout << "❌ Username already exists. Try another.\n";
        return;
    }

    ofstream file("users.txt", ios::app); 
    file << username << " " << password << endl;
    file.close();
    cout << "✅ Registration successful!\n";
}

// Login existing user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    unordered_map<string, string> users = loadCredentials();

    if (users.find(username) != users.end() && users[username] == password) {
        cout << "✅ Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "❌ Invalid username or password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
