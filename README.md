# Newton Raphson Solver (Group Z)
Project : Newton-Raphson Solver

Simple overview of use/purpose : [Newton-Raphson](https://en.wikipedia.org/wiki/Newton%27s_method) is a numerical method for solving equations. Here, in this sprint we focus on solving polynomial equations by implementing the newton-raphson algorithm. 

Description
Upon running the program, the user is asked to put the tolerance value : the minimum difference between two successive solutions, maximum number of iterations, so that the program doesn't run infinitely, and an initial guess solution.
Then depending upon the number of terms of in the equation, the equation is generated. Now, the polySolve function uses the polyDiff function to generate the differentiated equation and uses both the equations alongwith the previous solution (for the first iteration, this value would be the user-specified guess solution). The solver computes the solution and compares it with the previous solution. When the difference between the two is less than the user-specified tolerance, the solver returns the latest solution as the final solution. 

Getting Started
Dependencies
Basic C++ libraries
Cmake 
Describe any prerequisites, libraries, OS version, etc., needed before installing program.
ex. Windows 10
Installing 
Open a terminal in the build folder
Type "cmake .."
Type "cmake --build ."
This will generate a Newton-Raphson Solver
Executing program
The first prompt will be to enter a tolerance value, here the user can enter the value as '1e-X' or '0.xxxx1' as per his/her convinience. For eg, for a the tolerance value - 0.0001, the user can enter 1e-4 or 0.0001.
The next prompt is to enter the maximum the number of iterations allowed
The next prompt is to enter a guess solution. Here the user can enter any numerical value.
The next prompt is the number of terms in the equation. Here the user can enter any natural number.
Depending upon the number of terms, the user will be asked to enter the power and coefficient of each term. For eg if the user wants to enter equation - 'x^2-x-1'. It will done as follows. The user can view his equation.  
Now the polySolve function will run. It will take the differentiated equation from polyDiff and utilize both the equations and the preceding solution to generate a new solution. The solution with respect to this equation. 
It will continue to iterate until the maximum number of iterations is reached or the difference between two consecutive solutions falls below the user-specified tolerance. 
After the iterations are complete, it will present the solution, res, and the actual number of iterations taken to reach said solution. 
Help
Upon entering 'zero' as your guess solution or any value that makes the differentiated function 'zero' or extremely small value the second term in the algorithm will approach infinity leading to a non-numerical solution. In this case, re-run the code with a different guess solution
Any advise for common problems or issues.

command to run if program contains helper info
Authors
Contributors names and contact info

ex. Dominique Pizzie
ex. @DomPizzie

Version History
0.2
Various bug fixes and optimizations
See commit change or See release history
0.1
Initial Release
License
This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

Acknowledgments
Inspiration, code snippets, etc.

awesome-readme
PurpleBooth
dbader
zenorocha
fvcproductions
