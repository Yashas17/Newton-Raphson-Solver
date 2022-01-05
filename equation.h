#ifndef EQUATION_H
#define EQUATION_H

#include "specialFunction.h"
#include <iostream>
#include <memory>
#include <vector>

class equation {
private:
  std::vector<double> _p;                           // power of x
  std::vector<double> _c;                           // coefficient
  std::vector<std::unique_ptr<specialFunction>> _f; // special function

public:
  equation(const std::vector<double> &p, const std::vector<double> &c,
           const std::vector<unsigned int> &f); // constructor

  std::array<double, 2>
  evaluate(double x) const; // function to evaluate the equation
                            // and its derivative at given point

  double solve(const equation &eq, double tol, double x0, double miter);
};

#endif