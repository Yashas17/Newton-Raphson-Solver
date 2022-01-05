#include "equation.h"
#include "functions.h"
#include <iostream>
#include <vector>

int main() {
  if (!polySolve_test())
    return 1;
  std::cout << "\nUnit test successful!\n\n";

  double x0 = getx0();           // Guess solution
  double tol = getTol();         // Tolerance
  int miter = getMiter();        // Maximum iterations
  equation eq = getEq();         // Vector to store equation
  x0 = eq.solve(x0, tol, miter); // Solve the equation
}
