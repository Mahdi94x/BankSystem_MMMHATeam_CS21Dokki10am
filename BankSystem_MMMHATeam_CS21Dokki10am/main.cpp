#include <iostream>
using namespace std;
#include "Client.h"
#include "Admin.h"
int Client:: countClients = 0;
int Employee::countEmployees = 0;
int Admin::countAdmins = 0;


int main() {
    // Test 1: Creating and displaying a Client object =>
    // Testing Validation (name,password, phoneNumber,balance)
    cout << "Test 1:\n";
    Client client1(1, "Ali", "StrongPass123456789101215", "34567890", 200.0);
    cout << "Client 1 Details:\n";
    client1.display();

    // Test 2: Checking balance
    cout << "Test 2:\n";
    client1.checkBalance();
    cout << "==================================================================\n";

    // Test 3: Depositing money
    cout << "Test 3:\n";
    cout << "Depositing 500 into Client 1's account.\n";
    client1.deposite(500);

    // Test 4: Withdrawing money
    cout << "Test 4:\n";
    cout << "Withdrawing 1000 from Client 1's account.\n";
    client1.withdraw(1000);

    // Test 5: Transferring money between Clients
    cout << "Test 5:\n";
    Client client2(2, "Bob Smith", "AnotherPass123", "09876543210", 3000.0);
    cout << "Transferring 500 from Client 1 to Client 2.\n";
    client1.transferTo(client2, 50); // Validation of amount
    cout << "Checking the balance of both accounts after the transferTo: \n";
    client1.checkBalance();
    client2.checkBalance();
    cout << "==================================================================\n";

    // Test 6: Creating and displaying an Employee object
    cout << "Test 6:\n";
    Employee employee1(1, "John Doe", "EmpPass123", "01122334455", 6000.0);
    cout << "Employee 1 Details:\n";
    employee1.display();

    // Test 7: Checking salary
    cout << "Test 7:\n";
    cout << "Employee's Salary: " << employee1.getSalary() << endl;
    cout << "==================================================================\n";

    // Test 8: Creating and displaying an Admin object
    cout << "Test 8:\n";
    Admin admin1(1, "Admin Jane", "AdminPass123", "07788990011", 10000.0);
    cout << "Admin 1 Details:\n";
    admin1.display();

    // Test 9: Checking salary
    cout << "Test 9:\n";
    cout << "Admin's Salary: " << admin1.getSalary() << endl;
    cout << "==================================================================\n";

    // Summary of counts
    cout << "Summary:\n";
    cout << "Total Clients: " << Client::countClients << endl;
    cout << "Total Employees: " << Employee::countEmployees << endl;
    cout << "Total Admins: " << Admin::countAdmins << endl;

    return 0;
}
