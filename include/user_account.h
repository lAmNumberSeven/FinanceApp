#pragma once
#include "bill.h"
#include "account.h"
#include "debt.h"
#include <string>
#include <vector>
class UserBankAccount : public Account
{
public:
    UserBankAccount(double initial_balance);
    // ~UserBankAccount();
    void get_financial_summary() const;
    void get_user_bank_account_details() const;

private:
    std::vector<Bill> bills;
    std::vector<Debt> debts;
};