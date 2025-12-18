#include "debt.h"
#include <cstdio>
#include <cmath>
Debt::Debt(double amount, double interest_rate, int term_months)
    : principal(amount), interest_rate(interest_rate), term_months(term_months) {}
// Debt::~Debt() {}
double Debt::get_monthly_payment() const
{
    double monthly_rate = interest_rate / 12.0 / 100.0;
    double denominator = 1 - pow(1 + monthly_rate, -term_months);
    return (principal * monthly_rate) / denominator;
}
double Debt::get_total_payment() const
{
    return get_monthly_payment() * term_months;
}
void Debt::get_debt_details() const
{
    printf("Debt Details:\n");
    printf("Name: %s\n", name.c_str());
    printf("Principal: %.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", interest_rate);
    printf("Term (months): %d\n", term_months);
    printf("Monthly Payment: %.2f\n", get_monthly_payment());
    printf("Total Payment: %.2f\n", get_total_payment());
}

void Debt::set_name(std::string name)
{
    this->name = name;
}

std::string Debt::get_name() const
{
    return name;
}