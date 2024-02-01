/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:12:04 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:12:06 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << &str << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;

  std::cout << str << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;
  return 0;
}
