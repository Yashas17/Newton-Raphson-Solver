#include<iostream>
#include<vector>
#include"functions.h"

int main()
{
    int nt;    //number of terms in the equation seperated by addition
    double x0;     //guess solution
    double tol;    //tolerance
    int miter;  //maximum iterations
    std::vector<std::vector<double>> eq; //vector to store equation
    getEq(nt,x0,tol,miter,eq);
    polySolve(nt,x0,tol,miter,eq);
}
