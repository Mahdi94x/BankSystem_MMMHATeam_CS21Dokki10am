#pragma once
#include "Person.h"
#include "Client.h"
#include "Vectors.h"
//#include "FileHelper.h"
#include "FileManager.h"

class ClientManager
{
public:
    static int printClientMenu() {
        cout << "Please choose one of the following options:" << endl;
        cout << "1.  Deposit" << endl;
        cout << "2.  Withdraw" << endl;
        cout << "3.  Transfer to" << endl;
        cout << "4.  Display Information" << endl;
        cout << "5.  Update Password" << endl;
        cout << "6.  Check Balance" << endl;
        cout << "7.  Exit" << endl;

        int choice;
        cout << "Please, Choose an Option: ";
        cin >> choice;
        return choice;
    }

    static void updatePassword(Person* p) {
        string password;
        cout << "Please, enter your new password: ";
        cin >> password;
        p->setPassword(password);
        cout << "Password updated successfully!" << endl;
        FileManager fm;
        fm.exportAllClients();
        fm.exportAllEmployees();
        fm.exportAllAdmins();
    }

    static Client* login(int id, string password) {
        for (Client& c : clientsVector) {
            if (c.getID() == id && c.getPassword() == password) {
                return &c;
            }
        }
        cout << "Invalid ID or Password!" << endl;
        return nullptr;
    }

    static bool clientOptions(Client* c, int choice) {

        Client* receiver = nullptr;

        switch (choice) {
        case 1:
            double amount1;
            cout << "Enter the amount you want to deposit: ";
            cin >> amount1;
            c->deposite(amount1);
            break;

        case 2:
            double amount2;
            cout << "Enter the amount you want to withdraw: ";
            cin >> amount2;
            c->withdraw(amount2);
            break;

        case 3:
            int id;
            cout << "Enter the ID of the client you want to transfer to: ";
            cin >> id;
            for (Client& c : clientsVector) {
                if (c.getID() == id) {
                    receiver = &c;
                    break;
                }
            }
            if (receiver == nullptr) {
                cout << "Client not found!" << endl;
                break;
            }
            double amount3;
            cout << "Enter the amount you want to transfer: ";
            cin >> amount3;
            if (c != nullptr) {
                c->transferTo(*receiver, amount3);
            }
            else {
                cout << "Sender not available!" << endl;
            }
            break;

        case 4:
            c->display();
            break;

        case 5:
            updatePassword(c);
            break;

        case 6:
            c->checkBalance();
            break;

        case 7:
            return false;

        default:
            cout << "Invalid choice! Please choose a number between 1 and 7." << endl;
        }
        return true;
    }
};
