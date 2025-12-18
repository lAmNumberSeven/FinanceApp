#pragma once
#include "user.h"
#include <fstream>
#include <iostream>
class AccountMenu
{
public:
    AccountMenu(User user);
    void display_menu(User user);
    void handle_user_selection(int choice);

    // handle user selections for account operations
    void view_account_details();
    void deposit_funds();
    void withdraw_funds();
    void set_income();
    void create_bank_account();
    void view_financial_summary();
    void pay_bill();
    void pay_debt();
    void payoff_bill();
    void payoff_debt();
    void add_bill();
    void add_debt();
    void logout_and_exit();

private:
    User user;
};