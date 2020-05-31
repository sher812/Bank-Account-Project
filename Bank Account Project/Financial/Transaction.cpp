#include "Transaction.hpp"
#include <string>

int Transaction::NextIdentity = 0;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount):TransactionID(NextIdentity++){ //Increment TransactionID every time a new transaction is called
	//TODO Implement
	this->TransferState = PENDING; //initialise transfer state as PENDING
	this->AccountFrom = fromAccount;
	this->AccountTo = toAccount;
	this->Amount = amount; //if amount is less than 0, make the amount to 0
	if (this->Amount.asCents() < 0) {
		Money zero(0,0);
		this->Amount = zero;
	}
}

bool Transaction::performTransaction(){
	//TODO Implement

	if (this->AccountFrom->checkerWithdraw(this->Amount) == true && this->AccountTo->checkerDeposit(this->Amount) == true){ //given that the withdraw and deposit accounts are both possible
		this->AccountFrom->withdrawMoney(this->Amount);
		this->AccountTo->depositMoney(this->Amount);
		this->TransferState = COMPLETED; //allow withdrawal and deposits to happen, and change state to COMPLETED
		return true;
	} else {
		this->TransferState = FAILED; //Else don't allow transactions, and set state to FAILED
		return false;
	}
}

TransactionState Transaction::getState() const {
	//TODO Implement
	return this->TransferState;
}

Money Transaction::getAmount() const {
	//TODO Implement
	if (this->Amount.asCents() < 0) { //If amount is < 0, return 0
		return Money(0,0);
	} else {
		return this->Amount;
	}
}

Account* Transaction::getToAccount() const {
	//TODO Implement
	return this->AccountTo;
}

Account* Transaction::getFromAccount() const {
	//TODO Implement
	return this->AccountFrom;
}

int Transaction::getID() const {
	//TODO Implement
	return TransactionID;
}

Transaction::~Transaction() {
	// TODO implement
}

