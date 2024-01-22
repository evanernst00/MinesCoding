#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(std::string username, std::string hash);

    std::string getUsername() const;
    bool login(const std::string& username, const std::string& password) const;

    static std::pair<User, std::string> createUser(const std::string& username, const std::string& password);

private:
    std::string username;
    std::string hash;

    std::string getHash() const;
    static std::string generateHash(const std::string& username, const std::string& password);
};

#endif // USER_H
