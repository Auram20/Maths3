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

  const unsigned int dimension=1000;		
  Eigen::MatrixXf A = Eigen::MatrixXf::Random(dimension,dimension);	
  Eigen::MatrixXf B = Eigen::MatrixXf::Random(dimension,dimension);

  clock_t begin = clock();	
  std::cout << " A x B : \n "<< matrixProduct(A,B) <<std::endl;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "temps calcul du produit matriciel: " <<tempsCalc <<"s " << std::endl;


  clock_t begin2 = clock();
  std::cout << " vérification eigen : \n "<< (matrixProduct(A,B)-(A*B)).norm() <<std::endl;
  clock_t end2 = clock();
  double tempsCalc2 = double(end2 - begin2) / CLOCKS_PER_SEC;
  std::cout << "temps calcul du produit eigen: " <<tempsCalc2 <<"s " << std::endl;
  

  return 0;
}

