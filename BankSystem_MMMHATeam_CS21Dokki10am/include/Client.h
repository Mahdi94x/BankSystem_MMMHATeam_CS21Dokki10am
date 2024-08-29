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
