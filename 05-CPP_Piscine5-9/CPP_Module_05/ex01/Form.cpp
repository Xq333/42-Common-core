/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:37:29 by xq                #+#    #+#             */
/*   Updated: 2023/09/22 10:37:30 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
 *            Constructors
 * */

Form::Form()
    : _name("Unnamed"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
  std::cout << GRN "[Form] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been created!" NC
            << std::endl;
}

Form::Form(std::string const name, unsigned int gradeToSign,
           unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExecute) {
  if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
    throw Form::GradeTooLowException();
  if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
    throw Form::GradeTooHighException();
  std::cout << GRN "[Form] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been created!" NC
            << std::endl;
}

Form::Form(Form const &origin)
    : _name(origin._name), _gradeToSign(origin._gradeToSign),
      _gradeToExec(origin._gradeToExec) {
  std::cout << GRN "[Form] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been created!" NC
            << std::endl;
}

/*
 *            Destructor
 * */

Form::~Form() {
  std::cout << RED "[Form] " W << this->_name << "(S:" << this->_gradeToSign
            << ")(E:" << this->_gradeToExec << ") has been destroyed!" NC
            << std::endl;
}

/*
 *            Overload operators
 * */

Form &Form::operator=(Form const &origin) {
  if (this != &origin) {
    this->_signed = origin._signed;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &ostream, const Form &form) {
  ostream << CYA "[Form] " W << form.getName() << " is "
          << (form.getSigned() ? "signed" : "not signed")
          << ". Grade to sign: " << form.getGradeToSign()
          << ", Grade to execute: " << form.getGradeToExec() << NC << std::endl;
  return ostream;
}

/*
 *             Getters/Setters
 * */

std::string const &Form::getName() const { return this->_name; }

bool const &Form::getSigned() const { return this->_signed; }

unsigned int const &Form::getGradeToSign() const { return this->_gradeToSign; }

unsigned int const &Form::getGradeToExec() const { return this->_gradeToExec; }

void Form::beSigned(Bureaucrat &b) {
  try {
    if (b.getGrade() > this->getGradeToSign())
      throw Form::GradeTooLowException();
    this->_signed = true;
  } catch (Form::GradeTooLowException &e) {
    std::cout << e.what() << NC << std::endl;
  }
}
