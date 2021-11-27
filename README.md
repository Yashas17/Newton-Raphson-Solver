# Newton Raphson Solver (Group Z)
Project : Newton-Raphson Solver
[Newton-Raphson](https://en.wikipedia.org/wiki/Newton%27s_method) is a numerical method for solving equations. Here, in this sprint we focus on solving polynomial equations by implementing the newton-raphson algorithm. 

**Description**
Upon running the program, the user is asked to enter the following,

- The tolerance value : the minimum difference between two successive solutions.
- Maximum number of iterations, so that the program doesn't run infinitely. 
- An initial guess solution.

Then depending upon the number of terms of in the equation, the equation is generated. Now, the _polySolve_ function uses the _polyDiff_ function to generate the differentiated equation and uses both the equations alongwith the previous solution (for the first iteration, this value would be the user-specified guess solution). The solver computes the solution and compares it with the previous solution. When the difference between the two is less than the user-specified tolerance, the solver returns the latest solution as the final solution. 

**Dependencies:**

- Basic C++ libraries
- Cmake 

**Installing **

- Open a terminal in the build folder
- Type "cmake .."
- Type "cmake --build ."

This will generate a Newton-Raphson Solver

**Executing program:**

The first prompt will be to enter a tolerance value, here the user can enter the value as '1e-X' or '0.xxxx1' as per his/her convinience. For eg, for a the tolerance value - '0.0001', the user can enter '1e-4' or '0.0001'.

`Enter the tolerance:1e-4`

The next prompt is to enter the maximum the number of iterations allowed

`Enter maximum number of iterations:100`

The next prompt is to enter a guess solution. Here the user can enter any numerical value.

`Enter guess solution:1`

The next prompt is the number of terms in the equation. Here the user can enter any natural number.

`Enter the number of terms in the polynomial equation: 3`

Depending upon the number of terms, the user will be asked to enter the power and coefficient of each term. For eg. if the user wants to enter equation - 'x^2-x-1'. It will done as follows. 

`Enter the power of term 1:      2`

`Enter coefficient of term 1:    1`

`Enter the power of term 2:      1`

`Enter coefficient of term 2:    -1`

`Enter the power of term 3:      0`

`Enter coefficient of term 3:    -1`

The user can view his equation.  

`The polynomial is: 1x^2 + -1x^1 + -1x^0 `

Now the _polySolve_ function will run. It will take the differentiated equation from _polyDiff_ and utilize both the equations and the preceding solution to generate the next solution as per this equation. 

![alt text](https://web.mit.edu/10.001/Web/Course_Notes/NLAE/equation6.gif)

It will continue to iterate until the maximum number of iterations is reached or the difference between two consecutive solutions falls below the user-specified tolerance. 

After the iterations are complete, it will present the solution, res, and the actual number of iterations taken to reach said solution. 

`The solution is:1.61803`
`The number of iterations is:5`
`Residual is:4.59072e-007`


**Help**

Upon entering 'zero' as your guess solution or any value that makes the differentiated function 'zero' or extremely small value the second term in the algorithm will approach infinity leading to a non-numerical solution. In this case, re-run the code with a different guess solution

**Authors**

@pratikrawal333

@00000000014ADF47
