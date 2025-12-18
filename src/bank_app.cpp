#include "bank_app.h"
#include <ctime>
#include <chrono>
#include <thread>

BankApp::BankApp()
{
    // Constructor implementation (if needed)
    // printf("Welcome to the Bank Application!\n");
    // while (true)
    // {
    //     auto now = std::chrono::system_clock::now();
    //     std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    //     printf("Current Date and Time: %s", std::ctime(&current_time));
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
}
void BankApp::run(Users users)
{
    IntroMenu intro_menu(users);
    intro_menu.display_menu(users);
}