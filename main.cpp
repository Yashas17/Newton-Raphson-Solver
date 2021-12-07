#include<iostream>
#include<vector>
#include"functions.h"

int main()
{
    if(!polySolve_test()) return 1;
    std::cout<<"\nUnit test successful!\n\n";

    int nt;                                 //number of terms in the equation seperated by addition
    double x0;                              //guess solution
    double tol;                             //tolerance
    int miter;                              //maximum iterations
    std::vector<std::vector<double>> eq;    //vector to store equation
    getEq(nt,x0,tol,miter,eq);              //Get equation from user
    x0=polySolve(nt,x0,tol,miter,eq);       //Solve the equation
}
