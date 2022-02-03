#Performance Analysis

To analyse our code we used gprof tool. However, our code had runtime in order of hundered microseconds, which was out of scope for gprof. Thus, gprof was not very useful to analyse performance of our code. We code only get a rough idea seeing the number of function calls, as the time column was zero everywhere in gprof. We thus decided to use std::chrono to evaluate the runtime of our code manualy. The original code without any optimizations took on an average 700 microseconds to execute, out of which the solve() function of class equation just took 48.4 microseconds on an average. The runtime for 10 runs for eq.solve() is stored in _original.csv_ file. The other time was spent in reading the data from a configuration file. We tried two different methods to optimize our code:

##Optimization 1
We changed the the definition of evalute() function of class equations from `std::array<double,2> evaluate(double x)` to `void evaluate(std::array<double,2> &temp, double x)`. This was suggested by one of the reviewers during sprint2 review. After this change, the average runtime of eq.solve() dropped to 42 microseconds. This data is stored in _optimization1.csv_ file.

##Optimization 2
We were using seperate for loops to calculate temp[0] and temp[1] in evaluate() function. This also resulted in an extra if-else branching as well. Merging calculation on temp[0] and temp[1] also boosted the runtime. The average runtime of eq.solve() came out to be 36.6 microseconds which is stored in _optimization2.csv_ file.

##Compiler Optimization
After applying above optimizations, we set compiler flag '-O3' to let the compiler optimize our code automatically. We saw the runtime of eq.solve() improve to 33 microseconds. However, a larger time gain was observed in reading data part. The total runtime of our code just reduced to 400 microseconds on average. We also tested our code with 'O0' optimization which resulted in around 680 microsecondson an average. The function calls made by the nlohmann json library functions reduced greatly as can be seen from the gprof data log. Interestingly, evalDiff() was called 105 times in O3 optimized code but just 8 times in O0 optimized code. The number of calls remained unchanged for eval() and evaluate() functions in O0 and O3 optimization. 
