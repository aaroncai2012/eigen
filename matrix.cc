#include "matrix.h"

namespace eigen {

  Matrix::Matrix(int r, int c) {
    columns = c;
    r = rows;
    if (isSquare()) {
      for (int i = 0; i < rows; ++i) {
        std::vector<double> temp;
        for(int j = 0; j < columns; ++j) {
          //inserts a 1 if it is on a space on the diagonal line, and 0 otherwise.
          //this is to make an identity matrix of size r x c if r = c
          temp.emplace_back(i == j);
        }
        m.emplace_back(temp);
      }
    }
  }

  void Matrix::printOut() {
    std::cout << "Print out a " 
              << rows 
              << " x " 
              << columns  
              << " matrix." 
              << std::endl;
    for(int i = 0; i < rows; ++i) {
      for (int j = 0 ; j < columns; ++j){
        std::cout << m[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }

  void Matrix::insert(int row, int column, double value) {
    m[row][column] = value;
  }

  double Matrix::getValue(int row, int column) {
    return m[row][column];
  }

  bool Matrix::isSquare() {
    return (columns == rows);
  }

} //namespace eigen
