# Newton Raphson Solver (Group Z)

[Newton-Raphson](https://en.wikipedia.org/wiki/Newton%27s_method) is a numerical method for solving equations. This program can solve single variable polynomial equations using Newton-Raphson method. 

## Installation

Clone the project on your computer. Open a terminal in the `build` directory and run the following commands:
>`cmake ..`  
>`cmake --build .`

This will generate the executable file in the build folder named `newton-raphson`.

## Usage Guidelines

Upon running the program, the user is asked to enter the following parameters:

- The tolerance value
- Maximum number of iterations 
- A guess solution

The program then gets the number of terms of the polynomial equation and the coeffients and powers of each term. The choice of guess solution is very important as it affects the convergence and also the result. The farther the guess solution is from root, the more number of iterations it will take to converge. In case the equtaion has multiple roots, the solver converges to the root nearest to the guess solution.

**Important Note:** Sometimes the value of the differentiated function can become very small or zero, which can lead to huge error or `nan` (not a number) solution. In such cases, the program will throw a warning and user is should modify the guess solution to get more accurate results.

## Example

We solve the polynomial equation `x^2-x-1` using the program. The equation has two roots `-0.61803` and `1.61803`. `1.61803` is known as [Golden Ratio] (https://en.wikipedia.org/wiki/Golden_ratio).

The user will be first prompted to enter a tolerance value. Here, the user can enter the value as '1e-X' or '0.xxxx1' as per their convenience. For example, for a the tolerance value of `0.0001`, the user can enter either `1e-4` or `0.0001`. Following is the first prompt.

`Enter the tolerance:1e-4`

The next prompt is to enter the maximum the number of iterations allowed.

`Enter maximum number of iterations:100`

The next prompt is to enter a guess solution. Here the user can enter any numerical value.

`Enter guess solution:1`

The next prompt is the number of terms in the equation. Here the user can enter any positive number.

`Enter the number of terms in the polynomial equation: 3`

Depending upon the number of terms, the user will be asked to enter the power and coefficient of each term. For eg. if the user wants to enter equation - `x^2-x-1`, it will done as follows: 

`Enter the power of term 1:      2`

`Enter coefficient of term 1:    1`

`Enter the power of term 2:      1`

`Enter coefficient of term 2:    -1`

`Enter the power of term 3:      0`

`Enter coefficient of term 3:    -1`

The program will then print the equation:

`The polynomial is: 1x^2 + -1x^1 + -1x^0 `

Now the _polySolve_ function will run. It will take the differentiated equation [f'(x)] from _polyDiff_ and the original equation [f(x)] and utilize both the equations and the latest solution [x(n)] to generate the next solution [x(n+1)] as per this equation. 

![alt text](https://web.mit.edu/10.001/Web/Course_Notes/NLAE/equation6.gif)

It will continue to iterate until the maximum number of iterations is reached or the difference between two consecutive solutions falls below the user-specified tolerance. After the iterations are complete, it will present the _solution_, the number of iterations, and the residual. 

`The solution is:1.61803`

`The number of iterations is:5`

`Residual is:4.59072e-007`

## Authors

@pratikrawal333

@00000000014ADF47
