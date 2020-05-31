#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{
//TODO Implement members as needed
private:
	Account& operator=(const Account &other);
	Account(const Account &other);
	static int nextAccountID;
	int CID;
	const int idACC;

public:
	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;
	virtual bool checkerDeposit(Money amount) = 0;
	virtual bool checkerWithdraw(Money amount) = 0;
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	Money balance;
	virtual ~Account();

};

#endif /* ACCOUNT_HPP_ */
