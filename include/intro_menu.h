#pragma once
#include <fstream>
#include <iostream>
#include "account_menu.h"
#include "users.h"
class IntroMenu
{
public:
    IntroMenu(Users users);
    void display_menu(User users);
    void display_menu(Users users);
    void handle_user_selection(int choice);

private:
    // AccountMenu account_menu;
    Users users;
    // User user;
};