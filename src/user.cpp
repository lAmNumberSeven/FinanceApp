#include "user.h"
User::User(const std::string &username, const std::string &password)
    : username(username), password(password), is_logged_in(false), income(0.0)
{
    // Load info from txt and set to user when log-in
    std::ifstream file("accounts.txt");
    if (file.is_open())
    {

        std::string line;
        while (std::getline(file, line))
        {
            size_t delimiter_pos = line.find(',');
            if (delimiter_pos != std::string::npos)
            {
                std::string username = line.substr(0, delimiter_pos);
                if (username == get_username()) // check that account is users
                {
                    size_t second_delimiter_pos = line.find(',', delimiter_pos + 1);
                    std::string account_name = line.substr(delimiter_pos + 1, second_delimiter_pos - delimiter_pos - 1);
                    double balance = std::stod(line.substr(second_delimiter_pos + 1));
                    Account account = {balance, account_name};
                    bank_accounts.push_back(account);
                }
            }
        }
        file.close();
    }
}
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
    Account new_account(initial_balance, account_name);
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

int User::bill_choice() const
{
    if (bills.empty())
    {
        printf("Found NO bills\n");
        return -1;
    }
    printf("Found %zu bills.\n", bills.size());
    for (int i = 0; i < bills.size(); i++)
    {
        std::cout << i << ". " << bills.at(i).get_amount() << std::endl;
    }
    printf("Choose a bill: ");
    int choice;
    std::cin >> choice;
    return choice;
}

int User::debt_choice() const
{
    if (debts.empty())
    {
        printf("Found NO debts.\n");
        return -1;
    }
    printf("Found %zu debts.\n", debts.size());
    for (int i = 0; i < debts.size(); i++)
    {
        std::cout << i << ". " << debts.at(i).get_name() << std::endl;
    }
    printf("Choose a debt: ");
    int choice;
    std::cin >> choice;
    return choice;
}

std::string User::get_line(int line_number, const std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    int cur_line = 1;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {

            if (cur_line == line_number)
            {
                file.close();
                return line;
            }
        }
        printf("Could NOT find line number.\n");
        file.close();
    }
    else
    {
        std::cout << "Error opening file: " << file_name << std::endl;
    }
    return "";
}

void User::store_change(int id)
{
    double current_balance = get_account(id).get_balance();
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << current_balance;
    std::string new_balance = stream.str();

    std::string line = get_line(id + 1, "accounts.txt");
    size_t delimiter = line.find(',');
    size_t second_delimiter = line.find(',', delimiter + 1);
    std::string old_balance = line.substr(second_delimiter + 1);

    std::ifstream file_in("accounts.txt");
    if (!file_in)
    {
        printf("Could not open accounts.txt");
    }

    std::stringstream buffer;
    buffer << file_in.rdbuf();
    file_in.close();
    std::string file_contents = buffer.str();

    size_t pos = 0;
    while ((pos = file_contents.find(old_balance, pos)) != std::string::npos)
    {
        file_contents.replace(pos, old_balance.length(), new_balance);
        pos += new_balance.length();
    }

    std::ofstream file_out("accounts.txt", std::ios::trunc);
    if (!file_out)
    {
        printf("file cannot be opened.\n");
    }

    file_out << file_contents;
    file_out.close();
}