#include <vector>
#include "math.h"
using namespace std;

typedef vector<float> Vector; //Un vector
typedef vector<Vector> Matrix; //vector de vectores o sea matriz

void zeroes(Vector &v, int n){
  for(int i=0; i<n; i++){
    v.push_back(0.0);
  }
}

void zeroes(Matrix &M, int n){
  for(int i=0; i<n; i++){
    Vector row(n,0.0);
    M.push_back(row);
  }
}

void copyMatrix(Matrix A, Matrix &copy){
  zeroes(copy, A.size());
  for(int i=0; i<A.size(); i++){
    for(int j=0; j<A.size(); j++){
      copy.at(i).at(j) = A.at(i).at(j);
    }
  }
}

void productRealMatrix(float real, Matrix M, Matrix &R){
  zeroes(R, M.size());
  for(int i=0; i<M.size(); i++){
    for(int j=0;j<M.at(0).size(); j++){
      R.at(i).at(j)= real * M.at(i).at(j);
    }
  }
}

void transpose(Matrix M, Matrix &T){
  zeroes(T, M.size());
  for(int i=0; i<M.size(); i++){
    for(int j=0; j<M.at(0).size(); j++){
      T.at(j).at(i) = M.at(i).at(j);    }
  }
}

void getMinor(Matrix &M, int i, int j){
  M.erase(M.begin()+i);
  for(int i=0; i<M.size(); i++){
    M.at(i).erase(M.at(i).begin()+j);
  }

}

float determinant(Matrix M){
  if(M.size() == 1){
    return M.at(0).at(0);
  }else{
    float det = 0.0;
    for(int i=0;i<M.at(0).size(); i++){
      Matrix minor;
      copyMatrix(M, minor);
      getMinor(minor,0,i);
      det += pow(-1,i) * M.at(0).at(i) * determinant(minor);
    }
    return det;
  }
}

void cofactors(Matrix M, Matrix &Cof){
    zeroes(Cof,M.size());
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void inversaMatrix(Matrix M, Matrix &Inv){
  if(determinant(M) == 0){

    exit (EXIT_FAILURE);

  }else{

    Matrix cofactorss;
    cofactors(M, cofactorss);

    Matrix trancof;
    transpose(cofactorss, trancof);

    Matrix inversafinal;
    float det = determinant(M);
    float dett = (1/det);

    productRealMatrix(dett, trancof, inversafinal);
    
    copyMatrix(inversafinal, Inv);
  }
}