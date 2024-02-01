/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:13:44 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/17 07:13:45 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[1;31m" // FOR DESTRUCTORS
#define GRN "\033[1;32m" // FOR CONSTRUCTORS
#define YEL "\033[1;33m" // FOR ERRORS
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define W "\033[1;97m"
#define NC "\033[1;0m"
#define I "\033[1;3m"
#define U "\033[1;4m"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>

class BitcoinExchange {
public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &origin);
  ~BitcoinExchange();

  BitcoinExchange &operator=(BitcoinExchange const &origin);

  void createDB(std::string file);
  void getAndPrint(std::string file);
  class fileError : std::exception {
  public:
    virtual const char *what() throw() {
      return RED "[BitcoinExchange] " W "Batabase file error." NC;
    }
  };

private:
  std::map<int, float> _db;
};
