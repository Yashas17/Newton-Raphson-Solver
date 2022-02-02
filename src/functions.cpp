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

In the future, the user can add his/her own functions and their derivatives in the respective lists and extend functionality
provided the corresponding assert statements are also changed.
*/

double eval(const unsigned int f, const double x) {
  switch (f) {
  case 0:
    return 1;
  case 1:
    return sin(x);
  case 2:
    return cos(x);
  case 3:
    return tan(x);
  case 4:
    return 1. / tan(x);
  case 5:
    return 1. / cos(x);
  case 6:
    return 1. / sin(x);
  case 7:
    return log(x);
  case 8:
    return log10(x);
  case 9:
    return exp(x);
  }
}

double evalDiff(const unsigned int f, const double x) {
  switch (f) {
  case 0:
    return 0;
  case 1:
    return cos(x);
  case 2:
    return -sin(x);
  case 3:
    return 1. / (cos(x) * cos(x));
  case 4:
    return -1. / (sin(x) * sin(x));
  case 5:
    return tan(x) / cos(x);
  case 6:
    return -1. / (sin(x) * tan(x));
  case 7:
    return 1. / x;
  case 8:
    return 1. / (x * log(10.));
  case 9:
    return exp(x);
  }
}
