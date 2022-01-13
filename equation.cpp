#include "equation.h"

#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

equation::equation(const std::vector<double> &p, const std::vector<double> &c,
                   const std::vector<unsigned int> &f)
    : _p(p), _c(c), _f(f){};

std::array<double, 2> equation::evaluate(double x) const {
  std::array<double, 2> temp;
  temp[0] = 0;
  for (auto i = 0; i < _p.size(); i++) {
    if (_c[i] != 0)
      temp[0] += _c[i] * pow(x, _p[i]) * eval(_f[i], x);
  }
  temp[1] = 0;
  for (auto i = 0; i < _p.size(); i++) {
    if (_c[i] != 0)
      temp[1] = _c[i] * pow(x, _p[i]) * evalDiff(_f[i], x) +
                _c[i] * _p[i] * pow(x, _p[i] - 1) * eval(_f[i], x);
  }
  if (fabs(temp[1]) < 1e-14)
    std::cout << "\nWARNING!\nThe value of the differentiated function is "
                 "close or equal to zero which can lead to large errors!\n";
  return temp;
}

double equation::solve(double x0, const double tol, const int miter) {
  double res;   // Residual to check for convergence
  auto ctr = 0; // Counter for number of iterations
  do {
    double x;
    std::array<double, 2> f = evaluate(x0);
    x = x0 - f[0] / f[1];
    res = fabs(x - x0); // Absolute difference between solution of previous and
                        // current iteration
    x0 = x;             // Updating solution
    ctr++;
    if (ctr > miter) // Check if maximum number of iterations have been reached
    {
      std::cout << "\n Maximum number of iterations reached!\n"
                << "x=" << x0 << "\nResidual=" << res << std::endl;
      break;
    }
  } while (res > tol); // Iterate till the solution converges

  if (ctr <= miter)
    std::cout << "\nThe solution is:" << x0
              << "\nThe number of iterations is:" << ctr
              << "\nResidual is:" << res << std::endl;

  return x0;
}