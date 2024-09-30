#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Admin.h"
using namespace std;

class Parser
{
public:
	// Mahdi
	static vector<vector<string>> split(string dataBulk) {
		vector<vector<string>> allData;
		string line;
		stringstream ss(dataBulk);

		while (getline(ss, line, '\n')) {
			vector<string> singleLineAttributes;
			string token;
			stringstream lineStream(line);

			while (getline(lineStream, token, '~')) {
				singleLineAttributes.push_back(token);
			}

			singleLineAttributes.shrink_to_fit();
			allData.push_back(singleLineAttributes);

		}
		return allData;
	}

	//Helal
	static Client parseToClient(vector<string> singleLineAttributes) {
		int id = stoi(singleLineAttributes[0]); //stoi converts string to integer
		string name = singleLineAttributes[1];
		string password = singleLineAttributes[2];
		string phonenumber = singleLineAttributes[3];
		double balance = stod(singleLineAttributes[4]); // stod converts string to double
		return Client(id, name, password, phonenumber, balance);
	}

	//Hadeer
	static Employee parseToEmployee(vector<string> singleLineAttributes) {
		int id = stoi(singleLineAttributes[0]);
		string name = singleLineAttributes[1];
		string password = singleLineAttributes[2];
		string phonenumber = singleLineAttributes[3];
		double salary = stod(singleLineAttributes[4]);
		return Employee(id, name, password, phonenumber, salary);
	}
};

