/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:25:42 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:25:43 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
 *                  Constructors
 * */

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Unknown") {
  std::cout << GRN "[RobotomyRequestForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been created!" NC
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &_target)
    : AForm("RobotomyRequestForm", 72, 45), _target(_target) {
  std::cout << GRN "[RobotomyRequestForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been created!" NC
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &origin)
    : AForm(origin) {
  (void)origin;
}

/*
 *                  Destructors
 * */

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << RED "[RobotomyRequestForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been destroyed!" NC
            << std::endl;
}

/*
 *                  Overload operators
 * */

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &origin) {
  (void)origin;
  return *this;
}

/*
 *                  Functions
 * */

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  } else {
    if (std::time(0) % 2)
      std::cout << MAG "[RobotomyRequestForm] " W << this->_target
                << " has been robotomized" NC << std::endl;
    else
      std::cout << "[RobotomyRequestForm] " W U << this->_target
                << "... robotomization failed!" NC << std::endl;
  }
}
