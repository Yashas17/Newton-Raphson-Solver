#ifndef READ_DATA_H
#define READ_DATA_H

/**
Here we define the function that is responsible to read the values from json data file and assign the value 
to respective variables
*/
#include "equation.h"
#include "json.hpp"

void readData(double &x0, double &tol, int &miter, equation &eq);

#endif
