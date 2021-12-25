#include "functions.h"
#include <iostream>
#include <vector>

int main() {
  if (!polySolve_test())
    return 1;
  std::cout << "\nUnit test successful!\n\n";

  int nt;     // Number of terms in the equation seperated by addition
  double x0;  // Guess solution
  double tol; // Tolerance
  int miter;  // Maximum iterations
  std::vector<std::vector<double>> eq;    // Vector to store equation
  getEq(nt, x0, tol, miter, eq);          // Get equation from user
  x0 = polySolve(nt, x0, tol, miter, eq); // Solve the equation
}
