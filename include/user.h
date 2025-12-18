#pragma once
#include "bill.h"
#include "debt.h"
#include "account.h"
#include <fstream>
#include <vector>
#include <string>

class User
{
public:
    User(const std::string &username, const std::string &password);
    // ~User();
    std::string get_username() const;
    void set_username(const std::string &username);
    void login();
    void logout();
    void set_income(double income);
    double get_income() const;
    void create_bank_account(double initial_balance, std::string account_name);
    const std::vector<Account> &get_bank_accounts() const;
    const Account &get_account(int bank_account) const;
    int get_id() const;
    void set_id(int id);
    std::string get_password() const;

    // bills and debts
    void add_bill(const Bill &bill);
    void add_debt(const Debt &debt);
    const std::vector<Bill> &get_bills() const;
    const std::vector<Debt> &get_debts() const;
    double calculate_total_monthly_bills() const;
    double calculate_total_monthly_debts() const;
    void pay_debt(int index, double amount, int bank_account);
    void pay_bill(int index, double amount, int bank_account);
    void payoff_bill(int index, int bank_account);
    void payoff_debt(int index, int bank_account);

private:
    std::vector<Account> bank_accounts;
    std::vector<Debt> debts;
    std::vector<Bill> bills;
    std::string username;
    std::string password;
    bool is_logged_in;
    double income;
    int id;
};