#include "include/functions.h"
#include <cmath>
#include <iostream>

constexpr double pi = 3.1415926535;

bool evalTest() {
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

bool evalDiffTest() {
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

bool unitTest() {
  if (evalTest() == 1 || evalDiffTest() == 1)
    return 1;
  return 0;
}
