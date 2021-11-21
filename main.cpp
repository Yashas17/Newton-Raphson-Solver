#include<iostream>
#include<vector>

int main()
{
    int nt;    //number of terms in the equation seperated by addition
    int x0;     //guess solution
    int tol;    //tolerance
    int miter;  //maximum iterations
    std::vector<std::vector<double>> eq; //vector to store equation
    getEq(nt,x0,tol,miter,eq);
    polySolve(x0,tol,miter,eq);
    return 0;
}