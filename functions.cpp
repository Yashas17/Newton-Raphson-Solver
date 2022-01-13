#include "functions.h"
#include <cmath>

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