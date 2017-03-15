#include "matrix.h"
#include <iostream>

int main () {

  std::cout << "reached main properly" << std::endl;
  std::vector<std::vector<double>> MData = {{2, -12}, {1, -5}};
  eigen::Matrix<double> M(MData);
  M.printOut();

  std::vector<std::vector<double>> b0Data = {{1}, {1}};
  eigen::Matrix<double> b0(b0Data);
  eigen::Matrix<double> M1(M.calculateEigenvector(b0));


//  eigen::Matrix<double> minor(eigen::Matrix<double> & M.minorOf(std::make_pair(0, 0)));
  
  M1.printOut();
//  std::cout << M.det() << std::endl;
  return 0;
}
