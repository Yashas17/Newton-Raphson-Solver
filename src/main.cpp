#include "include/equation.h"
#include "include/functions.h"
#include "include/readData.h"
#include <iostream>
#include <vector>
#include "test/unittest.h"
#include "test/unittestDiff.h"


int main() {
  if(unittest()==1 && unittestDiff()==1) std::cout<<"Unit tests ran successfully";

  double x0;                     // Guess solution
  double tol;                    // Tolerance
  int miter;                     // Maximum iterations
  equation eq;                   // Vector to store equation
  readData(x0, tol, miter, eq);  // Read Data
  x0 = eq.solve(x0, tol, miter); // Solve the equation
}
