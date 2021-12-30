#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <vector>

class equation {
private:
  std::vector<std::vector<double>> _eq;

public:
  equation(std::vector<std::vector<double>> &eq); // constructor
  double evaluate(double x); // function to evaluate the equation at given point
  equation diff();           // function to differentiate an equation
};

#endif