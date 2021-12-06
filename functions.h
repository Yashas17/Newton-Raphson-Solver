#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>
#include<cmath>
#include "functions.cpp"

void getEq(int &nt,double &x0,double &tol,int &miter,std::vector<std::vector<double>> &eq);
double f(double x,const std::vector<std::vector<double>>& eq);
void polyDiff(const std::vector<std::vector<double>>& eq, std::vector<std::vector<double>>& eq1);
double polySolve(int nt, double x0, double tol, int miter, std::vector<std::vector<double>> eq);
bool polySolve_test();

#endif