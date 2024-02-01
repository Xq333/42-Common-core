/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:18:03 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/13 12:34:44 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <string>

int main(void) {
  Phonebook phone;
  std::string buff;

  while (1) {
    std::cout << "Phonebook > ";
    if (!std::getline(std::cin, buff) || phone.exit(buff)) {
      if (!phone.exit(buff))
        std::cout << std::endl;
      break;
    } else if (upperstr(buff) == "ADD") {
      if (!phone.add()) {
        std::cout << std::endl;
        break;
      }
    } else if (upperstr(buff) == "SEARCH") {
      if (!phone.search()) {
        std::cout << std::endl;
        break;
      }
    } else
      std::cout << buff << ": command not found" << std::endl;
  }
  return 0;
}
