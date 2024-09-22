#pragma once
#include <iostream>
#include "DataSourceInterface.h"
#include "FileHelper.h"

using namespace std;

class FileManager : public DataSourceInterface
{
public:
	//Helal
	void addClient(Client c) {
		FileHelper::saveClient(c);
	}

	//Hadeer
	void addEmployee(Employee e) {
		FileHelper::saveEmployee(e);
	}

	//Mostafa
	void addAdmin(Admin a) {
		FileHelper::saveAdmin(a);
	}

	//Amira
	void getAllClients() {
		FileHelper::getClients();
	}

	//Amira
	void getAllEmployees() {
		FileHelper::getEmployees();
	}

	//Amira
	void getAllAdmins() {
		FileHelper::getAdmins();
	}

	// Mohamed
	void removeAllClients() {
		FileHelper::clearFile("Client.txt", "ClientLastID.txt");
		clientsVector.clear();
	}

	//Mohamed
	void removeAllEmployees() {
		FileHelper::clearFile("Employee.txt", "EmployeeLastID.txt");
		employeesVector.clear();
	}

	//Mohamed
	void removeAllAdmin() {
		FileHelper::clearFile("Admin.txt", "AdminLastID.txt");
		adminsVector.clear();
	}

	void exportAllClients() {
		FileHelper::updateClients();
	}

	void exportAllEmployees() {
		FileHelper::updateEmployees();
	}

	void exportAllAdmins() {
		FileHelper::updateAdmins();
	}
};

