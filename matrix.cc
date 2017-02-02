#include <cfloat>
#include <cmath>

namespace eigen {

  // constructor that takes in two integers for the dimensions of this matrix
  template<class T>
  Matrix<T>::Matrix(int r, int c) : columns {c} , rows {r} {
    //fills matrix with 0's
    m = std::vector<std::vector<T>>(r, std::vector<T>(c));
    if(isSquare()) {
      //construct identity matrix if it is a square matrix
      for(int i = 0; i < rows; ++i) {
        insert(std::make_pair(i, i), 1);
      }
    }
  }

  template<class T>
  Matrix<T>::Matrix(std::pair<int, int> dimension)  : Matrix(dimension.first, dimension.second) {}
  template<class T>
  Matrix<T>::Matrix(int dimension) : Matrix(dimension, dimension){}

  //displays this matrix on the command line
  template<class T>
  void Matrix<T>::printOut() {
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

  template<class T>
  Matrix<T>::Matrix(std::vector<std::vector<T>> target) {
    rows = target.size();
    columns = target[0].size();
    m = std::vector<std::vector<T>>(target);
  }

  /*
  Matrix::Matrix(Matrix target) : rows{target.getRows()}, columns{target.getColumns()} {
    for(int i = 0; i < rows; ++i) {
      m[i] = std::vector<double>(target);
    }
  }
  */
  
  //inserts a number into the matrix at a specified location
  template<class T>
  void Matrix<T>::insert(std::pair<int, int> location, T value) {
    if(location.first >= rows || location.second >= columns) {
      return;
      std::cout << "attempted to insert value at invalid location" << std::endl;
    }
    m[location.first][location.second] = value;
//    std::cout << "succesfully inserted " << value << " into row " << row << ", column " << column << std::endl;
  }

  //obtains a number from the matrix at a specified location
  template<class T>
  T Matrix<T>::getValue(std::pair<int, int> location) {
    if(location.first >= rows || location.second >= columns) {
      return 0;
    }
    return m[location.first][location.second];
  }

  //a check for whether the matrix is a square or not
  template<class T>
  bool Matrix<T>::isSquare() {
    return (columns == rows);
  }

  //obtains the number of rows of this matrix
  template<class T>
  int Matrix<T>::getRows() {
    return rows;
  }
  
  //obtains the number of columns of this matrix
  template<class T>
  int Matrix<T>::getColumns() {
    return columns;
  }

  //calculates the determinate of this matrix if it is square
  template<class T>
  double Matrix<T>::det() {
    if (!isSquare()) {
      return DBL_MIN;
    }
    if (getRows() == 1) {
      return getValue(std::make_pair(0, 0));
    }
    double det = 0;
    for(int i = 0; i < columns; ++i) {
     
      //adding products of minor det and value to det
      if(i % 2 == 0) {
        det += (getValue(std::make_pair(i, 0)) * minorOf(std::make_pair(i, 0)).det());
      }
      else {
        det -= (getValue(std::make_pair(i, 0)) * minorOf(std::make_pair(i, 0)).det());
      }
    }
  }

  template<class T>
  Matrix<T> Matrix<T>::minorOf(std::pair<int, int> location) {
    std::vector<std::vector<T>> output(m);
    output.erase(output.begin() + location.first);
    for(int i = 0; i < rows-1; ++i) {
      output[i].erase(output[i].begin() + location.second);
    }
    return Matrix<T>(output);
  }

  template<class T>
  Matrix<T> Matrix<T>::operator*(Matrix& B) { Matrix product(rows, B.getColumns());
    for(int i = 0; i < product.getRows(); ++i) {
      for(int j = 0; j < product.getColumns(); ++j) {
        T value = 0; //what will get inserted into product
        //calculating a single value
        for(int k = 0; k < rows; ++k) {
          value += getValue(std::make_pair(i, k)) * B.getValue(std::make_pair(k, j));
        }
        product.insert(std::make_pair(i, j), value); 
      }
    }
    return product;
  }

  template<class T>
  double Matrix<T>::magnitude() {
    double value = 0;
    for(int i = 0; i < columns; ++i) {
      value += (getValue(make_pair(0, i)) * getValue(make_pair(0, i)));
    }
    return std::sqrt(value);
  }

  template<class T>
  double Matrix<T>::calculateEigenValue() {
    if(!isSquare()) {
      return DBL_MIN;
    }
    Matrix vector(1, rows);
    for(int i = 0; rows; ++i) {
      vector.insert(std::make_pair(0, i), 2);
    }
    double epsilon = 0.001;
    double previous = 0;
    int iterations = 0;
    do {

    iterations++;
    }while(false && iterations < 1000);
    
  }
} //namespace eigen
