/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:26:04 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:26:04 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

/*
 *                  Constructors
 * */

ShruberryCreationForm::ShruberryCreationForm()
    : AForm("ShruberryCreationForm", 145, 137), _target("Unknown") {
  std::cout << GRN "[ShruberryCreationForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been created!" NC
            << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(std::string const &_target)
    : AForm("ShruberryCreationForm", 145, 137), _target(_target) {
  std::cout << GRN "[ShruberryCreationForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been created!" NC
            << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(
    ShruberryCreationForm const &origin) : AForm(origin){
  (void)origin;
}

/*
 *                  Destructors
 * */

ShruberryCreationForm::~ShruberryCreationForm() {
  std::cout << RED "[ShruberryCreationForm] " W << this->getName()
            << "(S:" << this->getGradeToSign()
            << ")(E:" << this->getGradeToExec() << ") has been destroyed!" NC
            << std::endl;
}

/*
 *                  Overload operators
 * */

ShruberryCreationForm &
ShruberryCreationForm::operator=(ShruberryCreationForm const &origin) {
  (void)origin;
  return *this;
}

/*
 *                  Functions
 * */

void ShruberryCreationForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  } else {
    std::ofstream f;
    std::string str = this->_target + "_shrubbery";
    f.open(str.c_str());
    f << "                     / / /" << std::endl;
    f << "               /        /  /     //    /" << std::endl;
    f << "            /                 /         /  /" << std::endl;
    f << "                            /" << std::endl;
    f << "                           /                //" << std::endl;
    f << "           /          /            /              /" << std::endl;
    f << "           /            '/,        /               /" << std::endl;
    f << "           /              'b      *" << std::endl;
    f << "            /              '$    //                //" << std::endl;
    f << "           /    /           $:   /:               /" << std::endl;
    f << "         //      /  //      */  @):        /   / /" << std::endl;
    f << "                      /     :@,@):   ,/**:'   /" << std::endl;
    f << "          /      /,         :@@*: //**'      /   /" << std::endl;
    f << "                   '/o/    /:(@'/@*\"'  /" << std::endl;
    f << "           /  /       'bq,//:,@@*'   ,*      /  /" << std::endl;
    f << "                      ,p$q8,:@)'  /p*'      /" << std::endl;
    f << "               /     '  / '@@Pp@@*'    /  /" << std::endl;
    f << "                /  / //    Y7'.'     /  /" << std::endl;
    f << "                          :@):." << std::endl;
    f << "                         .:@:'." << std::endl;
    f << "                       .::(@:.      -Sam Blumenstein-" << std::endl;
    f.close();
  }
}
