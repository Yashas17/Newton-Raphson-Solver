#include<cmath>
#include<iostream>
#include<cmath>
#include"include/functions.h"

const double pi = 3.1415926535;

double sol[10] = {
    1,
    sin(pi/2),
    cos(0),
    tan(0),
    1/tan(0),
    1/cos(pi),
    1,
    log(pi),
    log10(pi),
    1
};

double testx[10] = {
    1,
    pi/2,
    0,
    0,
    0,
    pi,
    pi/2,
    pi,
    pi,
    0,
};

int unittest()
{
    for (auto i = 0; i < 10;i++)
    {
        if ((eval(i, testx[i]))!=sol[i])
        {
            return 0; 
        }
    }
    return 1;
}
