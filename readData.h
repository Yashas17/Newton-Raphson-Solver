#include "equation.h"
#include "json.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

void readData(double &x0, double &tol, int &miter, equation &eq) {

  std::vector<double> p;
  std::vector<double> c;
  std::vector<unsigned int> f;

  std::ifstream data_file("data.json", std::ifstream::binary);
  nlohmann::json data;
  data_file >> data;

  assert((data["data"]["pw"].size() == data["data"]["cf"].size()) &&
         (data["data"]["cf"].size() == data["data"]["fn"].size()));

  x0 = data["data"]["x0"];
  tol = data["data"]["tol"];
  miter = data["data"]["miter"];

  assert(miter > 0);

  for (auto a = 0; a < data["data"]["pw"].size(); a++) {
    p.push_back(data["data"]["pw"][a]);
    c.push_back(data["data"]["cf"][a]);
    assert(data["data"]["fn"][a] >= 0 && data["data"]["fn"][a] <= 9);
    f.push_back(data["data"]["fn"][a]);
  }
  eq = equation(p, c, f);
}
