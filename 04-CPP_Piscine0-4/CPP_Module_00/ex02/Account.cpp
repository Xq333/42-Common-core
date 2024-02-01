/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:35:10 by xq                #+#    #+#             */
/*   Updated: 2023/07/31 10:35:12 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t time = std::time(0);
  struct tm *timeinfo = std::localtime(&time);

  std::cout << "[" << timeinfo->tm_year + 1900
            << (timeinfo->tm_mon + 1 < 10 ? "0" : "") << timeinfo->tm_mon + 1
            << (timeinfo->tm_mday < 10 ? "0" : "") << timeinfo->tm_mday << "_"
            << (timeinfo->tm_hour < 10 ? "0" : "") << timeinfo->tm_hour
            << (timeinfo->tm_min < 10 ? "0" : "") << timeinfo->tm_min
            << (timeinfo->tm_sec < 10 ? "0" : "") << timeinfo->tm_sec << "] ";
}

Account::Account(int initial_deposit) {
  _displayTimestamp();
  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  this->_accountIndex = this->_nbAccounts++;
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << initial_deposit << ";created" << std::endl;
  this->_totalAmount += initial_deposit;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount()
            << ";deposit:" << deposit << ";amount:" << checkAmount() + deposit
            << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
  this->_amount += deposit;
  _totalNbDeposits += 1;
  _totalAmount += deposit;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount();
  if (this->_amount - withdrawal < 0) {
    std::cout << ";withdrawal:refused" << std::endl;
    return false;
  } else {
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount - withdrawal
              << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
  }
}

Account::Account(void) {
  _displayTimestamp();
  this->_amount = 0;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  this->_accountIndex = this->_nbAccounts++;
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << 0 << ";created" << std::endl;
  this->_totalAmount += 0;
}
