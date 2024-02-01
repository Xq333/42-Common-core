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

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

int main() {
  Bureaucrat Hugo("Hugo", 138);
  Bureaucrat Pedro("Pedro", 46);
  Bureaucrat Isaac("Isaac", 6);
  ShruberryCreationForm Shruberry("Hugo");
  RobotomyRequestForm Roboto("Pedro");
  PresidentialPardonForm President("Isaac");
  std::cout << BLU "----- Testing form sign/execution authorization -----"
            << std::endl;

  try {
    Hugo.signForm(Shruberry);
    Hugo.executeForm(Shruberry);
    std::cout << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << YEL << e.what() << std::endl;
  }

  try {
    Pedro.signForm(Roboto);
    Pedro.executeForm(Roboto);
    std::cout << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << YEL << e.what() << std::endl;
  }

  try {
    Isaac.signForm(President);
    Isaac.executeForm(President);
    std::cout << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << YEL << e.what() << std::endl;
  }

  std::cout << std::endl;
  Hugo.incrementGrade();
  Pedro.incrementGrade();
  Isaac.incrementGrade();
  std::cout << std::endl;

  try {
    Hugo.signForm(Shruberry);
    Hugo.executeForm(Shruberry);
    std::cout << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << YEL << e.what() << std::endl;
  }

  try {
    Pedro.signForm(Roboto);
    Pedro.executeForm(Roboto);
    std::cout << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << YEL << e.what() << std::endl;
  }

  try {
    Isaac.signForm(President);
    Isaac.executeForm(President);
    std::cout << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << YEL << e.what() << std::endl;
  }

  std::cout << BLU "----- Destructors -----" << std::endl;
}
