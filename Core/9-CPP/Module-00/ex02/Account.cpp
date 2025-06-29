#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::Account(int initial_deposit)
{
	this -> _accountIndex = _nbAccounts;
	this -> _amount = initial_deposit;
	this -> _nbDeposits = 0;
	this -> _nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";created\n"
}