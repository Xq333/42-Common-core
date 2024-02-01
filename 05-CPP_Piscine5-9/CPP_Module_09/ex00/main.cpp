/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:13:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/17 07:13:30 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << YEL "Error: could not open file." << std::endl;
    return 1;
  }
  try {
    BitcoinExchange btc;
    btc.createDB("data.csv");
    btc.getAndPrint(av[1]);
  } catch (BitcoinExchange::fileError &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
