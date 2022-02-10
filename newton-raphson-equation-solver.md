# Project: Newton-Raphson Equation Solver

Idea contributed by Yashas Gandhi <y.gandhi@tum.de> and Pratik Rawal <p.rawal@tum.de>.

## Motivation

Very often we need to solve non-linear equations numerically, for which [Newton-Raphson](https://en.wikipedia.org/wiki/Newton's_method) is one of the widely used methods. Hence, we plan to develop a program to solve non-linear equations using Newton-Raphson method.

## Sprint 1

Implement a program for solving single variable polynomial equations. Define a function for differentiating the polynomial equation.

### Definition of "done"

- The project contains a comprehensive `README.md` file explaining how to use it, including an example.
- The program can solve a single variable polynomial equation.
- The program will take guess solution, tolerance and maximum number of iterations from user.
- The solver prints or returns the root of the equation.
- The project contains at least one unit test which compares one case with its analytical solution for correctness.

## Sprint 2
Implement class `equation` to define original and differentiated equations. The program can handle complex polynomial, trigonometric, exponential and logarithmic functions. Use class hierarchies to define the different kinds of functions.

### Definition of "done"

- The solver can handle complex functions of the form x^n*f(x), where n is any real number and f(x) is sin(x), cos(x), tan(x), sec(x), cosec(x), cot(x) e^x or log(x).
- The `README.md` file shall explain how to add new functionality to the program.
- The project contains unit tests for polynomial, trigonometric, exponential, and logarithmic functions.

## Sprint 3

In this sprint, the code performance will be evaluated and improved. Potential performance bottlenecks will be found (e.g. using a profiler such as gprof) and optimization options for the code will be implemented. This investigation will be based on topics covered in the lecture.

### Definition of "done"

- A file `performance.md` presents observations from the performance analysis.
- The same file presents different optimization techniques applied, with the performance effects observed.
- The final code includes the most optimized version of our code.
