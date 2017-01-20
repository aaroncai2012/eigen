#include "matrix.h"

namespace eigen {

  Matrix(int r, int c) {
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

} //namespace eigen
