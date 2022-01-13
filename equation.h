#ifndef EQUATION_H
#define EQUATION_H

#include "functions.h"
#include <iostream>
#include <memory>
#include <vector>

class equation {
private:
  std::vector<double> _p;       // Power of x
  std::vector<double> _c;       // Coefficient
  std::vector<unsigned int> _f; // Special function

public:
  equation() = default; // Default constructor
  equation(const std::vector<double> &p, const std::vector<double> &c,
           const std::vector<unsigned int> &f); // Constructor

  std::array<double, 2>
  evaluate(double x) const; // Function to evaluate the equation
                            // and its derivative at given point

  double solve(double x0, const double tol,
               const int miter); // Function to solve equation
};

#endif