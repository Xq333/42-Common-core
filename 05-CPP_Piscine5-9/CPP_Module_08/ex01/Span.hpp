/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:12:18 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:19 by pfaria-d         ###   ########.fr       */
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
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

class Span {
public:
  Span();
  Span(size_t N);
  Span(Span const &origin);
  ~Span();

  Span &operator=(Span const &origin);

  void addNumber(int nb);
  int shortestSpan() const;
  int longestSpan() const;
  void generateRange(size_t N);

  class isFull : std::exception {
  public:
    virtual const char *what() throw() { return "Error: vector is full!"; }
  };

  class notEnoughValues : std::exception {
  public:
    virtual const char *what() throw() { return "Error: not enough values!"; }
  };

private:
  size_t _N;
  std::vector<int> _vector;
};
