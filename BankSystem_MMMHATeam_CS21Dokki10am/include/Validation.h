#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
using namespace std;
#include <regex> // Regular expression
#include <string>

class Validation
{
public:
    static bool validateName(string name) { // Mahdi
	if (name.size() >= 5 && name.size() <= 20 && regex_match(name, regex("^[a-zA-Z ]+$")))
		return true;
	else
		return false;
}
    static bool validatePassword(string password) { // Helal
	if (password.size() >= 8 && password.size() <= 20)
		return true;
	else
		return false;
}
    static bool validateBalance(double balance) { // Mostafa
	if (balance >= 1500)
		return true;
	else
		return false;
}
    static bool validateSalary(double salary) { // Hadeer
	if (salary >= 5000)
		return true;
	else
		return false;
}
    static bool validateAmount(double amount) { // Amira
	if (amount >= 100)
		return true;
	else
		return false;
}
    static bool validatePhoneNumber(string phonenumber) { // Mahdi
	if (phonenumber.size() == 11 && regex_match(phonenumber, regex("^[0-9]+$")))
		return true;
	else
		return false;
}
};

#endif // VALIDATION_H
