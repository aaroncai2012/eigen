#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>

namespace eigen {

class Matrix {

public:

  Matrix(int r, int c);
  Matrix(int dimension);
  Matrix(std::vector<std::vector<double>> target);
  void printOut();
  void insert(int row, int column, double value);
  double getValue(int row, int column);
  bool isSquare();
  int getRows();
  int getColumns();
  Matrix minorOf(int row, int column);
  double det();
  Matrix inverse();
  Matrix operator*(Matrix& B);
  Matrix rref();
  double calculateEigenValue();
  
private:

  std::vector<std::vector<double>> m;
  int columns;
  int rows;

};

} //namespace eigen

#endif //MATRIX_H_
