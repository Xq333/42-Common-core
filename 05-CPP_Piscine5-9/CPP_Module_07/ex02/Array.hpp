/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:11:12 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/01 16:11:12 by pfaria-d         ###   ########.fr       */
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
#include <cstdlib>
#include <iostream>

template <class T> class Array {
public:
  Array() : _array(NULL), _len(0) {
    std::cout << GRN "[Array] " W
                     "An array has been created, the len of the array is "
              << this->_len << "!" NC << std::endl;
  }
  Array(unsigned int n) : _array(new T[n]), _len(n) {
    std::cout << GRN "[Array] " W
                     "An array has been created, the len of the array is "
              << this->_len << "!" NC << std::endl;
  }
  Array(Array const &origin) : _array(new T[origin._len]), _len(origin._len) {
    for (unsigned int i = 0; i < this->_len; i++)
      this->_array[i] = origin._array[i];
    std::cout << GRN "[Array] " W
                     "An array has been created, the len of the array is "
              << this->_len << "!" NC << std::endl;
  };
  ~Array() {
    std::cout << RED "[Array] " W
                     "An array has been destroyed, the len of the array was "
              << this->_len << "!" NC << std::endl;
    delete[] this->_array;
  }

  Array<T> &operator=(Array<T> const &origin) {
    delete[] this->_array;
    this->_array = new T[origin._len];
    for (unsigned int i = 0; i < origin._len; i++)
      this->_array[i] = origin._array[i];
    this->_len = origin._len;
    return *this;
  }

  T &operator[](unsigned int i) {
    if (this->_len - 1 < i) {
      throw Array::outOfBounds();
    }
    return this->_array[i];
  }

  class outOfBounds : public std::exception {
  public:
    virtual const char *what() throw() {
      return "Error: Index is out of bounds!";
    }
  };

  unsigned int size() const { return this->_len; }

private:
  T *_array;
  unsigned int _len;
};
