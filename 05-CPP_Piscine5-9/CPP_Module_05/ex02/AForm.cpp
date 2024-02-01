/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:37:29 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:54:15 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
 *            Constructors
 * */

AForm::AForm()
    : _name("Unnamed"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
  std::cout << GRN "[AForm] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been created!" NC
            << std::endl;
}

AForm::AForm(std::string const name, unsigned int gradeToSign,
             unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExecute) {
  if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
    throw AForm::GradeTooLowException();
  if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
    throw AForm::GradeTooHighException();
  std::cout << GRN "[AForm] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been created!" NC
            << std::endl;
}

AForm::AForm(AForm const &origin)
    : _name(origin._name), _gradeToSign(origin._gradeToSign),
      _gradeToExec(origin._gradeToExec) {
  std::cout << GRN "[AForm] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been created!" NC
            << std::endl;
}

/*
 *            Destructor
 * */

AForm::~AForm() {
  std::cout << RED "[AForm] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been destroyed!" NC
            << std::endl;
}

/*
 *            Overload operators
 * */

AForm &AForm::operator=(AForm const &origin) {
  if (this != &origin) {
    this->_signed = origin._signed;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &ostream, const AForm &form) {
  ostream << CYA "[Form] " W << form.getName() << " is "
          << (form.getSigned() ? "signed" : "not signed")
          << ". Grade to sign: " << form.getGradeToSign()
          << ", Grade to execute: " << form.getGradeToExec() << NC << std::endl;
  return ostream;
}

/*
 *             Getters/Setters
 * */

std::string const &AForm::getName() const { return this->_name; }

bool const &AForm::getSigned() const { return this->_signed; }

unsigned int const &AForm::getGradeToSign() const { return this->_gradeToSign; }

unsigned int const &AForm::getGradeToExec() const { return this->_gradeToExec; }

void AForm::beSigned(Bureaucrat &b) {
  try {
    if (b.getGrade() > this->getGradeToSign())
      throw AForm::GradeTooLowException();
    this->_signed = true;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << e.what() << NC << std::endl;
  }
}
