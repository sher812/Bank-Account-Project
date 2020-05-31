#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};

class Transaction {
	//TODO Implement members as needed
private:
	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);
    TransactionState TransferState;
    Account* AccountFrom;
    Account* AccountTo;
    Money Amount;
    int TransactionID;
    static int NextIdentity;
public:
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	int getID() const;
	virtual ~Transaction();
	bool Checking();
};

#endif /* TRANSACTION_HPP_ */
