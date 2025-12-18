#pragma once
#include "intro_menu.h"
#include "users.h"
#include "account_menu.h"

class BankApp
{
public:
    BankApp();

    void run(Users users);

private:
    Users users;
};