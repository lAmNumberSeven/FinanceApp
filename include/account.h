#pragma once

class Account
{
public:
    Account(double initial_balance);
    // ~Account();

    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    double get_income_vs_expense() const;
    void get_account_details();

private:
    double balance;
    double income_vs_expense;
    bool is_negative_balance;
};