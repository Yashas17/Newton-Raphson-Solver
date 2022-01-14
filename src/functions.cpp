#include "include/functions.h"
#include <cmath>

/*
eval() and evalDiff() methods return value of the special functions and thier
derivate respectively at given x. The special functions are identified by the
following numbers:

0: none
1: sin(x)
2: cos(x)
3: tan(x)
4: cot(x)
5: sec(x)
6: cosec(x)
7: log(x)
8: log10(x)
9: exp(x)
*/

double eval(const unsigned int f, const double x) {
  switch (f) {
  case 0:
    return 1;
    break;
  case 1:
    return sin(x);
    break;
  case 2:
    return cos(x);
    break;
  case 3:
    return tan(x);
    break;
  case 4:
    return 1. / tan(x);
    break;
  case 5:
    return 1. / cos(x);
    break;
  case 6:
    return 1. / sin(x);
    break;
  case 7:
    return log(x);
    break;
  case 8:
    return log10(x);
    break;
  case 9:
    return exp(x);
    break;
  }
}

double evalDiff(const unsigned int f, const double x) {
  switch (f) {
  case 0:
    return 0;
    break;
  case 1:
    return cos(x);
    break;
  case 2:
    return -sin(x);
    break;
  case 3:
    return 1. / (cos(x) * cos(x));
    break;
  case 4:
    return -1. / (sin(x) * sin(x));
    break;
  case 5:
    return tan(x) / cos(x);
    break;
  case 6:
    return -1. / (sin(x) * tan(x));
    break;
  case 7:
    return 1. / x;
    break;
  case 8:
    return 1. / (x * log(10.));
    break;
  case 9:
    return exp(x);
    break;
  }
}
