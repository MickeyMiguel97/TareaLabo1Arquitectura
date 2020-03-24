#include <iostream>
#include "math_tools.h"
#include "display_tools.h"

int main() {

  Matrix example_matrix, invers_matrix;

  zeroes(example_matrix, 3);
  //zeroes(invers_matrix, 3);
  cout << endl;
  cout << "Matriz Original";
  cout << endl;
  example_matrix.at(0).at(0) = 2;
  example_matrix.at(0).at(1) = 2;
  example_matrix.at(0).at(2) = 3;
  example_matrix.at(1).at(0) = 4;
  example_matrix.at(1).at(1) = 5;
  example_matrix.at(1).at(2) = 6;
  example_matrix.at(2).at(0) = 7;
  example_matrix.at(2).at(1) = 8;
  example_matrix.at(2).at(2) = 9;

  showMatrix(example_matrix);

  cout << endl;
  cout << "Matriz Inversa";
  cout << endl;
  inversaMatrix(example_matrix, invers_matrix);

  showMatrix(invers_matrix);
  cout << endl;
}