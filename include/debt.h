#pragma once
#include <string>
class Debt
{
public:
    Debt(double amount, double interest_rate, int term_months);
    // ~Debt();
    double get_monthly_payment() const;
    double get_total_payment() const;
    void get_debt_details() const;
    void set_name(std::string name);
    std::string get_name() const;

private:
    double principal;
    double interest_rate;
    int term_months;
    std::string name;
};