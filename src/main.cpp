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

  std::ofstream logfile;
  logfile.open("log.csv", std::ios_base::app);
  for (auto i = 0; i < 10; i++) {

    auto start = std::chrono::system_clock::now();
    eq.solve(x0, tol, miter); // Solve the equation
    auto end = std::chrono::system_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    logfile << elapsed.count() << ',';
  }
  logfile.close();
}
