#include "include/equation.h"
#include "include/functions.h"
#include "include/readData.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

int main() {
  double x0;                    // Guess solution
  double tol;                   // Tolerance
  int miter;                    // Maximum iterations
  equation eq;                  // Vector to store equation
  readData(x0, tol, miter, eq); // Read Data
  eq.solve(x0, tol, miter);     // Solve the equation
}
