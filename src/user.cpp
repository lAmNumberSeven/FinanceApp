#include "user.h"
User::User(const std::string &username, const std::string &password)
    : username(username), password(password), is_logged_in(false), income(0.0) {}
// User::~User() {}
std::string User::get_username() const
{
    return username;
}

void User::set_username(const std::string &username)
{
    this->username = username;
}

void User::login()
{
    is_logged_in = true;

    printf("User %s logged in.\n", username.c_str());
}
void User::logout()
{
    is_logged_in = false;
    printf("User %s logged out.\n", username.c_str());
}
void User::set_income(double income)
{
    this->income = income;
}
double User::get_income() const
{
    return income;
}
void User::create_bank_account(double initial_balance, std::string account_name)
{
    Account new_account(initial_balance);
    bank_accounts.push_back(new_account);
    printf("Bank account '%s' created for user %s with initial balance %.2f\n",
           account_name.c_str(), username.c_str(), initial_balance);

    // save account to file
    std::ofstream file("accounts.txt", std::ios::app);
    if (file.is_open())
    {
        file << username << "," << account_name << "," << initial_balance << "\n";
        file.close();
    }
}
void User::set_id(int id)
{
    this->id = id;
}
int User::get_id() const
{
    return id;
}
std::string User::get_password() const
{
    return password;
}
const std::vector<Account> &User::get_bank_accounts() const
{
    return bank_accounts;
}

const Account &User::get_account(int bank_account) const
{
    return bank_accounts[bank_account];
}

void User::add_bill(const Bill &bill)
{
    bills.push_back(bill);
}
void User::add_debt(const Debt &debt)
{
    debts.push_back(debt);
}
const std::vector<Bill> &User::get_bills() const
{
    return bills;
}

const std::vector<Debt> &User::get_debts() const
{
    return debts;
}

double User::calculate_total_monthly_bills() const
{
    double total = 0.0;
    for (const auto &bill : bills)
    {
        total += bill.get_amount();
    }
    return total;
}

double User::calculate_total_monthly_debts() const
{
    double total = 0.0;
    for (const auto &debt : debts)
    {
        total += debt.get_monthly_payment();
    }
    return total;
}

void User::pay_debt(int index, double amount, int bank_account)
{

    if (index < 0 || index >= debts.size())
    {
        printf("Invalid debt index.\n");
        return;
    }
    Debt &debt = debts[index];
    double monthly_payment = debt.get_monthly_payment();
    if (amount < monthly_payment)
    {
        printf("Payment amount is less than the monthly payment of %.2f\n", monthly_payment);
    }
    Account account = this->get_account(bank_account);
    account.withdraw(amount);
}

void User::pay_bill(int index, double amount, int bank_account)
{
    if (index < 0 || index >= bills.size())
    {
        printf("Invalid Bill index.\n");
        return;
    }
    Bill &bill = bills[index];
    double bill_payment = bill.get_amount();
    if (amount < bill_payment)
    {
        printf("Payment amount is less than the bill amount of %.2f\n", bill_payment);
        return;
    }
    Account account = this->get_account(bank_account);
    account.withdraw(amount);
}

void User::payoff_bill(int index, int bank_account)
{
    if (index < 0 || index >= bills.size())
    {
        printf("Invalid bill index.\n");
        return;
    }
    Bill &bill = bills[index];
    double bill_amount = bill.get_amount();

    Account account = this->get_account(bank_account);
    account.withdraw(bill_amount);
    printf("Paid off bill due on: %s\n", bill.get_due_date().c_str());
}

void User::payoff_debt(int index, int bank_account)
{
    if (index < 0 || index >= debts.size())
    {
        printf("Invalid debt index.\n");
        return;
    }

    Debt &debt = debts[index];
    double debt_amount = debt.get_monthly_payment();

    Account account = this->get_account(bank_account);
    account.withdraw(debt_amount);
    // printf("Paid off debt due on: %s \n", debt.get_name());
    debt.get_debt_details();
}