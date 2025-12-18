#include "account_menu.h"
void AccountMenu::display_menu(User user)
{
    this->user = user;
    printf("Account Menu:\n");
    printf("1. View Account Details\n");
    printf("2. Deposit Funds\n");
    printf("3. Withdraw Funds\n");
    printf("4. Set Income\n");
    printf("5. Create Bank Account\n");
    printf("6. View Financial Summary\n");
    printf("7. Pay Bill\n");
    printf("8. Pay Debt\n");
    printf("9. Payoff Bill\n");
    printf("10. Payoff Debt\n");
    printf("11. Add Bill\n");
    printf("12. Add Debt\n");
    printf("13. Log out and Exit\n");
    printf("Please enter an option: ");
    int choice;
    std::cin >> choice;
    while (choice != 13)
    {
        handle_user_selection(choice);
    }
}
void AccountMenu::handle_user_selection(int choice)
{

    switch (choice)
    {
    case 1:
        view_account_details();
        break;
    case 2:
        deposit_funds();
        break;
    case 3:
        withdraw_funds();
        // Implement withdraw funds logic here
        break;
    case 4:
        set_income();
        // Implement exit to main menu logic here
        break;
    case 5:
        create_bank_account();
    case 6:
        view_financial_summary();
    case 7:
        pay_bill();
    case 8:
        pay_debt();
    case 9:
        payoff_bill();
    case 10:
        payoff_debt();
    case 11:
        add_bill();
    case 12:
        add_debt();
    case 13:
        logout_and_exit();
    default:
        printf("Invalid choice. Please try again.\n");
        display_menu(user);
        break;
    }
}

AccountMenu::AccountMenu(User user) : user(user)
{
    printf("Welcome, %s!\n", user.get_username().c_str());
}

void AccountMenu::view_account_details()
{
    system("cls");
    printf("View Account Details selected.\n");
    // Implement view account details logic here
    if (user.get_bank_accounts().empty())
    {
        printf("No bank accounts found.\n");
        printf("Create a bank account? (y/n): ");
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y')
        {
            double initial_balance;
            std::string account_name;
            printf("Enter initial balance for the new account: ");
            std::cin >> initial_balance;
            printf("Enter a name for the new account: ");
            std::cin >> account_name;
            user.create_bank_account(initial_balance, account_name);
        }
    }
    else
    {
        view_financial_summary();
    }
}

void AccountMenu::deposit_funds()
{
    system("cls");
    printf("Deposit Funds selected.\n");
    // Implement deposit funds logic here
    if (user.get_bank_accounts().empty())
    {
        printf("No bank accounts found to deposit into.\n");
    }
    else
    {
        printf("Found %zu bank account(s).\n", user.get_bank_accounts().size());
        printf("choose an account to deposit into: \n");
        int chosen_account;
        std::cin >> chosen_account;

        double amount;
        printf("Enter amount to deposit: ");
        std::cin >> amount;

        Account *account = (Account *)&user.get_bank_accounts().at(chosen_account);
        account->deposit(amount);

        printf("Deposited %.2f into your account.\n", amount);
        printf("Current Balance: %.2f", account->get_balance());
    }
}

void AccountMenu::withdraw_funds()
{
    system("cls");
    printf("Withdraw Funds Selected.\n");

    printf("Choose what account to withdraw from: \n");
    int chosen_account;
    std::cin >> chosen_account;
    if (user.get_bank_accounts().empty())
    {
        printf("No bank accounts found to withdraw from.\n");
        return;
    }
    if (chosen_account >= user.get_bank_accounts().size() || chosen_account < 0)
    {
        printf("Invalid account selection.\n");
        return;
    }
    double amount;
    printf("Enter amount to withdraw: ");
    std::cin >> amount;
    Account *account = (Account *)&user.get_bank_accounts().at(chosen_account);
    account->withdraw(amount);
    printf("Withdrew %.2f from your account.\n", amount);
    printf("Current Balance: %.2f", account->get_balance());
}

void AccountMenu::set_income()
{
    system("cls");
    printf("Set Income Selected.\n");
    double amount;
    std::cin >> amount;
    user.set_income(amount);
    printf("Income has been set to %.2f.", amount);
    printf("Current Income: %.2f", user.get_income());
}

void AccountMenu::create_bank_account()
{
    system("cls");
    printf("Create Bank Account Selected.\n");
    printf("Enter Initial Balance: ");
    double balance;
    std::cin >> balance;

    printf("Enter Account Name: ");
    std::string account_name;
    std::cin >> account_name;
    user.create_bank_account(balance, account_name);

    printf("Account Create!\n");
    user.get_bank_accounts();
}

void AccountMenu::view_financial_summary()
{
    system("cls");
    printf("Financial Summary:\n");
    printf("Current Income: %.2f\n", user.get_income());
    printf("Bank Accounts Info: \n ");
    for (auto account : user.get_bank_accounts())
    {
        account.get_account_details();
    }

    printf("Bills: \n");
    for (const auto bill : user.get_bills())
    {
        bill.get_bill_details();
    }

    printf("Debts: \n");
    for (const auto debt : user.get_debts())
    {
        debt.get_debt_details();
    }
}

void AccountMenu::pay_bill()
{
    system("cls");
    printf("Pay Bill:\n");

    printf("Select Which Bill To Pay: ");
}

void AccountMenu::pay_debt()
{
    system("cls");
    printf("Pay Debt:\n");
}

void AccountMenu::add_bill()
{
    system("cls");
    printf("Add Bill: \n");
}

void AccountMenu::add_debt()
{
    system("cls");
    printf("Add Debt:");
}
void AccountMenu::logout_and_exit()
{
    printf("Logging out and exiting.\n");
    // Implement exit to main menu logic here

    exit(0);
}