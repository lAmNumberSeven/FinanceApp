#pragma once
#include <string>
#include <iostream>
class Account
{
public:
    Account(double initial_balance, std::string account_name);
    // ~Account();

    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    double get_income_vs_expense() const;
    void get_account_details();
    std::string get_name();

private:
    double balance;
    double income_vs_expense;
    bool is_negative_balance = false; // maybe remove this
    std::string account_name;
};