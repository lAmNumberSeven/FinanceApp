#include "account_menu.h"
void AccountMenu::display_menu(User user)
{
    /** @todo fix failed login bug
     * bug where if user fails to login, user will not have any
     * corresponding data
     */
    system("cls");
    this->user = user;
    std::cout << "Welcome " << user.get_username() << std::endl;
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
        break;
    case 4:
        set_income();
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
        else
        {
            back_to_menu();
        }
    }
    else
    {
        std::vector<Account> accounts = user.get_bank_accounts();
        for (auto account : accounts)
        {
            account.get_account_details();
        }
        back_to_menu();
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
        back_to_menu();
    }
    else
    {
        int account_selection = account_choice();

        double amount;
        printf("Enter amount to deposit: ");
        std::cin >> amount;

        Account *account = (Account *)&user.get_bank_accounts().at(account_selection);
        account->deposit(amount);

        printf("Deposited %.2f into your account.\n", amount);
        printf("Current Balance: %.2f\n", account->get_balance());
    }
    back_to_menu();
}

void AccountMenu::withdraw_funds()
{
    system("cls");
    printf("Withdraw Funds Selected.\n");

    printf("Choose what account to withdraw from: \n");
    int account_selection = account_choice();
    Account *account = (Account *)&user.get_bank_accounts().at(account_selection);

    system("cls");
    printf("Current Balance: %.2f\n", account->get_balance());

    double amount;
    printf("Enter amount to withdraw: ");
    std::cin >> amount;
    account->withdraw(amount);

    printf("Withdrew %.2f from your account.\n", amount);
    printf("Current Balance: %.2f\n", account->get_balance());

    user.store_change(account_selection);

    back_to_menu();
}

void AccountMenu::set_income()
{
    system("cls");
    printf("Set Income Selected.\n");

    printf("1. Hourly 2. Yearly? Please Pick Format For Income: ");
    int choice;
    std::cin >> choice;

    printf("Please Enter Income: ");
    double amount;
    std::cin >> amount;

    user.set_income(amount);

    if (choice == 1)
    {
        user.set_income(amount * 40 * 52);
    }
    else
    {
        user.set_income(amount);
    }
    printf("Income has been set to %.2f.\n", amount);
    printf("Current Income: %.2f\n", user.get_income());

    back_to_menu();
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
    printf("Press 1 to View to New Account");
    int input;
    std::cin >> input;
    if (input == 1)
    {
        user.get_bank_accounts();
    }
    back_to_menu();
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
    printf("Pay Bill Selected.\n");

    int bill_choice = user.bill_choice();
    int user_account_choice = account_choice();
    Bill bill = user.get_bills().at(bill_choice);

    user.pay_bill(bill_choice, bill.get_amount(), user_account_choice);
}

void AccountMenu::pay_debt()
{
    system("cls");
    printf("Pay Debt Selected\n");

    int debt_choice = user.debt_choice();
    int user_account_choice = account_choice();
    Debt debt = user.get_debts().at(debt_choice);

    user.pay_debt(debt_choice, debt.get_monthly_payment(), user_account_choice);
    // add info about payment (reciepts)
}

void AccountMenu::payoff_bill() {}
void AccountMenu::payoff_debt() {}
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

void AccountMenu::back_to_menu()
{
    printf("Continue Back To Menu? (y/n):");
    char response;
    std::cin >> response;
    if (response == 'y' || response == 'Y')
    {
        display_menu(this->user); // idk if this is the best way to implement
    }
    else
    {
        printf("Press any button to exit.\n");
        std::cin.ignore();
        std::cin.get();
        exit(0);
    }
}

int AccountMenu::account_choice() const
{
    if (user.get_bank_accounts().empty())
    {
        printf("No bank accounts found to withdraw from.\n");
        return -1;
    }

    printf("Found %zu bank account(s).\n", user.get_bank_accounts().size());
    for (int i = 0; i < user.get_bank_accounts().size(); i++)
    {
        Account account = user.get_bank_accounts().at(i);
        std::cout << i << ". " << account.get_name()
                  << std::endl;
    }
    printf("choose an account to contiue into: ");
    int chosen_account;
    std::cin >> chosen_account;
    return chosen_account;
}