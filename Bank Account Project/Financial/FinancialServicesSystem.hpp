#ifndef FINANCIALSERVICESSYSTEM_HPP_
#define FINANCIALSERVICESSYSTEM_HPP_


#include "Customer.hpp"
#include "Account.hpp"
#include "Transaction.hpp"
#include "Money.hpp"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

class FinancialServicesSystem {
//TODO Add members as needed
private:

public:
	FinancialServicesSystem();
	static std::string author();
	bool addCustomer(Customer* customer);
	bool addAccount(Account* account);
	bool addTransaction(Transaction* transaction);

	std::vector<Transaction*> performPendingTransactions();
	Money getCustomerBalance(int customerID) const;

	bool verifyCustomer(int customerID) const;
	bool verifyAccount(int accountID) const;
	bool verifyTransaction(int transactionID) const;

	std::vector<Account*> getAccounts() const;
	std::vector<Customer*> getCustomers() const;
	std::vector<Transaction*> getTransactions() const;
	std::vector<Transaction*> getTransactions(TransactionState state) const;

	std::vector<Customer*> Customer_List; //Vector to collect list of customers
	std::vector<Account*> Account_List; //Vector to collect list of accounts
	std::vector<Transaction*> Transaction_List; //Vector to collect list of transactions


	virtual ~FinancialServicesSystem();
};

#endif /* FINANCIALSERVICESSYSTEM_HPP_ */
