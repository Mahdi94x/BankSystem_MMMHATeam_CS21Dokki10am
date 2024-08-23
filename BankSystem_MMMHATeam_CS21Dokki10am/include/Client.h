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
    //Constructors:
    Client() {}
    Client(int id, string name, string password, double balance) {}

    //Setters:
    void setBalance(double balance) {}

    //Getters:
    double getBalance() {}

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
