#ifndef SPECIALFUNCTION_H
#define SPECIALFUNCTION_H

class specialFunction {
public:
  virtual double eval(const double x) = 0;
  virtual double evalDiff(const double x) = 0;
};

#endif