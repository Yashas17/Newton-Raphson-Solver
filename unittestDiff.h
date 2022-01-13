#include<cmath>
#include<iostream>
#include<math.h>
#include"functions.h"
const double pi_val = 3.1415926535;
int flag2 = 1;
double solDiff[10] = {
    0,
    cos(pi_val),
    -sin(pi_val),
    1. / (cos(pi_val) * cos(pi_val)),
    -1. / (sin(pi_val/2) * sin(pi_val/2)),
    tan(pi_val) / cos(pi_val),
    -1. / (sin(pi_val/4) * tan(pi_val/4)),
    1. / pi_val,
    1. / (pi_val * log(10.)),
    exp(pi_val)
};
double test[10] = {
    1,
    pi_val,
    pi_val,
    pi_val,
    pi_val/2,
    0,
    pi_val/4,
    pi_val,
    pi_val,
    pi_val,
};
int unittestDiff()
{
        for (auto i = 0; i < 10;i++)
    {
        if (floor(evalDiff(i, test[i]))!=floor(solDiff[i]))
        {
            return 0;
        }
    }
    return 1;
}