#include "user_account.h"
#include <cstdio>
UserBankAccount::UserBankAccount(double initial_balance)
    : Account(initial_balance) {}
// UserBankAccount::~UserBankAccount() {}

void UserBankAccount::get_financial_summary() const
{
    printf("Financial Summary:\n");
    // printf("Total Monthly Bills: %.2f\n", calculate_total_monthly_bills());
    // printf("Total Monthly Debts: %.2f\n", calculate_total_monthly_debts());
}
void UserBankAccount::get_user_bank_account_details() const
{
    // get_account_details();
    printf("Number of Bills: %zu\n", bills.size());
    printf("Number of Debts: %zu\n", debts.size());
}
