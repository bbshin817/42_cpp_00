#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
	std::time_t now;
	std::tm *lt;

	now = std::time(NULL);
	lt = std::localtime(&now);

	std::cout << "["
			  << std::setfill('0')
			  << std::setw(4) << (lt->tm_year + 1900)
			  << std::setw(2) << (lt->tm_mon + 1)
			  << std::setw(2) << lt->tm_mday
			  << "_"
			  << std::setw(2) << lt->tm_hour
			  << std::setw(2) << lt->tm_min
			  << std::setw(2) << lt->tm_sec
			  << "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;

	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount;

	p_amount = this->_amount;

	Account::_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout
			<< "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused"
			<< std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;

	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}
