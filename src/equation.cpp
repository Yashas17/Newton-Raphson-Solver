#include "include/equation.h"
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

/**
Constructor for class equation
**/
equation::equation(const std::vector<double> &p, const std::vector<double> &c,
                   const std::vector<unsigned int> &f)
                   : _p(p), _c(c), _f(f){};

/**
This function evaluates the value of equation and its derivative at a particular instance of x
These values are stored in corresponding elements of 'temp'. We also check whether the value of 
differentiated function is too close to zero, which is a limitation of the Newton-Raphson 
algorithm and can lead to large errors.
**/
void equation::evaluate(
    std::array<double, 2> &temp,
    double x) const { 

  temp[0] = 0;                                  // First element stores the value of original equation at x
  temp[1] = 0;                                  // Second element stores the value of derivative of equation at x

/**
We follow the chain rule of differentiation to calculate value of derivative of equation at a particular x
**/
  for (auto i = 0; i < _p.size(); i++) {
    if (_p[i] != 0) {                           // Power zero sometimes creates errors thus handling the
                                                // case manually
      temp[0] += _c[i] * pow(x, _p[i]) * eval(_f[i], x);
      temp[1] += _c[i] * pow(x, _p[i]) * evalDiff(_f[i], x) +
                 _c[i] * _p[i] * pow(x, _p[i] - 1) * eval(_f[i], x);
    } else {
      temp[0] += _c[i] * eval(_f[i], x);
      temp[1] += _c[i] * evalDiff(_f[i], x);
    }
  }
  if (fabs(temp[1]) < 1e-14) {
    std::cout << "\nWARNING!\nThe value of the differentiated function is "
                 "close or equal to zero which can lead to large errors!\n";
  }
}
/**
This function carries out the actual Newton-Raphson algorithm to generate the solution. 
If the iterations exceed the maximum number of iterations allowed or the residuals falls below 
the tolerance value, the solution, number of iterations and residual is printed.
**/
void equation::solve(double x0, const double tol,
                     const int miter) { 

  double res;                                   // Residual to check for convergence
  auto ctr = 0;                                 // Counter for number of iterations
  std::array<double, 2> f;
  do {
    double x;
    evaluate(f, x0);
    x = x0 - f[0] / f[1];
    res = fabs(x - x0);                         // Absolute difference between solution of previous and
                                                // current iteration
    x0 = x;                                     // Updating solution
    ctr++;
    if (ctr > miter)                            // Check if maximum number of iterations have been reached
    {
      std::cout << "\n Maximum number of iterations reached!\n"
                << "x= " << x0 << "\nResidual= " << res << std::endl;
      break;
    }
  } while (res > tol);                          // Iterate till the solution converges

  if (ctr <= miter)
    std::cout << "\nThe solution is: " << x0
              << "\nThe number of iterations is: " << ctr
              << "\nResidual is: " << res << std::endl
              << std::endl;
}
