/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:19:57 by xq                #+#    #+#             */
/*   Updated: 2023/09/22 08:19:59 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
  Bureaucrat Hugo("Hugo", 150);
  Bureaucrat Pedro("Pedro", 0);
  Bureaucrat Isaac("Isaac", 200);
  std::cout << std::endl;
  Hugo.setGrade(160);
  std::cout << std::endl;
  Hugo.setGrade(0);
  std::cout << std::endl;
  Hugo.decrementGrade();
  std::cout << std::endl;
  Hugo.incrementGrade();
  std::cout << std::endl;
  Hugo.setGrade(1);
  std::cout << std::endl;
  Hugo.incrementGrade();
  std::cout << std::endl;
  Hugo.decrementGrade();
  std::cout << std::endl;
  std::cout << Hugo;
  std::cout << Pedro;
  std::cout << Isaac;
}
