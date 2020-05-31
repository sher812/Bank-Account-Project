#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	// TODO implement
	Money balance(0, 0); //initialize account starting off with 0 in balance
	this->balance = balance;
}

bool CreditAccount::withdrawMoney(Money amount) {
	// TODO implement
	if (amount.asCents() < 0) { //Account can only withdraw positive values
		return false;
	}

	this->balance.subtractCents(amount.asCents());
	return true;
}

bool CreditAccount::depositMoney(Money amount) {
	// TODO implement
	if (amount.asCents() < 0) { //Account can only deposit positive amounts
		return false;
	}

	if (amount.asCents() + getBalance().asCents() > 500000) { //cannot deposit more than 5000 dollars or less than 0
		return false;
	} else {
		this->balance.addCents(amount.asCents());
		return true;
	}

}

bool CreditAccount::checkerDeposit(Money amount) {

	if (amount.asCents() < 0) { //checks if deposit is possible
		return false;
	}

	if (amount.asCents() + getBalance().asCents() > 500000) {
		return false;
	} else {
		return true;
	}
}

bool CreditAccount::checkerWithdraw(Money amount) {

	if (amount.asCents() < 0) { //checks if withdrawal is possible
		return false;
	}

	return true;
}

CreditAccount::~CreditAccount() {
	// TODO implement
}
