#include "matrix.h"
#include <cfloat>

namespace eigen {

  // constructor that takes in two integers for the dimensions of this matrix
  Matrix::Matrix(int r, int c) : columns {c} , rows {r} {
    //fills matrix with 0's
    m = std::vector<std::vector<double>>(r, std::vector<double>(c));
    if(isSquare()) {
      //construct identity matrix if it is a square matrix
      for(int i = 0; i < rows; ++i) {
        insert(i, i, 1);
      }
    }
  }

  Matrix::Matrix(int dimension) : Matrix(dimension, dimension){}

  //displays this matrix on the command line
  void Matrix::printOut() {
    std::cout << "Print out a " 
              << rows 
              << " x " 
              << columns  
              << " matrix." 
              << std::endl;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0 ; j < columns; ++j){
        std::cout << m[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }

  Matrix::Matrix(std::vector<std::vector<double>> target) {
    rows = target.size();
    columns = target[0].size();
    m = std::vector<std::vector<double>>(target);
  }

  /*
  Matrix::Matrix(Matrix target) : rows{target.getRows()}, columns{target.getColumns()} {
    for(int i = 0; i < rows; ++i) {
      m[i] = std::vector<double>(target);
    }
  }
  */
  
  //inserts a number into the matrix at a specified location
  void Matrix::insert(int row, int column, double value) {
    if(row >= rows || column >= columns) {
      return;
    }
    m[row][column] = value;
//    std::cout << "succesfully inserted " << value << " into row " << row << ", column " << column << std::endl;
  }

  //obtains a number from the matrix at a specified location
  double Matrix::getValue(int row, int column) {
    if(row >= rows || column >= columns) {
      return 0;
    }
    return m[row][column];
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
    if (!isSquare()) {
      return DBL_MIN;
    }
    if (getRows() == 1) {
      return getValue(0, 0);
    }
    double det = 0;
    for(int i = 0; i < columns; ++i) {
     
      //adding products of minor det and value to det
      if(i % 2 == 0) {
        det += (getValue(i, 0) * minorOf(i, 0).det());
      }
      else {
        det -= (getValue(i, 0) * minorOf(i, 0).det());
      }
    }
  }

  Matrix Matrix::minorOf(int row, int column) {
    std::vector<std::vector<double>> output(m);
    output.erase(output.begin() + row);
    for(int i = 0; i < rows-1; ++i) {
      output[i].erase(output[i].begin() + column);
    }
    return Matrix(output);
  }

  Matrix Matrix::operator*(Matrix& B) { Matrix product(rows, B.getColumns());
    for(int i = 0; i < product.getRows(); ++i) {
      for(int j = 0; j < product.getColumns(); ++j) {
        double value = 0; //what will get inserted into product
        //calculating a single value
        for(int k = 0; k < rows; ++k) {
          value += getValue(i, k) * B.getValue(k, j);
        }
        product.insert(i, j, value); 
      }
    }
    return product;
  }

  double Matrix::calculateEigenValue() {
    if(!isSquare()) {
      return DBL_MIN;
    }
    Matrix vector(1, rows);
    double epsilon = 1;
    while (epsilon > 0.001) {

    }
  }
} //namespace eigen
