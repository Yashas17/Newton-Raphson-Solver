#include "equation.h"
#include <cmath>
#include <iostream>
#include <vector>

equation::equation(std::vector<std::vector<double>> &eq) : _eq(eq){};

double equation::evaluate(double x) {
  double sum = 0;
  for (auto i = 0; i < _eq.size(); i++) {
    if (_eq[i][1] != 0)
      sum += _eq[i][1] * pow(x, _eq[i][0]);
  }
  auto y = sum;
  if (y < 0)
    y = -y;
  if (y < 1e-14)
    std::cout << "\nWARNING!\nThe value of the differentiated function is "
                 "close or equal to zero which can lead to large errors!\n";
  return sum;
}

equation equation::diff() {
  std::vector<std::vector<double>> eq = _eq;
  return eq;
};