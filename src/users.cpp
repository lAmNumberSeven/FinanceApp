#include "users.h"
#include <algorithm>
#include <fstream>
#include <iostream>

Users::Users()
{
    // Load users from file
    std::ifstream file("users.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            size_t delimiter_pos = line.find(',');
            if (delimiter_pos != std::string::npos)
            {
                std::string username = line.substr(0, delimiter_pos);
                size_t second_delimiter_pos = line.find(',', delimiter_pos + 1);
                std::string password = line.substr(delimiter_pos + 1, second_delimiter_pos - delimiter_pos - 1);
                int user_id = std::stoi(line.substr(second_delimiter_pos + 1));
                User user(username, password);
                user.set_id(user_id);
                registered_users.push_back(user);
                if (user_id >= id)
                {
                    id = user_id + 1; // Ensure unique ID for next user
                }
            }
        }
        file.close();
    }
}
// Users::~Users()
// {
//     // Optionally save users to file on destruction
// }

void Users::register_user()
{
    printf("Please enter your login credentials.\n");
    // take user input and create a new user
    std::string username;
    std::string password;
    printf("Enter username: ");
    std::cin >> username;
    printf("Enter password: ");
    std::cin >> password;
    User user(username, password);

    // insert user into registered_users vector and assign an ID
    registered_users.insert(registered_users.begin() + id, user);
    user.set_id(id);

    // save user to output file
    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open())
    {
        file << user.get_username() << "," << user.get_password() << "," << user.get_id() << "\n";
        file.close();
    }

    // confirm registration
    printf("User %s registered with ID %d\n", user.get_username().c_str(), id);

    // increment ID for next user
    id++;
}
User Users::login_user()
{
    std::string input_username;
    std::string input_password;

    printf("Enter username: ");
    std::cin >> input_username;
    printf("Enter password: ");
    std::cin >> input_password;

    if (validate_credentials(input_username, input_password))
    {
        // rewrite password variable to avoid access (no longer needed after validation)
        std::fill_n(&input_password[0], input_password.size(), '\0');

        User temp_user("", ""); // temporary user to hold pointer
        for (auto &user : registered_users)
        {
            if (user.get_username() == input_username)
            {
                temp_user = user;
                break;
            }
        }
        temp_user.login();
        return temp_user;
    }
    else
    {
        printf("Invalid username or password. Please try again.\n");
        system("cls");
        login_user(); // retry login
    }
    return User("", "");
}
bool Users::validate_credentials(const std::string &username, const std::string &password)
{
    for (const auto &user : registered_users)
    {
        if (user.get_username() == username && user.get_password() == password)
        {
            return true;
        }
    }
    return false;
}
