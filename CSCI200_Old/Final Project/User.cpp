#include "User.h"
#include <iostream>
// Include necessary headers for hashing

User::User(std::string username, std::string hash) : username(username), hash(hash) {
    
}

std::string User::getUsername() const 
{
    return username;
}

std::string User::getHash() const 
{
    return hash;
}

std::string User::generateHash(const std::string& username, const std::string& password) 
{
    // Implement a simple hash generation logic (should be replaced with a proper hash function)
    return username + ":" + password; // Placeholder
}

bool User::login(const std::string& username, const std::string& password) const 
{
    return this->username == username && generateHash(username, password) == hash;
}

std::pair<User, std::string> User::createUser(const std::string& username, const std::string& password) 
{
    std::string hash = generateHash(username, password);
    return {User(username, hash), hash};
}
