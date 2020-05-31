#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

FinancialServicesSystem::FinancialServicesSystem() {
	// TODO implement
}

std::string FinancialServicesSystem::author(){ //This method returns my unique UPI
	// TODO implement
	return "sher812";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {

	if (verifyCustomer(customer->getID()) == true){ //if customer ID already exists, return false
		return false;
	} else {
		Customer_List.push_back(customer); //add to the customer vector otherwise
		return true;
	}
}

bool FinancialServicesSystem::addAccount(Account* account) {
	// TODO implement
	for (unsigned int i = 0; i < Customer_List.size(); i++) { //Go through the entire customer vector
		if (account->getCustomerID() == Customer_List[i]->getID()) { //Only allow account to be added if the customer ID of the account is already in the customer list
			if (verifyAccount(account->getAccountID()) == true){ //if account ID already exists, return false
				return false;
			} else {

				Account_List.push_back(account); //add to the account vector otherwise
				return true;

			}
		}
	}

	return false;
}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	// TODO implement

	for (unsigned int i = 0; i < Account_List.size(); i++) { //given that the account IDs used in the transactions exist...
		if (transaction -> getToAccount()->getAccountID() == Account_List[i]->getAccountID()) {
			for (unsigned int j = 0; j < Account_List.size(); j++) {
				if (transaction->getFromAccount()->getAccountID() == Account_List[j]->getAccountID()) {
					if (verifyTransaction(transaction->getID()) == true){ //if account already exists, return false
						return false;
					} else {
						Transaction_List.push_back(transaction); //add to the transaction vector otherwise
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool comparator(const Transaction* lesser, const Transaction* greater) { //comparator function for the sort()
	return (lesser->getID() < greater->getID());
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
	// TODO implement

	std::vector<Transaction*> Pending; //create a pending vector

	sort(Transaction_List.begin(), Transaction_List.end(), comparator); //use the sort() to order Transaction vector in an ascending order

		for(unsigned int i = 0; i < Transaction_List.size(); i++) { //going through the Transaction vector
			if (Transaction_List[i]->getState() == PENDING) { //if the state is in PENDING, perform transaction
				Transaction_List[i]->performTransaction();
				if (Transaction_List[i]->getState() == COMPLETED) { //if the status is COMPLETED, add to the pending vector
					Pending.push_back(Transaction_List[i]);
				}

			}
		}

		return Pending; //return all completed transactions via the pending vector.
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	// TODO implement
	std::vector<Account*> AccountMoney; //create a temporary account gathering vector

	for (unsigned int i = 0; i < Account_List.size();i++) { //if Account in Account list has the same customer ID, add to the temporary vector
		if (customerID == Account_List[i]->getCustomerID()) {
			AccountMoney.push_back(Account_List[i]);
		}
	}

	for (unsigned int i = 1; i < AccountMoney.size(); i++) { //Run through how many accounts there are
		AccountMoney[0]->balance.add(AccountMoney[i]->balance); //Add together all the accounts balance into the first account
	}

	return AccountMoney[0]->balance; //return the summed balance
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	// TODO implement
	for(unsigned int i = 0; i < Customer_List.size(); i++ ) { //Go through the customer vector
		if (Customer_List[i]->getID() == customerID) { //If the ID exists, then return true
			return true;
		}
	}

	return false;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
	// TODO implement
	for(unsigned int i = 0; i < Account_List.size(); i++ ) {
		if (Account_List[i]->getAccountID() == accountID) {
			return true;
		}
	}

	return false;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	// TODO implement
	for(unsigned int i = 0; i < Transaction_List.size(); i++ ) { //Go through transaction vector
		if (Transaction_List[i]->getID() == transactionID) { //if transactionID exists in the vector, return true
			return true;
		}
	}

	return false;

}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	// TODO implement

	return Account_List;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	// TODO implement

	return Customer_List;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	// TODO implement

	return Transaction_List;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	// TODO implement
	std::vector<Transaction*> StateVector; //temporary vector to collect transactions of the same state
	for (unsigned int i = 0; i < Transaction_List.size(); i++){
		if (Transaction_List[i]->getState() == state)
			StateVector.push_back(Transaction_List[i]); //add to State Vector if state is same
	}

	return StateVector;
}

FinancialServicesSystem::~FinancialServicesSystem() {
	// TODO implement
}



