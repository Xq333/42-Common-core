/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:19:46 by xq                #+#    #+#             */
/*   Updated: 2023/09/22 08:19:46 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 *            Constructors
 * */

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {
  std::cout << GRN "[Bureaucrat] " W << this->_name << "(" << this->_grade
            << ") has been created!" NC << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade)
    : _name(name) {
  try {
    if (grade > 150) {
      throw Bureaucrat::GradeTooLowException();
    }
    if (grade < 1)
      throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
  } catch (Bureaucrat::GradeTooLowException &e) {

    std::cout << YEL "[Bureaucrat] " W << this->_name << "(" << grade << ")... "
              << e.what() << " Grade will be set to 150." NC << std::endl;
    this->_grade = 150;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << YEL "[Bureaucrat] " W << this->_name << "(" << grade << ")... "
              << e.what() << " Grade will be set to 1." NC << std::endl;
    this->_grade = 1;
  }
  std::cout << GRN "[Bureaucrat] " W << this->_name << "(" << this->_grade
            << ") has been created!" NC << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &origin)
    : _name(origin._name), _grade(origin._grade) {
  std::cout << GRN "[Bureaucrat] " W << this->_name << "(" << this->_grade
            << ") has been copied!" NC << std::endl;
}

/*
 *            Destructor
 * */

Bureaucrat::~Bureaucrat() {
  std::cout << RED "[Bureaucrat] " W << this->_name << "(" << this->_grade
            << ") has been destroyed!" NC << std::endl;
}

/*
 *            Overload operators
 * */

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &origin) {
  if (this != &origin) {
    this->_grade = origin._grade;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
  o << CYA "[Bureaucrat] " W << bureaucrat.getName() << ", grade "
    << bureaucrat.getGrade() << "!" NC << std::endl;
  return (o);
}

/*
 *             Getters/Setters
 * */

unsigned int const &Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::setGrade(unsigned int grade) {
  try {
    std::cout << MAG "[Bureaucrat] " W << this->getName() << " -> "
              << this->getGrade() << " >> " << grade << NC << std::endl;
    if (grade > 150)
      throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
      throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    std::cout << CYA "[Bureaucrat] Grade has been set!" NC << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << YEL "[Bureaucrat] " << e.what() << NC << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << YEL "[Bureaucrat] " << e.what() << NC << std::endl;
  }
}

std::string const &Bureaucrat::getName() const { return this->_name; }

/*
 *            Functions
 * */

void Bureaucrat::incrementGrade() {
  std::cout << MAG "[Increment]";
  this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
  std::cout << MAG "[Decrement]";
  this->setGrade(this->getGrade() + 1);
}
