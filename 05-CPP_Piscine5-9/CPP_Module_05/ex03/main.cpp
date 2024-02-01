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

#include "Intern.hpp"

int main() {
  // Bureaucrat Hugo("Hugo", 138);
  // Bureaucrat Pedro("Pedro", 46);
  // Bureaucrat Isaac("Isaac", 6);
  // ShruberryCreationForm Shruberry("Hugo");
  // RobotomyRequestForm Roboto("Pedro");
  // PresidentialPardonForm President("Isaac");
  // std::cout << BLU "----- Testing form sign/execution authorization -----" <<
  // std::endl;
  //
  // try{
  // Hugo.signForm(Shruberry);
  // Hugo.executeForm(Shruberry);
  // std::cout << std::endl;
  // } catch (AForm::GradeTooLowException &e)
  // {
  //   std::cout << YEL << e.what() << std::endl;
  // }
  //
  // try{
  // Pedro.signForm(Roboto);
  // Pedro.executeForm(Roboto);
  // std::cout << std::endl;
  // } catch (AForm::GradeTooLowException &e)
  // {
  //   std::cout << YEL << e.what() << std::endl;
  // }
  //
  // try{
  // Isaac.signForm(President);
  // Isaac.executeForm(President);
  // std::cout << std::endl;
  // } catch (AForm::GradeTooLowException &e)
  // {
  //   std::cout << YEL << e.what() << std::endl;
  // }
  //
  // std::cout << std::endl;
  // Hugo.incrementGrade();
  // Pedro.incrementGrade();
  // Isaac.incrementGrade();
  // std::cout << std::endl;
  //
  // try{
  // Hugo.signForm(Shruberry);
  // Hugo.executeForm(Shruberry);
  // std::cout << std::endl;
  // } catch (AForm::GradeTooLowException &e)
  // {
  //   std::cout << YEL << e.what() << std::endl;
  // }
  //
  // try{
  // Pedro.signForm(Roboto);
  // Pedro.executeForm(Roboto);
  // std::cout << std::endl;
  // } catch (AForm::GradeTooLowException &e)
  // {
  //   std::cout << YEL << e.what() << std::endl;
  // }
  //
  // try{
  // Isaac.signForm(President);
  // Isaac.executeForm(President);
  // std::cout << std::endl;
  // } catch (AForm::GradeTooLowException &e)
  // {
  //   std::cout << YEL << e.what() << std::endl;
  // }
  std::cout << std::endl << std::endl << std::endl;
  Bureaucrat Ivan("Ivan", 1);
  Intern intern;
  AForm *form[4];

  std::cout << std::endl << BLU "---- Shruberry test ----" NC << std::endl;
  form[0] = intern.makeForm("shrubbery creation", "Ivan");
  Ivan.signForm(*form[0]);
  Ivan.executeForm(*form[0]);

  std::cout << std::endl << BLU "---- Robotomy test ----" NC << std::endl;
  form[1] = intern.makeForm("robotomy request", "Ivan");
  Ivan.signForm(*form[1]);
  Ivan.executeForm(*form[1]);

  std::cout << std::endl << BLU "---- Presidential test ----" NC << std::endl;
  form[2] = intern.makeForm("presidential pardon", "Ivan");
  Ivan.signForm(*form[2]);
  Ivan.executeForm(*form[2]);

  std::cout << std::endl << BLU "---- Magic test ----" NC << std::endl;
  form[3] = intern.makeForm("magic recovery", "Ivan");
  Ivan.signForm(*form[3]);
  Ivan.executeForm(*form[3]);

  std::cout << BLU "----- Destructors -----" << std::endl;
  for (int i = 0; i < 4; i++)
    delete form[i];
}
