#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double eval(const unsigned int f,
            const double x); // Function returning the value of special function
                             // at given point
double evalDiff(const unsigned int f,
                const double x); // Function returning the value of derivative
                                 // of special function at given point

#endif