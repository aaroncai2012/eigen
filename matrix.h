#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>

namespace eigen {
class Matrix {

public:

  Matrix(int r, int c);
  void printOut();
  void insert(int row, int column, double value);
  double getValue(int row, int column);
  bool isSquare();
  double det();
  Matrix inverse();
  Matrix rref();
  
private:

  std::vector<std::vector<double> > m;
  int columns;
  int rows;

};

} //namespace eigen

#endif //MATRIX_H_
