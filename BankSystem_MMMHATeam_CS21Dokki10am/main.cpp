#include <iostream>
using namespace std;
#include "Client.h"
#include "Admin.h"
int Client:: countClients = 0;
int Employee::countEmployees = 0;
int Admin::countAdmins = 0;


int main() {
    // *************** Testing of Phase 1 ***************

    // Test 1: Creating and displaying a Client object Testing Validation (name, password, phoneNumber, balance)\n"
    cout << "Test 1: Creating and displaying a Client object\nTesting Validation (name,password, phoneNumber,balance):\n";
    Client client1(1, "Ali", "StrongPass123456789101215", "34567890", 200.0);
    cout << "Client 1 Details:\n";
    client1.display();
    system("pause");
    cout << "==================================================================\n";

    // Test 2: Checking balance
    cout << "Test 2: Checking balance:\n";
    client1.checkBalance();
    cout << "==================================================================\n";
    system("pause");
    cout << "==================================================================\n";

    // Test 3: Depositing money
    cout << "Test 3: Depositing money:\n";
    cout << "Depositing 500 into Client 1's account.\n";
    client1.deposite(500);
    system("pause");
    cout << "==================================================================\n";

    // Test 4: Withdrawing money
    cout << "Test 4: Withdrawing money:\n";
    cout << "Withdrawing 1000 from Client 1's account.\n";
    client1.withdraw(1000);
    system("pause");
    cout << "==================================================================\n";

    // Test 5: Transferring money between Clients
    cout << "Test 5: Transferring money between Clients (Amount Validation):\n";
    Client client2(2, "Bob Smith", "AnotherPass123", "09876543210", 3000.0);
    cout << "Transferring 500 from Client 1 to Client 2.\n";
    client1.transferTo(client2, 50); // Validation of amount
    cout << "Checking the balance of both accounts after the transferTo: \n";
    client1.checkBalance();
    client2.checkBalance();
    cout << "==================================================================\n";
    system("pause");
    cout << "==================================================================\n";

    // Test 6: Creating and displaying an Employee object
    cout << "Test 6: Creating and displaying an Employee object:\n";
    Employee employee1(1, "John Doe", "EmpPass123", "01122334455", 6000.0);
    cout << "Employee 1 Details:\n";
    employee1.display();
    system("pause");
    cout << "==================================================================\n";

    // Test 7: Checking salary
    cout << "Test 7: Checking salary:\n";
    cout << "Employee's Salary: " << employee1.getSalary() << endl;
    cout << "==================================================================\n";
    system("pause");
    cout << "==================================================================\n";

    // Test 8: Creating and displaying an Admin object
    cout << "Test 8: Creating and displaying an Admin object:\n";
    Admin admin1(1, "Admin Jane", "AdminPass123", "07788990011", 10000.0);
    cout << "Admin 1 Details:\n";
    admin1.display();
    system("pause");
    cout << "==================================================================\n";

    // Test 9: Checking salary
    cout << "Test 9: Checking salary:\n";
    cout << "Admin's Salary: " << admin1.getSalary() << endl;
    cout << "==================================================================\n";
    system("pause");
    cout << "==================================================================\n";

    // Test 10: Summary of counts
    cout << "Test 10: Summary of counts:\n";
    cout << "Total Clients: " << Client::countClients << endl;
    cout << "Total Employees: " << Employee::countEmployees << endl;
    cout << "Total Admins: " << Admin::countAdmins << endl;
    cout << "==================================================================\n";
    return 0;
}
