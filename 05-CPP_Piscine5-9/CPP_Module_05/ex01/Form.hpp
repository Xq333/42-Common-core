/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:37:32 by xq                #+#    #+#             */
/*   Updated: 2023/09/22 10:37:33 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
public:
  Form();
  Form(std::string const name, unsigned int const gradeToSign,
       unsigned int const _gradeToExecute);
  Form(Form const &origin);
  ~Form();

  Form &operator=(Form const &origin);

  std::string const &getName() const;
  bool const &getSigned() const;
  unsigned int const &getGradeToSign() const;
  unsigned int const &getGradeToExec() const;
  void beSigned(Bureaucrat &b);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() throw() { return "Error: Grade too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() throw() { return "Error: Grade too low"; }
  };

private:
  std::string const _name;
  bool _signed;
  unsigned int const _gradeToSign;
  unsigned int const _gradeToExec;
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);
