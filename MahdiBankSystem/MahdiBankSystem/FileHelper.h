#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Parser.h"
#include "Client.h"
#include "Admin.h"
#include "Vectors.h"
using namespace std;

class FileHelper
{
public:

	//Amira
	static void saveLastID(string FileName, int id) {
		fstream myFile;
		myFile.open(FileName, ios::out); // Overwrite
		if (myFile.is_open()) {
			myFile << id;
			myFile.close();
		}
	}

	//Amira
	static int getLastID(string fileName) {
		fstream myFile;
		string last;
		myFile.open(fileName, ios::in);
		if (myFile.is_open()) {
			myFile >> last;
			myFile.close();
		}
		int lastID = stoi(last) + 1;
		return lastID;
	}

	//Helal
	static void saveClient(Client c) {
		clientsVector.push_back(c);
		fstream myFile;
		string clientInfo = to_string(c.getID()) + '~' + c.getName() + '~' + c.getPassword() + '~' + c.getPhoneNumber() + '~' + to_string(c.getBalance());
		myFile.open("Client.txt", ios::app);
		if (myFile.is_open()) {
			myFile << clientInfo << endl;
			myFile.close();
		}
		saveLastID("ClientLastID.txt", c.getID());
	}

	//Helal
	static void getClients() {
		fstream myFile;
		myFile.open("Client.txt", ios::in);
		string clientLine;
		if (myFile.is_open()) {
			while (getline(myFile, clientLine)) {
				vector<vector<string>> allData = Parser::split(clientLine);
				for (auto attributes : allData) { // int and string attributes so we use auto keyword to handle it
					Client cliobj = Parser::parseToClient(attributes);
					clientsVector.push_back(cliobj);
				}
			}
			myFile.close();
		}
	}

	//Hadeer
	static void saveEmployee(Employee e) {
		employeesVector.push_back(e);
		fstream myFile;
		string info = to_string(e.getID()) + '~' + e.getName() + '~' + e.getPassword() + '~' + e.getPhoneNumber() + '~' + to_string(e.getSalary());
		myFile.open("Employee.txt", ios::app);
		if (myFile.is_open()) {
			myFile << info << endl;
			myFile.close();
		}
		saveLastID("EmployeeLastID.txt", e.getID());
	}

	//Hadeer
	static void getEmployees() {
		fstream myFile;
		myFile.open("Employee.txt", ios::in);
		string employeeLine;
		if (myFile.is_open()) {
			while (getline(myFile, employeeLine)) {
				vector<vector<string>> allData = Parser::split(employeeLine);
				for (auto attributes : allData) { // int and string attributes so we use auto key word to handle it
					Employee empobj = Parser::parseToEmployee(attributes);
					employeesVector.push_back(empobj);
				}
			}
			myFile.close();
		}
	}

	//Mostafa
	static void saveAdmin(Admin a) {
		adminsVector.push_back(a);
		fstream myFile;
		string info = to_string(a.getID()) + '~' + a.getName() + '~' + a.getPassword() + '~' + a.getPhoneNumber() + '~' + to_string(a.getSalary());
		myFile.open("Admin.txt", ios::app);
		if (myFile.is_open()) {
			myFile << info << endl;
			myFile.close();
		}
		saveLastID("AdminLastID.txt", a.getID());
	}

	//Mostafa
	static void getAdmins() {
		fstream myFile;
		myFile.open("Admin.txt", ios::in);
		string adminLine;
		if (myFile.is_open()) {
			while (getline(myFile, adminLine)) {
				vector<vector<string>> allData = Parser::split(adminLine);
				for (auto attributes : allData) { // int and string attributes so we use auto key word to handle it
					Admin admobj = Parser::parseToAdmin(attributes);
					adminsVector.push_back(admobj);
				}
			}
			myFile.close();
		}
	}

	//Mohamed
	static void clearFile(string fileName, string lastIDFile) {
		fstream myFile;
		myFile.open(fileName, ios::out);
		if (myFile.is_open()) {
			myFile << "";
			myFile.close();
		}
		myFile.open(lastIDFile, ios::out);
		if (myFile.is_open()) {
			myFile << 0;
			myFile.close();
		}
	}

	//Mahdi
	static void updateClients() {
		fstream myFile;
		myFile.open("Client.txt", ios::out);
		if (myFile.is_open()) {
			for (int i = 0; i < clientsVector.size(); i++) {
				string clientInfo = to_string(clientsVector[i].getID()) + '~' + clientsVector[i].getName() + '~' + clientsVector[i].getPassword() + '~' + clientsVector[i].getPhoneNumber() + '~' + to_string(clientsVector[i].getBalance());
				myFile << clientInfo << endl;
			}
			myFile.close();
		}
	}

	//Mahdi
	static void updateEmployees() {
		fstream myFile;
		myFile.open("Employee.txt", ios::out);
		if (myFile.is_open()) {
			for (int i = 0; i < employeesVector.size(); i++) {
				string employeeInfo = to_string(employeesVector[i].getID()) + '~' + employeesVector[i].getName() + '~' + employeesVector[i].getPassword() + '~' + employeesVector[i].getPhoneNumber() + '~' + to_string(employeesVector[i].getSalary());
				myFile << employeeInfo << endl;
			}
			myFile.close();
		}
	}

	//Mahdi
	static void updateAdmins() {
		fstream myFile;
		myFile.open("Admin.txt", ios::out);
		if (myFile.is_open()) {
			for (int i = 0; i < adminsVector.size(); i++) {
				string adminInfo = to_string(adminsVector[i].getID()) + '~' + adminsVector[i].getName() + '~' + adminsVector[i].getPassword() + '~' + adminsVector[i].getPhoneNumber() + '~' + to_string(adminsVector[i].getSalary());
				myFile << adminInfo << endl;
			}
			myFile.close();
		}
	}
};

