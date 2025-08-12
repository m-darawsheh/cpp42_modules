#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
// initializing static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << "\n";
}



Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";closed" << "\n";
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << "\n";
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
			  << ";withdrawal:" << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

//the struct which is used to represent time
//struct tm {
//    int tm_sec;   // seconds (0–60)
//    int tm_min;   // minutes (0–59)
//    int tm_hour;  // hours (0–23)
//    int tm_mday;  // day of month (1–31)
//    int tm_mon;   // months since January (0–11)
//    int tm_year;  // years since 1900
//    int tm_wday;  // day of week (0=Sunday)
//    int tm_yday;  // day of year (0–365)
//    int tm_isdst; // daylight saving time flag
//};

void Account :: _displayTimestamp(void)
{
	time_t now ;
	time(&now);
	tm *struct_time = localtime(&now);
	std::cout << "[" << 1900 + struct_time->tm_year << std::setfill('0') << std::setw(2) << 1 + struct_time->tm_mon
			  << std::setfill('0') << std::setw(2) << struct_time->tm_mday << "_"
			  << std::setfill('0') << std::setw(2) << struct_time->tm_hour
			  << std::setfill('0') << std::setw(2) << struct_time->tm_min
			  << std::setfill('0') << std::setw(2) << struct_time->tm_sec << "] ";
}
