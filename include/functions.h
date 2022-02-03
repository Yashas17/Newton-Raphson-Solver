#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/**These are the functions responsible for returning the value of the special
** function and its derivative at any particular value of x
**/

double eval(const unsigned int f,
            const double x);                // Function returning the value of special function
                                            // at given point
double evalDiff(const unsigned int f,
                const double x);            // Function returning the value of derivative
                                            // of special function at given point

#endif
