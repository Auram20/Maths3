#include <iostream>
#include <Eigen/Eigenvalues>

#include "ioEigen.hpp"

using namespace Eigen;


void hints(void){

  MatrixXd M;
  
  // compute the column wize mean of a data matrix
  VectorXd mean =  M.colwise().sum() / (double) M.rows(); 
  
  // some hints to center some data (with the exterior product)
  std::cout << VectorXd::Ones(M.rows())*mean.transpose() << std::endl;

  // compute some eigen vectors
  SelfAdjointEigenSolver<MatrixXd> eigensolver(M);
  std::cout << "\neigenvectors of M \n" << eigensolver.eigenvectors().rowwise().reverse() << std::endl;
  std::cout << "\neigenvalues of M : " << eigensolver.eigenvalues().colwise().reverse().transpose() << std::endl;
  
  // extract some rows or columns from a matrix
  std::cout << M.leftCols(3) << std::endl; 
  std::cout << M.topRows(3) << std::endl; 
	
}



int main(int argc, char **argv)
{
  if(argc != 2){
    std::cerr << "usage : " << argv[0] << " data.mat" << std::endl;
    exit(0);
  }
  
  // load the data
  MatrixXd A;
  loadMatrix(A,argv[1]);
  std::cout << "A\n" << A << std::endl;

  // mean of the data
  // ...
  VectorXd mean=A.colwise().sum()/ (double) A.rows();
  std::cout << "mean\n" << mean << std::endl;

  // center the data
  // ...
  MatrixXd Acentered = A - VectorXd::Ones(A.rows()) * mean.transpose();
  std::cout << "\ncenter\n" << Acentered << std::endl;

  //scale ?
  MatrixXd scale = MatrixXd::Zero(A.cols(), A.cols());
  scale.diagonal() = Acentered.cwiseAbs().colwise().sum()/(double) Acentered.rows();
  scale = scale.inverse();
  MatrixXd Anormalized = Acentered * scale;

  // normalize the data
  // ...

  // build the covariance matrix 
  // ...
  MatrixXd cov = Anormalized.transpose() * Anormalized/(Anormalized.rows()-1);
  SelfAdjointEigenSolver<MatrixXd> eigensolver(cov);

  // compute the eigen vectors
  // ...
  std::cout << eigensolver.eigenvectors().rowwise().reverse() << std::endl;
  std::cout << eigensolver.eigenvectors().colwise().reverse().transpose() << std::endl;

  int dimension = 3;
  MatrixXd T = eigensolver.eigenvectors().rowwise().reverse().leftCols(dimension);
  MatrixXd Afinal=Anormalized*T;
  //test
  VectorXd x(A.cols());
  x << 1,1,1,10,0.5;
  VectorXd xProj = (T.transpose() * scale * (x-mean)).transpose();
  VectorXd distance = (Afinal - VectorXd::Ones(Afinal.rows())*xProj.transpose()).rowwise().norm();

  std::cout << "distance" << distance <<std::endl;

  // keep only n dimensions
  // ...
  
  // project the data
  // ...
  
  // project a new vector (remind to center and scale this vector)
  // ...

  return 0;
}
