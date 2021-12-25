#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "functions.cpp"
#include <cmath>
#include <iostream>
#include <vector>

void getEq(int &nt, double &x0, double &tol, int &miter,
           std::vector<std::vector<double>>
               &eq); // Function to get equation and parameters from user
double f(double x, const std::vector<std::vector<double>>
                       &eq); // Function to evaluate equation at given x
void polyDiff(const std::vector<std::vector<double>> &eq,
              std::vector<std::vector<double>>
                  &eq1); // Function to differentiate the given equation
double polySolve(int nt, double x0, double tol, int miter,
                 std::vector<std::vector<double>>
                     eq); // Function to solve the given equation
bool polySolve_test();    // Test function for polynomial equation solver

#endif