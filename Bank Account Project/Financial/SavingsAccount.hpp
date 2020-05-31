#include "Account.hpp"

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_

class SavingsAccount : public Account {
//TODO Implement members as needed
private:
	SavingsAccount& operator=(const SavingsAccount &other);
    SavingsAccount(const SavingsAccount &other);
	int DepositeNumber;
	Money BonusMoney; //change all initialised stuff here and do it in the constructor because otherwise it won't be saved or something rather.

public:
	SavingsAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	bool checkerDeposit(Money amount);
	bool checkerWithdraw(Money amount);
	Money getBonusValue() const;
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
