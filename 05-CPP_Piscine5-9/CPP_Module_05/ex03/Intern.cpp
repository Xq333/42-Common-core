/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:37:29 by xq                #+#    #+#             */
/*   Updated: 2023/09/26 14:37:29 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
 *            Constructors
 * */

Intern::Intern(){
  std::cout << GRN "[Intern]" W " An intern has been created!" << std::endl;
}

Intern::Intern(Intern const &origin){
  (void)origin;
  std::cout << GRN "[Intern]" W " An intern has been created!" << std::endl;
}

/*
 *            Destructor
 * */

Intern::~Intern(){
  std::cout << RED "[Intern]" W " An intern has been created!" << std::endl;
}

/*
 *            Overload operators
 * */

Intern &Intern::operator=(Intern const &origin){
  (void)origin;
  return *this;
}

/*
 *            Functions
 * */

std::string toLowerStr(std::string const origin){
  std::string str;
  for (unsigned int i = 0; i < origin.size(); i++)
    str += tolower(origin[i]);
  return str;
}

AForm *newShruberry(std::string const &target){
  return new ShruberryCreationForm(target);
}

AForm *newRobotomy(std::string const &target){
  return new RobotomyRequestForm(target);
}

AForm *newPresidential(std::string const &target){
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const name, std::string const target){
  std::string formName[3] = {"ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
  std::string const form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm *(*f[3])(std::string const &) = {&newShruberry, &newRobotomy, &newPresidential};

  for (int i = 0; i < 3; i++)
  {
    if (toLowerStr(name).compare(form[i]) == 0)
    {
      std::cout << MAG "[Intern] " W "Intern creates " << formName[i] << "!" NC << std::endl; 
      return f[i](target);
    }
  }
  std::cout << YEL "[Intern] " W "Intern try to make a " << name << "... But it does not work." NC << std::endl; 
  return NULL;
}
