/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:27:45 by xq                #+#    #+#             */
/*   Updated: 2023/07/27 15:27:47 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.hpp"

Utilities::Utilities(void) {}

Utilities::~Utilities(void) {}

bool Utilities::strdigit(std::string str) {
  for (int i = 0; str[i]; i++) {
    if (!isdigit(str[i])) {
      std::cout << "Phone number must be a number!" << std::endl;
      return (false);
    }
  }
  return (true);
}

std::string Utilities::getString(std::string str) {
  std::string buff;

  std::cout << str;
  if (!std::getline(std::cin, buff)) {
    buff = "NULL";
    std::cout << "NULL" << std::endl;
  }
  return (buff);
}

void Utilities::printsearch(int index) {
  std::string head = "|     Index| FirstName|  LastName|  Nickname|";
  if (index == 1)
    goto printhead;
  else if (index == 2)
    goto printsep;
printhead:
  std::cout << head << std::endl;
  return;
printsep:
  for (int i = 0; i < (int)head.length(); i++)
    std::cout << "-";
  std::cout << std::endl;
  return;
}

void Utilities::printvalues(std::string str) {
  if (str.length() > 9) {
    for (int y = 0; y < 9; y++)
      std::cout << str[y];
    std::cout << '.';
  } else {
    int length = 10 - str.length();
    for (int y = 0; y < length; y++)
      std::cout << " ";
    std::cout << str;
  }
  std::cout << "|";
  return;
}

void Utilities::printsearchedvalues(std::string str, std::string contact) {
  std::cout << str << contact << std::endl;
}
