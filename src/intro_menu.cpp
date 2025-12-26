#include "intro_menu.h"

void IntroMenu::display_menu(Users users)
{
    this->users = users;
    printf("Welcome to the Budget App!\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    printf("Please enter an option: ");
    int choice;
    std::cin >> choice;
    handle_user_selection(choice);
}
void IntroMenu::handle_user_selection(int choice)
{
    Users users;
    std::string username;
    std::string password;
    User current_user("", "");
    AccountMenu account_menu(current_user);

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Login selected.\n");
        // Handle login logic here
        current_user = users.login_user();

        account_menu.display_menu(current_user);

        break;
    case 2:
        system("cls");
        printf("Register selected.\n");
        // Handle registration logic here
        users.register_user();
        current_user = users.login_user();
        account_menu.display_menu(current_user);
        // add account menu here to access bank info and operations
        break;
    case 3:
        printf("Exiting the application. Goodbye!\n");
        exit(0);
    default:
        printf("Invalid choice. Please try again.\n");

        display_menu(users);
        break;
    }
}
void IntroMenu::display_menu(User users)
{
    // This function is intentionally left blank as per the current design.
}
IntroMenu::IntroMenu(Users users) : users(users)
{
    // printf("Welcome to the Budget App!\n");
}