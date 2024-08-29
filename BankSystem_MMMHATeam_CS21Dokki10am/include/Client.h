#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;
#include "Person.h"

class Client : public Person
{
private:

	//Attributes:
	double balance;

	//Private Methods: // Team Effort
    void acceptedTransaction() {
        cout << "Processing...\nTransaction is completed.\n";
        checkBalance();
        cout <<"Time of Transaction => " << getCurrentTime() << endl;
        cout << "==================================================================\n";
}

    void declinedTransaction() {
        cout << "Processing...\nTransaction is declined. Please contact the bank for more information.\n";
        checkBalance();
        cout << "Time of Transaction => " << getCurrentTime() << endl;
        cout << "==================================================================\n";
}

    double updatingAmount(double amount){
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
	return amount;
}

    void declinedAmount() {
        cout << "Apologies! The amount you entered does not meet the requirements!\n";
        declinedTransaction();
}

public:
    //Attributes: //Hadeer
    static int countClients;

    //Constructors: // Hadeer
    Client() {
        this->balance = 0;
        countClients++;
}
    Client(string id, string name, string password): Person (id,name,password) {
        this->balance = 0;
        countClients++;
}
    Client(string id, string name, string password, string phonenumber, double balance):Person (id,name,password, phonenumber) {
        setBalance(balance); // this->balance = balance;
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
            cout << "Thank you for providing the modified balance.\n";
            this->balance = balance;
        }
        else {
            cout << "Max Attempts have been reached! => Setting balance to default value\n";
            cout << "Kindly Contact our support ASAP\n";
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
    void withdraw(double amount) { // Mahdi
        amount = updatingAmount(amount);
        if (Validation::validateAmount(amount)) {
            if (amount > balance) {
                declinedTransaction();
            }
            else {
                cout << "Thank you for providing the modified amount.\n";
                this->balance -= amount;
                acceptedTransaction();
            }
        }
        else {
            declinedAmount();
        }
}

    void deposite(double amount) { // Mostafa
        amount = updatingAmount(amount);
        if (Validation::validateAmount(amount)) {
            cout << "Thank you for providing the modified amount.\n";
            this->balance += amount;
            acceptedTransaction();
        }
        else {
            declinedAmount();
        }
}

    void transferTo(Client& recipient, double amount){ // Mahdi
        amount = updatingAmount(amount);
        if (Validation::validateAmount(amount)) {
            if (amount > balance) {
                declinedTransaction();
            }
            else {
                cout << "Thank you for providing the modified amount.\n";
                this->balance -= amount;
                recipient.balance += amount;
                acceptedTransaction();
            }
        }
        else {
            declinedAmount();
        }
}

    void display() { // Mostafa
        cout << "Name:         " << getName() << endl;
        cout << "ID:           " << getID() << endl;
        cout << "Password:     " << getPassword() << endl;
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Balance:      " << getBalance() << endl;
        cout << "======================================\n";
}

};

#endif // CLIENT_H
