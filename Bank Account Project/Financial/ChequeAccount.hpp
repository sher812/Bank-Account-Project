#include "Account.hpp"

#ifndef CHEQUEACCOUNT_HPP_
#define CHEQUEACCOUNT_HPP_

class ChequeAccount : public Account {
//TODO Implement members as needed
private:
	ChequeAccount& operator=(const ChequeAccount &other);
   	ChequeAccount(const ChequeAccount &other);
	Money* TransactionFee;
public:
	ChequeAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money* getTransactionFee() const;
	bool checkerDeposit(Money amount);
	bool checkerWithdraw(Money amount);
	virtual ~ChequeAccount();
};

#endif /* CHEQUEACCOUNT_HPP_ */
