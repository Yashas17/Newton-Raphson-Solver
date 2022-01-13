#include<cmath>
#include<iostream>
#include<cmath>
#include"functions.h"
const double pi = 3.1415926535;
double sol[10] = {
    1,
    sin(pi),
    cos(pi),
    tan(pi),
    1/tan(0),
    1/cos(pi),
    1,
    log(pi),
    log10(pi),
    exp(pi)
};
double testx[10] = {
    1,
    pi,
    pi,
    pi,
    0,
    pi,
    1,
    pi,
    pi,
    pi,
};

int unittest()
{
    for (auto i = 0; i < 10;i++)
    {
        if (floor((eval(i, testx[i])))!=floor(sol[i]))
        {
            return 0; 
        }
    }
    return 1;
}