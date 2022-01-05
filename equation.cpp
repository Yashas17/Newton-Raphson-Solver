#include "equation.h"
#include "specialFunction.cpp"
#include "specialFunction.h"
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

equation::equation(const std::vector<double> &p, const std::vector<double> &c,
                   const std::vector<unsigned int> &f)
    : _p(p), _c(c) {
  for (auto i = 0; i < _p.size(); i++) {
    switch (f[i]) {
    case 0:
      _f.push_back(std::make_unique<None>);
      break;
    case 1:
      _f.push_back(std::make_unique<Sine>);
      break;
    case 2:
      _f.push_back(std::make_unique<Cosine>);
      break;
    case 3:
      _f.push_back(std::make_unique<Tangent>);
      break;
    case 4:
      _f.push_back(std::make_unique<Cotangent>);
      break;
    case 5:
      _f.push_back(std::make_unique<Secant>);
      break;
    case 6:
      _f.push_back(std::make_unique<Cosecant>);
      break;
    case 7:
      _f.push_back(std::make_unique<Logarithm>);
      break;
    case 8:
      _f.push_back(std::make_unique<Logarithm10>);
      break;
    case 9:
      _f.push_back(std::make_unique<Exponential>);
      break;
    }
  }
};

std::array<double, 2> equation::evaluate(double x) const {
  std::array<double, 2> temp;
  temp[0] = 0;
  for (auto i = 0; i < _p.size(); i++) {
    if (_c[i] != 0)
      temp[0] += _c[i] * pow(x, _p[i]) * _f[i]->eval(x);
  }
  if (fabs(temp[0]) < 1e-14)
    std::cout << "\nWARNING!\nThe value of the differentiated function is "
                 "close or equal to zero which can lead to large errors!\n";
  temp[1] = 0;
  for (auto i = 0; i < _p.size(); i++) {
    if (_c[i] != 0)
      temp[1] = _c[i] * pow(x, _p[i]) * _f[i]->evalDiff(x) +
                _c[i] * _p[i] * pow(x, _p[i] - 1) * _f[i]->eval(x);
  }
  return temp;
}

double equation::solve(double x0, double tol, int miter) {
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