#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
using namespace std;
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
    static bool validateBalance(double balance) {}
    static bool validateSalary(double salary) {}
    static bool validateAmount(double amount) {}
};

#endif // VALIDATION_H
