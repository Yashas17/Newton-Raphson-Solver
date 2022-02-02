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
  readData(x0, tol, miter, eq); // Calling the function to read data from json file and store it in the corresponding variables
  eq.solve(x0, tol, miter);     // SCalling the function to solve the function and print the results
}
