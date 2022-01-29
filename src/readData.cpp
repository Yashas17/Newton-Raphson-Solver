#include "include/readData.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

void readData(double &x0, double &tol, int &miter, equation &eq) {

  std::vector<double> p;       // Vector to store the powers
  std::vector<double> c;       // Vector to store the coefficients
  std::vector<unsigned int> f; // Vector to store the special functions

  std::ifstream data_file(
      "data.json", std::ifstream::binary); // File from which data is read
  nlohmann::json data;
  data_file >> data; // Reading data from the file

  assert((data["data"]["power"].size() == data["data"]["coefficient"].size()) &&
         (data["data"]["coefficient"].size() ==
          data["data"]["function"]
              .size())); // Ensuring that power, coefficient and
                         // function vectors are of same size

  x0 = data["data"]["guess solution"];
  tol = data["data"]["tolerance"];
  miter = data["data"]["max iterations"];

  assert(miter > 0);
  assert(tol > 0);

  std::cout << "\nGuess Solution = " << x0 << "\nMax Iterations = " << miter << "\nTolerance = " << tol
            << std::endl; // Printing x0, miter and tol on console

  for (auto a = 0; a < data["data"]["power"].size();
       a++) { // Constructing the three vectors for equation
    p.push_back(data["data"]["power"][a]);
    c.push_back(data["data"]["coefficient"][a]);

    assert(data["data"]["function"][a] >= 0 &&
           data["data"]["function"][a] <=
               9); // Ensuring the function value is within the bounds
    f.push_back(data["data"]["function"][a]);
  }
  eq = equation(p, c, f); // Initializing the equation with given vectors

  std::vector<std::string> functions{
      "1",        "sin(x)", "cos(x)",   "tan(x)", "cot(x)", "sec(x)",
      "cosec(x)", "log(x)", "log10(x)", "exp(x)"}; // Vector of strings of
                                                   // special function names
                                                   // used to print the equation
                                                   // read from data

  std::cout << "\nYou have entered the following equation:\n";
  for (auto a = 0; a < data["data"]["power"].size();
       a++) { // Printing the equation read from data file

    std::cout << data["data"]["coefficient"][a] << "*x^"
              << data["data"]["power"][a] << "*"
              << functions[data["data"]["function"][a]];
    if (a < data["data"]["power"].size() - 1)
      std::cout << "+";
  }
  std::cout << "\n";
}
