#include "equation.h"
#include "functions.h"
#include "readData.cpp"
#include <iostream>
#include <vector>

int main() {

  double x0;                     // Guess solution
  double tol;                    // Tolerance
  int miter;                     // Maximum iterations
  equation eq;                   // Vector to store equation
  readData(x0, tol, miter, eq);  // Read Data
  x0 = eq.solve(x0, tol, miter); // Solve the equation
  std::cout << x0;
}
