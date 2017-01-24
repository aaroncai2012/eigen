#include "matrix.h"
#include <iostream>

int main () {

  std::cout << "reached main properly" << std::endl;
  eigen::Matrix* M = new eigen::Matrix(2, 2);
  std::cout << "created a matrix properly" << std::endl;
  return 0;

}
