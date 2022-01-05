#include "specialFunction.h"
#include <cmath>

class None : specialFunction {
public:
  virtual double eval(const double x) override { return 1; }
  virtual double evalDiff(const double x) override { return 0; }
};

class Sine : specialFunction {
public:
  virtual double eval(const double x) override { return sin(x); }
  virtual double evalDiff(const double x) override { return cos(x); }
};

class Cosine : specialFunction {
public:
  virtual double eval(const double x) override { return cos(x); }
  virtual double evalDiff(const double x) override { return -sin(x); }
};

class Tangent : specialFunction {
public:
  virtual double eval(const double x) override { return tan(x); }
  virtual double evalDiff(const double x) override {
    return 1. / (cos(x) * cos(x));
  }
};

class Cotangent : specialFunction {
public:
  virtual double eval(const double x) override { return 1. / tan(x); }
  virtual double evalDiff(const double x) override {
    return -1. / (sin(x) * sin(x));
  }
};

class Secant : specialFunction {
public:
  virtual double eval(const double x) override { return 1. / cos(x); }
  virtual double evalDiff(const double x) override { return tan(x) / cos(x); }
};

class Cosecant : specialFunction {
public:
  virtual double eval(const double x) override { return 1. / sin(x); }
  virtual double evalDiff(const double x) override {
    return -1. / (sin(x) * tan(x));
  }
};

class Logarithm : specialFunction {
public:
  virtual double eval(const double x) override { return log(x); }
  virtual double evalDiff(const double x) override { return 1 / x; }
};

class Logarithm10 : specialFunction {
public:
  virtual double eval(const double x) override { return log10(x); }
  virtual double evalDiff(const double x) override {
    return log10(exp(1.)) / x;
  }
};

class Exponential : specialFunction {
public:
  virtual double eval(const double x) override { return exp(x); }
  virtual double evalDiff(const double x) override { return exp(x); }
};