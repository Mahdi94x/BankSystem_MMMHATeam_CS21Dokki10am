#pragma once

#include "Person.h"
#include "Validation.h"
#include <vector>
#include <iterator>
using namespace std;

class Client : public Person
{
private:

	//Attributes:
	double balance;

	//Private Methods: // Team Effort
	void acceptedTransaction() {
		cout << "Processing...\nTransaction is completed.\n";
		checkBalance();
		cout << "Time of Transaction => " << getCurrentTime() << endl;
		cout << "==================================================================\n";
	}

	void declinedTransaction() {
		cout << "Processing...\nTransaction is declined. Kindly Contact our support ASAP for more information.\n";
		checkBalance();
		cout << "Time of Transaction => " << getCurrentTime() << endl;
		cout << "==================================================================\n";
	}

	double updatingAmount(double amount) {
		int attempt{};
		const int maxattempts{ 3 };
		while (!(Validation::validateAmount(amount)) && attempt < maxattempts) {
			cout << "Apologies! Invalid Amount. The Amount must be equal to or higher than 100.\n";
			attempt++;
			cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified amount : ";
			cin >> amount;
			// Clear the input buffer to avoid issues with getline or other input methods.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (attempt != 0) {
			cout << "Thank you for providing the modified amount.\n";
		}
		return amount;
	}

	bool isActive() { // Mahdi
		if (Validation::isAccountActive(getName(), getPassword(), getPhoneNumber(), getBalance(), true)) {
			return true;
		}
		else {
			cout << "Account is frozen. Kindly Contact our support ASAP for more information.\n";
			return false;
		}
	}

	void declinedAmount() {
		cout << "Apologies! The amount you entered does not meet the requirements!\n";
		declinedTransaction();
	}


public:
	//Attributes: //Hadeer
	static int countClients;

	//Constructors: // Hadeer
	Client() :Person() {
		this->balance = 0;
		countClients++;
	}
	Client(int id, string name, string password) : Person(id, name, password) {
		this->balance = 0;
		countClients++;
	}
	Client(int id, string name, string password, string phonenumber, double balance) :Person(id, name, password, phonenumber) {
		setBalance(balance);
		countClients++;
	}

	//Setters: // Helal
	void setBalance(double balance) {
		int attempt{};
		const int maxattempts{ 3 };
		while (!(Validation::validateBalance(balance)) && attempt < maxattempts) {
			cout << "Apologies! Invalid Balance. The Balance must be equal to or higher than 1500.\n";
			attempt++;
			cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified balance : ";
			cin >> balance;
			// Clear the input buffer to avoid issues with getline or other input methods.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (Validation::validateBalance(balance)) {
			if (attempt != 0) {
				cout << "Thank you for providing the modified balance.\n";
			}
			this->balance = balance;
		}
		else {
			cout << "Max Attempts have been reached! => Setting balance to default value.\n";
			cout << "Kindly Contact our support ASAP.\n";
			this->balance = 0;
		}
	}

	//Getters: // Amira
	double getBalance() {
		return this->balance;
	}

	// Methods:
	void checkBalance() { // Amira
		cout << "Current Balance of Account's ID: " << getID() << " is => " << getBalance() << " EGP." << endl;
	}
	void withdraw(double amount); // Mahdi

	void deposite(double amount); // Mostafa

	void transferTo(Client& recipient, double amount); // Mahdi

	void display() { // Mostafa
		Person::display();
		cout << "Balance:      " << getBalance() << endl;
		cout << "======================================\n";
	}

};
