#include "account.h"
#include <cstdio>

Account::Account(double initial_balance, std::string account_name) : balance(initial_balance), account_name(account_name) {}
// Account::~Account() {}
void Account::deposit(double amount)
{
    if (amount < 0)
    {
        printf("Deposit amount must be positive.\n");
        return;
    }
    else
    {
        balance += amount;
    }
}
void Account::withdraw(double amount)
{
    if (amount > balance)
    {
        // Handle insufficient funds scenario
        // is_negative_balance = true;
        printf("Insufficient funds for withdrawal of %.2f\n", amount);
        return;
    }
    else
    {
        balance -= amount;
        printf("Current balance after withdraw: %.2f", balance);
    }
}

double Account::get_balance() const
{
    return balance;
}

double Account::get_income_vs_expense() const
{
    return income_vs_expense;
}

void Account::get_account_details()
{
    std::cout << "Account: " << this->account_name << std::endl;
    printf("Account Balance: %.2f\n", balance);
    printf("Income vs Expense: %.2f\n", income_vs_expense);
}

std::string Account::get_name()
{
    return account_name;
}