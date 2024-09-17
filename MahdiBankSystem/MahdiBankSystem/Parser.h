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
	/*myFile.open("Mahdi.txt", ios::in);
	if (myFile.is_open()) {
		string singleLine;
		while (getline(myFile, singleLine)) {
			cout << singleLine<<"\n";
		}
		myFile.close();
	}*/
	/* 
	Data Bulk Format:
	format: id~name~password~phonenumber~balance
	1001~John Doe~password123~01234567890~1500.000000'\n'

	1002~Jane Smith~securePass!~01234567891~2000.000000
	1003~Alice Johnson~mypassword~01234567892~2500.000000
	1004~Bob Brown~password456~01234567893~3000.000000
	1005~Carol White~pass@word1~01234567894~3500.000000
	1006~David Black~Password789~01234567895~4000.000000
	1007~Emma Green~password321~01234567896~4500.000000
	1008~Frank Miller~mypassword1~01234567897~5000.000000
	1009~Grace Lewis~secret123~01234567898~5500.000000
	1010~Hannah Wilson~12345678~01234567899~6000.000000
	1011~Ivy Scott~qwertyui~01234567900~6500.000000
	1012~Jack Hall~asdfghjk~01234567901~7000.000000
	1013~Kara Adams~Pashidf452~01234567902~7500.000000
	1014~Liam Clark~password~01234567903~8000.000000
	1015~Mia Lewis~password1~01234567904~8500.000000
	*/
public:
	// Mahdi
	static vector<vector<string>> split(string dataBulk) { 
		//vector intial format [ [], [], [], [], [],]
		vector<vector<string>> allData;
		string line;
		stringstream ss(dataBulk);

		// Split the bulk data into individual lines
		while (getline(ss, line, '\n')) {
			vector<string> singleLineAttributes; 
			//vector format 1 [ [singlelineattribute1], [singlelineattribute2],[singlelineattribute3]]
			string token;
			stringstream lineStream(line);

			// Split each line into attributes based on the '~' delimiter
			while (getline(lineStream, token, '~')) {
				singleLineAttributes.push_back(token);
			}

			// Add the vector of attributes to the main vector
			singleLineAttributes.shrink_to_fit();
			allData.push_back(singleLineAttributes);

		}
		return allData;  
		//						singlelineattribute1		singlelineattribute2
		//vector final format [ [att1,att2,att3,att4,att5],[att1,att2,att3,att4,att5],[att1,att2,att3,att4,att5],[],[] ]
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

	//Mostafa
	static Admin parseToAdmin(vector<string> singleLineAttributes) {
		int id = stoi(singleLineAttributes[0]);
		string name = singleLineAttributes[1];
		string password = singleLineAttributes[2];
		string phonenumber = singleLineAttributes[3];
		double salary = stod(singleLineAttributes[4]);
		return Admin(id, name, password, phonenumber, salary);
	}
};

