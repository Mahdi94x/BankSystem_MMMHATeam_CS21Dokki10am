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
            cout << "Attemp => (" << attempt << "/" << maxattempts << ")" << " Enter the modified balance : ";
            cin >> balance;
            // Clear the input buffer to avoid issues with getline or other input methods.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (Validation::validateBalance(balance)) {
            this->balance = balance;
        }
        else {
            cout << "Max Attemps have been reached! => Setting balance to default value\n";
            cout << "Kindly Contact our support ASAP\n";
            this->balance = 0;
        }
}

    // Methods:
    void withdraw(double amount) {}

    void deposite(double amount) {}
    }

    void transferTo(Client& recipient, double amount) {}
    }

    void checkBalance() {}

    void display() {}

};

#endif // CLIENT_H
