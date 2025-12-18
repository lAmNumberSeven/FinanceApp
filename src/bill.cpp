#include "bill.h"
#include <cstdio>
Bill::Bill(double amount, const std::string &due_date)
    : amount(amount), due_date(due_date), description(""), category("") {}
double Bill::get_amount() const
{
    return amount;
}
std::string Bill::get_due_date() const
{
    return due_date;
}
std::string Bill::get_description() const
{
    return description;
}
std::string Bill::get_category() const
{
    return category;
}
void Bill::set_description(const std::string &desc)
{
    description = desc;
}
void Bill::set_category(const std::string &cat)
{
    category = cat;
}
void Bill::get_bill_details() const
{
    printf("Bill Details:\n");
    printf("Amount: %.2f\n", amount);
    printf("Due Date: %s\n", due_date.c_str());
    printf("Description: %s\n", description.c_str());
    printf("Category: %s\n", category.c_str());
}