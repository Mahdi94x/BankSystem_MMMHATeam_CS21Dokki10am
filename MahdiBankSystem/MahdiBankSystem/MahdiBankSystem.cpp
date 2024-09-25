/*#include <iostream>
#include "FileHelper.h"
#include "FileManager.h"*/
#include "Screens.h"
//using namespace std;


int main() {

	// *************** Testing of Phase 3 ***************
	Screens::runApp();
	return 0;
}



// *************** Testing of Phase 1 ***************
/*
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


*/

// *************** Testing of Phase 2 ***************
/*
// Test 1: Loading existing clients, employees, and admins from txt files
cout << "Test 1:Loading existing clients, employees, and admins from txt files\n";
cout << "Testing Parser Class and FileHelper Class\n";
FileManager f1;
f1.getAllEmployees();
f1.getAllClients();
f1.getAllAdmins();
cout << "Number of clients: " << clientsVector.size() << endl;
cout << "Number of employees: " << employeesVector.size() << endl;
cout << "Number of admins: " << adminsVector.size() << endl;
cout << "==================================================================\n";
system("pause");
/*
// Test 2: Adding a new Client, Employee, and Admin to the system, vector, and txt file
cout << "Test 2: Adding a new Client, Employee, and Admin to the system, vector, and txt file\n";
cout << "Testing FileHelper Class (ID Section saving and storing)\n";
Client c1(FileHelper::getLastID("ClientLastID.txt"), "Ahmed Mohamed", "ahmed1234", "01234567890", 10000);
f1.addClient(c1);
Employee e1(FileHelper::getLastID("EmployeeLastID.txt"), "Mahmoud Ali", "mahmoud1234", "01122334455", 6000);
f1.addEmployee(e1);
Admin a1(FileHelper::getLastID("AdminLastID.txt"), "Mona Ahmed", "Mona12345", "07788990011", 7000);
f1.addAdmin(a1);
cout << "Latest Client's ID: " << c1.getID() << endl;
cout << "Latest Employee's ID: " << e1.getID() << endl;
cout << "Latest Admin's ID: " << a1.getID() << endl;
cout << "Number of clients: " << clientsVector.size() << endl;
cout << "Number of employees: " << employeesVector.size() << endl;
cout << "Number of admins: " << adminsVector.size() << endl;
// open txt files to check if the new objects are added
cout << "==================================================================\n";
system("pause");

// Test 3: Listing all clients and employees in the system by an Admin
cout << "Test 2: Listing all clients and employees in the system\n";
a1.listClient();
system("pause");
a1.listEmployee();
cout << "==================================================================\n";
system("pause");

// Test 4: Adding new client by Employee and adding new employee by admin
cout << "Test 4: Adding new client by Employee and adding new employee by admin\n";
e1.addClient();
a1.addEmployee();
cout << "Number of clients: " << clientsVector.size() << endl;
cout << "Number of employees: " << employeesVector.size() << endl;
cout << "Number of admins: " << adminsVector.size() << endl;
cout << "==================================================================\n";
system("pause");

// Test 5: Searching for a Client, Employee in the system
cout << "Test 5: Searching for a Client, Employee in the system\n";
Client* temp1 = e1.searchClient(1010);
temp1->display();
cout << "==================================================================\n";
Employee* temp2 = a1.searchEmployee(2005);
temp2->display();
cout << "==================================================================\n";
system("pause");

// Test 6: Editing a Client in the system
cout << "Test 6: Adding client with wrong information and editing it\n";
cout << "Testing New Validation system, searching and editing\n";
int AliID = FileHelper::getLastID("ClientLastID.txt");
Client c2(AliID, "Ali", "aliii1234", "01234567890", 10000); // Wrong Name
f1.addClient(c2);
c2.display();
c2.deposite(500);
system("pause");
c2 = e1.reactivateClient(AliID);
system("pause");
c2.deposite(500);
FileHelper::exportClients(); // use export function to update clients.txt file for the next run.
// better to use it at the end of the program
cout << "==================================================================\n";
system("pause");

//Test 7: Removing all Clients, Employees, and Admins
cout << "Test 7: Removing all Clients, Employees, and Admins\n";
f1.removeAllClients();
f1.removeAllEmployees();
f1.removeAllAdmin();
cout << "Number of clients: " << clientsVector.size() << endl;
cout << "Number of employees: " << employeesVector.size() << endl;
cout << "Number of admins: " << adminsVector.size() << endl;
cout << "==================================================================\n";
system("pause");
*/
