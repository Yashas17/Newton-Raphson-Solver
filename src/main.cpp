#include "include/equation.h"
#include "include/functions.h"
#include "include/readData.h"
#include "test/unittest.h"
#include <iostream>
#include <vector>

int main() {

  if (unitTest() != 0) {
    return 1;
  }                              // Unit Tests
  double x0;                     // Guess solution
  double tol;                    // Tolerance
  int miter;                     // Maximum iterations
  equation eq;                   // Vector to store equation
  readData(x0, tol, miter, eq);  // Read Data
  x0 = eq.solve(x0, tol, miter); // Solve the equation
}
