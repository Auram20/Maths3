#include <iostream>
#include <Eigen/Dense>
#include <ctime>
// Pour compiler avec Eigen 
// g++ -Wall -O2 exercice4.cpp -I /usr/include/eigen3 -o exerice4.exe



Eigen::MatrixXf matrixProduct(const Eigen::MatrixXf &A, const Eigen::MatrixXf &B)
{
	assert(A.cols()==B.rows() && "error");

	Eigen::MatrixXf result = Eigen::MatrixXf::Zero(A.rows(), B.cols());

	
		for(unsigned int i=0;i<result.rows();i++)
		{
			for(unsigned int j=0;j<result.cols();j++)
			{
				for (unsigned int k=0;k<A.cols();k++)
				{
					result(i,j)+=A(i,k)*B(k,j);
				}
			}
		}

	return result;
	

}





int main()
{
	
  Eigen::MatrixXf A = Eigen::MatrixXf::Random(3,4);	
  Eigen::MatrixXf B = Eigen::MatrixXf::Random(4,4);	
  std::cout << " A x B : \n "<< matrixProduct(A,B) <<std::endl;
  std::cout << " vérification eigen : \n "<< (matrixProduct(A,B)-(A*B)).norm() <<std::endl;

  return 0;
}

