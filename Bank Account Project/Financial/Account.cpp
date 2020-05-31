#include "Account.hpp"

int Account::nextAccountID = 0;

Account::Account(const int customerID):idACC(nextAccountID++) { //increment account ID every time a new Cheque, Credit, Savings is created
	// TODO implement
	this->CID = customerID;
}

int Account::getAccountID() const {
	return idACC;
}

int Account::getCustomerID() const {
	// TODO implement	
	return this->CID;
}

Money Account::getBalance() const {
	// TODO implement
	return this->balance;
}

Account::~Account() {
	// TODO implement
}

