/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:13:39 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/17 07:13:40 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
 *          Constructors
 * */

BitcoinExchange::BitcoinExchange() {
  std::cout << GRN "[BitcoinExchange] " W "A database has been created!" NC
            << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &origin) {
  std::cout << GRN "[BitcoinExchange] " W "A database has been copied!" NC
            << std::endl;
  this->_db = origin._db;
}

/*
 *          Destructor
 * */

BitcoinExchange::~BitcoinExchange() {
  std::cout << RED "[BitcoinExchange]" W " A database has been destroyed!" NC
            << std::endl;
}

/*
 *          Overload operators
 * */

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &origin) {
  this->_db = origin._db;
  return *this;
}

/*
 *          Functions
 * */

void BitcoinExchange::createDB(std::string file) {
  std::ifstream f;
  std::string line;
  std::string date;
  int dateint;
  float val;
  f.open(file.c_str());
  if (f.fail()) {
    throw(fileError());
    return;
  }
  while (!f.eof()) {
    f >> line;
    date = line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
    dateint = std::atoi(date.c_str());
    val = std::strtof(line.substr(11).c_str(), NULL);
    this->_db.insert(std::pair<int, float>(dateint, val));
  }
  f.close();
}

bool checkDate(std::string date) {
  int truedays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(4, 2).c_str());
  int day = std::atoi(date.substr(6, 2).c_str());
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    truedays[1] = 29;
  if (year < 2009)
    return false;
  if (month < 1 || month > 12)
    return false;
  if (truedays[month] < day || day < 1)
    return false;
  return true;
}

void BitcoinExchange::getAndPrint(std::string file) {
  std::ifstream f;
  std::string line;
  std::string date;
  float val;
  f.open(file.c_str());
  if (f.fail()) {
    throw(fileError());
    return;
  }
  while (!f.eof()) {
    std::getline(f, line);
    if (line.length() == 0)
      break;
    if (line == "date | value")
      std::getline(f, line);
    if (line.length() < 14 || line[10] != ' ' || line[4] != '-' ||
        line[7] != '-')
      std::cout << YEL "Error: bad input => " << line << NC << std::endl;
    else {
      date = line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
      val = std::strtof(line.substr(13).c_str(), NULL);
      if (line.find('|') == line.npos) {
        std::cout << YEL "Error: bad input => " << line << NC << std::endl;
      } else if (!checkDate(date)) {
        std::cout << YEL "Error: date error." NC << std::endl;
      } else if (val < 0) {
        std::cout << YEL "Error: not a positive number." NC << std::endl;
      } else if (val > 2147483647.0) {
        std::cout << YEL "Error: too large a number." NC << std::endl;
      } else {
        std::map<int, float>::iterator it =
            this->_db.lower_bound(std::atoi(date.c_str()));
        if (it == this->_db.end())
          it--;
        float res = it->second;
        std::cout << W << line.substr(0, 10) << " => " << val << " = "
                  << val * res << NC << std::endl;
      }
    }
  }
  f.close();
}
