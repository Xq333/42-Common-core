/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:16 by xq                #+#    #+#             */
/*   Updated: 2023/08/09 14:42:38 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string &str) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  this->filter = 4;
  for (int i = 0; i < 4; i++) {
    if (levels[i] == str) {
      this->filter = i;
      break;
    }
  }
  if (this->filter < 4)
    std::cout << "Harl is ready to complain!" << std::endl;
}

Harl::~Harl(void) {
  if (this->filter < 4)
    std::cout << "Harl is done complaining!" << std::endl;
}

void Harl::debug(void) {
  std::cout
      << "DEBUG: I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout << "INFO: I cannot believe adding extra bacon costs more money. "
               "You didn’t put enough bacon in my burger! If you did, I "
               "wouldn’t be asking for more!"
            << std::endl;
}

void Harl::warning(void) {
  std::cout << "WARNING: I think I deserve to have some extra bacon for free. "
               "I’ve been coming for years whereas you started working here "
               "since last month."
            << std::endl;
}

void Harl::error(void) {
  std::cout
      << "ERROR: This is unacceptable! I want to speak to the manager now."
      << std::endl;
}

void Harl::complain(void) {
  switch (this->filter) {
  case 0:
    std::cout << "\033[1;96m[ DEBUG ]" << std::endl;
    this->debug();
    // fall-through
  case 1:
    std::cout << "\033[1;90m[ INFO ]" << std::endl;
    this->info();
    // fall-through
  case 2:
    std::cout << "\033[1;93m[ WARNING ]" << std::endl;
    this->warning();
    // fall-through
  case 3:
    std::cout << "\033[1;31m[ ERROR ]" << std::endl;
    this->error();
    break;
  default:
    std::cout
        << "\033[1;97m [ Probably complaining about insignificant problems ]"
        << std::endl;
    break;
  }
}
