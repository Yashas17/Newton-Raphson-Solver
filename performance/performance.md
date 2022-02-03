# Performance Analysis

To analyse our code we used the **gprof** tool. However, our code had runtime in order of just a **few hundered microseconds**, which was out of scope for gprof. Thus, gprof was not very useful to analyse performance of our code. We could only get a rough idea of code performance seeing the number of function calls, as the time column was zero everywhere in gprof. We thus decided to use **std::chrono** to evaluate the runtime of our code manually. The original code without any optimizations took on an average **700 microseconds** to execute, out of which the eq.solve() function just took **48.4 microseconds** on an average. The runtime for 10 runs for eq.solve() is stored in _original.csv_ file. The other time was spent in reading the data from a configuration file. Since the data is read using an external library, we have only focused on improving runtime of eq.solve() function. We tried two different methods to optimize our code:

## Optimization 1
We changed the the definition of evalute() function of class equations from `std::array<double,2> evaluate(double x)` to `void evaluate(std::array<double,2> &temp, double x)`. This was suggested by one of the reviewers during sprint2 review. This change reduced the number of new array declarations and gave a significant runtime boost. After this change, the average runtime of eq.solve() dropped to 42 microseconds. This data is stored in _optimization1.csv_ file.

## Optimization 2
We were using seperate _for_ loops to calculate _temp[0]_ and _temp[1]_ in `evaluate()` function. This also resulted in an extra if-else branching as well. Merging calculation on _temp[0]_ and _temp[1]_ also boosted the runtime. The average runtime of eq.solve() came out to be 36.6 microseconds which is stored in _optimization2.csv_ file.

Original Code:

```
for (auto i = 0; i < _p.size(); i++) {
    if (_p[i] != 0) { // Power zero sometimes creates errors thus handling the
                      // case manually
      temp[0] += _c[i] * pow(x, _p[i]) * eval(_f[i], x);
    } else {
      temp[0] += _c[i] * eval(_f[i], x);
    }
  }
  temp[1] = 0; // Second element stores the value of derivative of equation
for (auto i = 0; i < _p.size(); i++) {
    if (_p[i] != 0) { // For power zero, x does not exist in the equation
                      // technically and thus this case is treated seperately
      temp[1] += _c[i] * pow(x, _p[i]) * evalDiff(_f[i], x) +
                 _c[i] * _p[i] * pow(x, _p[i] - 1) * eval(_f[i], x);
    } else {
      temp[1] += _c[i] * evalDiff(_f[i], x);
    }
}
```
Final Code:

```
for (auto i = 0; i < _p.size(); i++) {
    if (_p[i] != 0) {                           // Power zero sometimes creates errors thus handling the
                                                // case manually
      temp[0] += _c[i] * pow(x, _p[i]) * eval(_f[i], x);
      temp[1] += _c[i] * pow(x, _p[i]) * evalDiff(_f[i], x) +
                 _c[i] * _p[i] * pow(x, _p[i] - 1) * eval(_f[i], x);
    } else {
      temp[0] += _c[i] * eval(_f[i], x);
      temp[1] += _c[i] * evalDiff(_f[i], x);
    }
  }
```

## Compiler Optimization
After applying above optimizations, we set compiler flag **'-O3'** to let the compiler optimize our code automatically. We saw the runtime of eq.solve() improve to **33 microseconds**. However, a larger time gain was observed in reading data part. The total runtime of our code reduced to **400 microseconds** on average, while with **'O0'** optimization resulted in around **680 microseconds** on an average. The function calls made by the nlohmann json library functions reduced greatly as can be seen from the gprof data log. Interestingly, evalDiff() was called **105 times** in O3 optimized code but just **8 times** in O0 optimized code. The number of calls remained unchanged for eval() and evaluate() functions in O0 and O3 optimization. Yet we saw a minor runtime improvement in eq.solve() function.

Since we have a very short runtime, all this analysis cannot be taken at face value. Background processes can highly impact the runtime if it is very low. We logged data for each code 10 times and the large variation in runtime for same code is clearly visible. We would be happy to know if you have any suggestions to map performance of such a lightweight code accurately during sprint3 review.
