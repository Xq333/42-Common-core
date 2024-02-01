/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:19:52 by xq                #+#    #+#             */
/*   Updated: 2023/09/22 08:19:53 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define RED "\033[1;31m" // FOR DESTRUCTORS
#define GRN "\033[1;32m" // FOR CONSTRUCTORS
#define YEL "\033[1;33m" // FOR ERRORS
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define W "\033[1;97m"
#define NC "\033[1;0m"
#define I "\033[1;3m"
#define U "\033[1;4m"

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(std::string const _name, unsigned int grade);
  Bureaucrat(Bureaucrat const &origin);
  ~Bureaucrat();

  Bureaucrat &operator=(Bureaucrat const &origin);

  unsigned int const &getGrade() const;
  void setGrade(unsigned int grade);
  std::string const &getName() const;
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() throw() { return "Error: Grade too high!"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() throw() { return "Error: Grade too low!"; }
  };

private:
  std::string const _name;
  unsigned int _grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);
