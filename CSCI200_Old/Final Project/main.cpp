#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
using namespace std;

vector<User> loadUsers(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    string username, hash;
    while (file >> username >> hash) {
        users.emplace_back(username, hash);
    }
    return users;
}

void saveUser(const std::string& filename, const std::string& username, const std::string& hash) {
    std::ofstream file(filename, std::ios::app);
    file << username << " " << hash << "\n";
}

int main() {
    vector<User> users = loadUsers("users.txt");
    
    string username, password;
    int choice;
    cout << "1. Login\n2. Create Account\nChoose option: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (const auto& user : users) 
        {
            if (user.login(username, password)) 
            {
                cout << "Logged in\n";
                return 0;
            }
        }
        cout << "Login failed\n";
    } else if (choice == 2) {
    std::cout << "Choose a username: ";
    std::cin >> username;
    std::cout << "Choose a password: ";
    std::cin >> password;

    auto [newUser, hash] = User::createUser(username, password);
    saveUser("users.txt", newUser.getUsername(), hash);
    std::cout << "Account created\n";
}

    return 0;
}
