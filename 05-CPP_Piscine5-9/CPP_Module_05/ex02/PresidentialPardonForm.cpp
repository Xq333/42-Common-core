/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:25:30 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:25:31 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
 *                  Constructors
 * */

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Unknown") {
  std::cout << GRN "[PresidentialPardonForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been created!" NC
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &_target)
    : AForm("PresidentialPardonForm", 25, 5), _target(_target) {
  std::cout << GRN "[PresidentialPardonForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been created!" NC
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &origin) : AForm(origin){
  (void)origin;
}

/*
 *                  Destructors
 * */

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << RED "[PresidentialPardonForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been destroyed!" NC
            << std::endl;
}

/*
 *                  Overload operators
 * */

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &origin) {
  (void)origin;
  return *this;
}

/*
 *                  Functions
 * */

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  } else
    std::cout << MAG "[PresidentialPardonForm] " W << this->_target
              << " has been pardoned by Zaphod Beeblebrox" NC << std::endl;
}
