#ifndef READ_DATA_H
#define READ_DATA_H

#include "equation.h"
#include "json.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

void readData(double &x0, double &tol, int &miter, equation &eq);

#endif