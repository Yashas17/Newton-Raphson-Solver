#include<cmath>
#include<iostream>
#include<math.h>
#include"include/functions.h"

const double pi_val = 3.1415926535;
int flag2 = 1;
double solDiff[10] = {
    0,
    cos(pi_val),
    -sin(pi_val/2),
    1. / (cos(pi_val) * cos(pi_val)),
    -1. / (sin(pi_val/2) * sin(pi_val/2)),
    tan(0) / cos(0),
    -1. / (sin(0) * tan(0)),
    1,
    0,
    exp(0)
};
double test[10] = {
    1,
    pi_val,
    pi_val/2,
    pi_val,
    pi_val/2,
    0,
    0,
    1,
    INFINITY,
    0,
};
int unittestDiff()
{
        for (auto i = 0; i < 10;i++)
    {
        if (evalDiff(i, test[i])!=solDiff[i])
        {
            return 0;
        }
    }
    return 1;
}
