#include "matrix.h"

namespace eigen {

  // constructor that takes in two integers for the dimensions of this matrix
  Matrix::Matrix(int r, int c) {
    columns = c;
    rows = r;
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

  //displays this matrix on the command line
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

  //inserts a number into the matrix at a specified location
  void Matrix::insert(int row, int column, double value) {
    if(row > rows || column > columns) {
      return;
    }
    m[row-1][column-1] = value;
    std::cout << "succesfully inserted " << value << " into row " << row << ", column " << column << std::endl;
  }

  //obtains a number from the matrix at a specified location
  double Matrix::getValue(int row, int column) {
    if (row > rows || column > columns) {
      return 0;
    }
    return m[row-1][column-1];
  }

  //a check for whether the matrix is a square or not
  bool Matrix::isSquare() {
    return (columns == rows);
  }

  //obtains the number of rows of this matrix
  int Matrix::getRows() {
    return rows;
  }
  
  //obtains the number of columns of this matrix
  int Matrix::getColumns() {
    return columns;
  }

  //calculates the determinate of this matrix if it is square
  double Matrix::det() {
    if (isSquare()) {
      return 0;
    }

  }
} //namespace eigen
