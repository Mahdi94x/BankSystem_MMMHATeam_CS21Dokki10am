#include "Client.h"
#include "FileHelper.h"
#include "FileManager.h"

int Client::countClients = 0;

void Client::withdraw(double amount) { // Mahdi
	if (isActive() == false) {
		declinedTransaction();
		return;
	}
	amount = updatingAmount(amount);
	if (Validation::validateAmount(amount)) {
		if (amount > balance) {
			declinedTransaction();
		}
		else {
			FileManager fm;
			this->balance -= amount;
			acceptedTransaction();
			fm.exportAllClients();
		}
	}
	else {
		declinedAmount();
	}
}

void Client::deposite(double amount) { // Mostafa
	if (isActive() == false) {
		declinedTransaction();
		return;
	}
	amount = updatingAmount(amount);
	if (Validation::validateAmount(amount)) {
		FileManager fm;
		this->balance += amount;
		acceptedTransaction();
		fm.exportAllClients();
	}
	else {
		declinedAmount();
	}
}

void Client::transferTo(Client& recipient, double amount) { // Mahdi
	if (isActive() == false) {
		declinedTransaction();
		return;
	}
	amount = updatingAmount(amount);
	if (Validation::validateAmount(amount)) {
		if (amount > balance) {
			declinedTransaction();
		}
		else {
			FileManager fm;
			this->balance -= amount;
			recipient.balance += amount;
			acceptedTransaction();
			fm.exportAllClients();
		}
	}
	else {
		declinedAmount();
	}
}
