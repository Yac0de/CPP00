#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "["
		 << 1900 + ltm->tm_year
		 << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon 
		 << std::setfill('0') << std::setw(2) << ltm->tm_mday << "_"
		 << std::setfill('0') << std::setw(2) << ltm->tm_hour 
		 << std::setfill('0') << std::setw(2) << ltm->tm_min 
		 << std::setfill('0') << std::setw(2) << ltm->tm_sec 
		 << "]";
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout   << " " << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
	return;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout   << " " << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
	return;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout   << " " << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	return;
}

int Account::checkAmount(void) const { return _amount; }

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout   << " " << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:";
	if(withdrawal > checkAmount())
		return(std::cout << "refused" << std::endl, false);
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout   << withdrawal
				<< ";amount:" << _amount - withdrawal
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return true;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout   << " " << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
	return;
}
