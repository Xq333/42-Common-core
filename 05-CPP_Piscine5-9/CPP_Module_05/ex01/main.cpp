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

#include "Form.hpp"

int main() {
  std::cout << BLU "----- Test from ex00 -----" << std::endl;
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
  std::cout << BLU "----- Testing form exeptions -----" << std::endl;
  std::cout << BLU "Form with " RED "160" BLU " grade to " RED U "sign" NC BLU
                   ":" NC
            << std::endl;
  try {
    Form test("test", 160, 1);
  } catch (Form::GradeTooLowException &e) {
    std::cout << YEL "[Form] " << e.what() << std::endl;
  }
  std::cout << BLU "Form with " RED "0" BLU " grade to " RED U "sign" NC BLU
                   ":" NC
            << std::endl;
  try {
    Form test("test", 0, 1);
  } catch (Form::GradeTooHighException &e) {
    std::cout << YEL "[Form] " << e.what() << std::endl;
  }
  std::cout << BLU "Form with " RED "160" BLU " grade to " RED U
                   "execute" NC BLU NC ":"
            << std::endl;
  try {
    Form test("test", 1, 160);
  } catch (Form::GradeTooLowException &e) {
    std::cout << YEL "[Form] " << e.what() << std::endl;
  }
  std::cout << BLU "Form with " RED "0" BLU " grade to " RED U "execute" NC BLU
                   ":" NC
            << std::endl;
  try {
    Form test("test", 1, 0);
  } catch (Form::GradeTooHighException &e) {
    std::cout << YEL "[Form] " << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << BLU "----- Testing form sign authorization -----" << std::endl;
  Form form("Bourse", 50, 50);
  Pedro.signForm(form);
  Isaac.signForm(form);
  std::cout << std::endl;

  Form form2("Bourse2", 50, 50);
  Isaac.signForm(form2);
  std::cout << std::endl;
  std::cout << BLU "----- Destructors -----" << std::endl;
  std::cout << form;
}
