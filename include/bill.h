#pragma once

#include <string>
class Bill
{
public:
    Bill(double amount, const std::string &due_date);
    double get_amount() const;
    std::string get_due_date() const;
    std::string get_description() const;
    std::string get_category() const;
    void set_description(const std::string &desc);
    void set_category(const std::string &cat);
    void get_bill_details() const;
    bool get_is_paid() const;

private:
    double amount;
    std::string due_date;
    std::string description;
    std::string category;
    bool is_paid = false;
};
