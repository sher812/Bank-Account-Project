#include "SavingsAccount.hpp"


//TODO Implement the SavingsAccount class

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	// TODO implement
	this->DepositeNumber = 0; //initialize deposit number as 0
	Money BonusMoney(0, 1000); //initialize bonus money as 10 dollars
	this->BonusMoney = BonusMoney;
	Money balance(0, 0); //start balance off from 0
	this->balance = balance;
}

bool SavingsAccount::withdrawMoney(Money amount) {
	// TODO implement

	if (amount.asCents() > getBalance().asCents() || amount.asCents() < 0) { //don't withdraw money if amount is greater than balance or if amount is negative
		return false;
	} else { 

		this->BonusMoney.subtractCents(200); //subtract 2 dollars from bonus money every time withdrawal is called
		if (this->BonusMoney.asCents() < 0) { //if bonus money reaches 0, leave it at 0
			Money zero(0, 0);
			this->BonusMoney = zero;
		}
		this->balance.subtractCents(amount.asCents());
		return true;
	}
}

bool SavingsAccount::depositMoney(Money amount) {
	// TODO implement

	if (amount.asCents() >= 0) {
		this->DepositeNumber++;
		this->balance.addCents(amount.asCents());
		if ((this->DepositeNumber)%2 == 0) { //every two times we deposit money add bonus money
			this->balance.addCents(this->BonusMoney.asCents());
		}
		return true;
	} else {	
		return false;
	}
}

bool SavingsAccount::checkerDeposit(Money amount) {

	if (amount.asCents() < 0) { //check if deposit is possible
		return false;
	}

	if (amount.asCents() >= 0) {
		return true;
	} else {
		return false;
	}
}

bool SavingsAccount::checkerWithdraw(Money amount) {

	if (amount.asCents() < 0) { //check if withdrawal is possible
		return false;
	}

	if (amount.asCents() > getBalance().asCents()) {
		return false;
	} else {
		return true;
	}
}

Money SavingsAccount::getBonusValue() const {
	// TODO implement
	return this->BonusMoney;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


