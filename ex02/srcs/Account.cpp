/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:58:18 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/16 12:37:03 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "../include/Account.hpp"

// static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _nbAccounts += 1;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "created" << std::endl;
    return ;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
    time_t      t_stmp_ptr; //Armazena o tempo atual em segundos desde 1º de janeiro de 1970 
    struct tm   *t_stmp; // tempo dividido em componentes como ano, mês, dia, hora, minuto e segundo

    std::time(&t_stmp_ptr);
    t_stmp = localtime(&t_stmp_ptr);
	std::cout << "[";
    std::cout << t_stmp->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << t_stmp->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << t_stmp->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << t_stmp->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << t_stmp->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << t_stmp->tm_sec << "] ";
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
         << "total:" << getTotalAmount() << ";"
         << "deposits:" << getNbDeposits() << ";"
         << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount << ";";
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout << "deposit:" << deposit << ";"
         << "amount:" << this->_amount << ";"
         << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount << ";";

    if (withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    this->_nbWithdrawals += 1;
    std::cout << "withdrawal:" << withdrawal << ";"
            << "amount:" << this->_amount << ";"
            << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "deposits:" << this->_nbDeposits << ";"
         << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

