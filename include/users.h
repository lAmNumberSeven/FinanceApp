#pragma once
#include "user.h"

class Users
{
public:
    Users();
    // ~Users();
    void register_user();
    User login_user();

private:
    bool validate_credentials(const std::string &username, const std::string &password);
    std::string get_user_password(const std::string &username);
    int id = 0;
    std::vector<User> registered_users;
};