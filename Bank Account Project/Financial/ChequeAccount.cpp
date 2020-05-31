#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class

ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {

	this->balance = Money (0,0); //start balance off from 0
	Money* TransFee = new Money(0, 100); //start transaction fee from 1 dollar
	this->TransactionFee = TransFee;
}

bool ChequeAccount::withdrawMoney(Money amount) {
	// TODO implement
	if (amount.asCents() +  this->TransactionFee->asCents() < 0) { //cannot withdraw if amount and transaction fee is less than 0
		return false;
	} else if(amount.asCents() +  this->TransactionFee->asCents() <= getBalance().asCents()) { //withdraw possible only if amount + transaction fee is less than current balance
		this->balance.subtractCents(amount.asCents() + this->TransactionFee->asCents());
		this->TransactionFee->addCents(100);
		return true;
	} else {
		return false;
	}
}

bool ChequeAccount::depositMoney(Money amount) {
	// TODO implement
	if (amount.asCents() >= 0 && amount.asCents() <= 300000) { //deposits can only be positive and less than or equal to 3000 dollars
		this->balance.addCents(amount.asCents());
		return true;
	} else {	
		return false;
	}
}

bool ChequeAccount::checkerDeposit(Money amount) {
	if (amount.asCents() >= 0 && amount.asCents() <= 300000) { //check if deposit is possible
		return true;
	} else {
		return false;
	}
}

bool ChequeAccount::checkerWithdraw(Money amount) {

	if (amount.asCents() < 0) { //check if withdraw is possible
		return false;
	}

	if (amount.asCents() +  this->TransactionFee->asCents() <= getBalance().asCents()) {
		return true;
	} else {
		return false;
	}
}

Money* ChequeAccount::getTransactionFee() const {
	// TODO implement
	return this->TransactionFee;
}

ChequeAccount::~ChequeAccount() {
	// TODO implement
	delete TransactionFee; //delete what is in the TransFee address to prevent an overflow occurring in the heap.
}

