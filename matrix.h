#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>

namespace eigen {

template <class T>
class Matrix {

public:

  Matrix(int r, int c);
  Matrix(int dimension);
  Matrix(std::vector<std::vector<T>> target);
  Matrix(std::pair<int, int> dimension);
  void printOut();
  void insert(std::pair<int, int> location, T value);
  T getValue(std::pair<int, int> location);
  bool isSquare();
  int getRows();
  int getColumns();
  std::pair<int, int> getDimension();
  Matrix<T> transpose();
  Matrix<T> minorOf(std::pair<int, int> location);
  double det();
  Matrix<T> inverse();
  Matrix<T> operator*(Matrix<T>& B);
  Matrix<T> operator*(double num);
  Matrix<T> operator/ (Matrix<T> B);
  Matrix<T> operator/ (double num);
  Matrix<T> rref();
  Matrix<T> calculateEigenvector(Matrix<T> b0);
  double calculateEigenValue();
  double magnitude();
  
private:

  std::vector<std::vector<T>> m;
  int columns;
  int rows;

};

} //namespace eigen

#include "matrix.cc"

#endif //MATRIX_H_
