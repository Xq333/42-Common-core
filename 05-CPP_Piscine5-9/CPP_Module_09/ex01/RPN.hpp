/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:06 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/18 15:24:07 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <iostream>
#include <stack>

class RPN {
public:
  RPN();
  RPN(RPN const &origin);
  ~RPN();

  RPN &operator=(RPN const &origin);

  int RPNcalc(std::string str);

  class div0 : std::exception {
  public:
    virtual const char *what() throw() { return RED "Divided by 0." NC; }
  };

  class badCalc : std::exception {
  public:
    virtual const char *what() throw() {
      return RED "Incorrect calculation!" NC;
    }
  };

private:
  std::stack<int> _stack;
};
