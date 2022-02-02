#include "include/equation.h"
#include "include/functions.h"
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

constexpr double pi = 3.1415926535;

bool evalTest() { // Function to test eval() function implemented in
                  // functions.cpp
  double sol[10] = {
      1, sin(pi / 2.), cos(0.),   tan(0.), 1. / tan(pi / 2.), 1 / cos(pi),
      1, log(pi),      log10(pi), 1};

  double testx[10] = {
      1., pi / 2, 0., 0., pi / 2., pi, pi / 2., pi, pi, 0.,
  };
  for (auto i = 0; i < 10; i++) {
    if ((eval(i, testx[i])) != sol[i]) {
      std::cout << "Check eval() for function number" << i << "\n";
      return 1;
    }
  }
  std::cout << "eval() working as expected.\n";
  return 0;
}

bool evalDiffTest() { // Function to test evalDiff() function implemented in
                      // functions.cpp
  double solDiff[10] = {0.,
                        cos(pi),
                        -sin(pi / 2.),
                        1. / (cos(pi) * cos(pi)),
                        -1. / (sin(pi / 2.) * sin(pi / 2.)),
                        tan(0.) / cos(0.),
                        -1. / (sin(pi / 2.) * tan(pi / 2.)),
                        1.,
                        0.,
                        exp(0.)};
  double test[10] = {
      1, pi, pi / 2, pi, pi / 2, 0, pi / 2., 1., INFINITY, 0.,
  };
  for (auto i = 0; i < 10; i++) {
    if (evalDiff(i, test[i]) != solDiff[i]) {
      std::cout << "Check evalDiff() for function number" << i << "\n";
      return 1;
    }
  }
  std::cout << "evalDiff() working as expected.\n";
  return 0;
}

bool evaluateTest() { // Function to test evaluate() function implemented in
                      // equations.cpp
  std::vector<double> c = {1., -2};
  std::vector<double> p = {2., 0.};
  std::vector<unsigned int> f = {1, 7};
  equation eq(p, c, f);
  double x = 0.5;
  std::array<double, 2> a;
  eq.evaluate(a,x);
  double x1 = pow(x, 2.) * sin(x) - 2 * log(x);
  double x2 = pow(x, 2.) * cos(x) - 2 * x * sin(x) - 2. / x;
  if (fabs(a[0] - x1) > 1e-4 || fabs(a[0] - x1) > 1e-4) {
    std::cout << "Check evaluate()";
    return 1;
  }
  std::cout << "evaluate() working as expected.\n";
  return 0;
}

bool unitTest() {
  std::cout << "\n";
  if (evalTest() == 1 || evalDiffTest() == 1 || evaluateTest() == 1)
    return 1;
  return 0;
}

int main() {
  if (unitTest() != 0) {
    return 1;
  }
}