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


Eigen::MatrixXf matrixProductStrassen(const Eigen::MatrixXf &m1, const Eigen::MatrixXf &m2, const int minimalRecSize) {
  if (m1.rows() <= minimalRecSize)
    return m1 * m2;

  const unsigned int rows = m1.rows() / 2;
  const unsigned int cols = m1.cols() / 2;

  Eigen::MatrixXf result = Eigen::MatrixXf::Zero(m1.rows(), m2.cols());

  Eigen::MatrixXf a = m1.topLeftCorner(rows, cols);
  Eigen::MatrixXf b = m1.topRightCorner(rows, cols);
  Eigen::MatrixXf c = m1.bottomLeftCorner(rows, cols);
  Eigen::MatrixXf d = m1.bottomRightCorner(rows, cols);

  Eigen::MatrixXf e = m2.topLeftCorner(rows, cols);
  Eigen::MatrixXf f = m2.topRightCorner(rows, cols);
  Eigen::MatrixXf g = m2.bottomLeftCorner(rows, cols);
  Eigen::MatrixXf h = m2.bottomRightCorner(rows, cols);

  Eigen::MatrixXf P1 = matrixProductStrassen(a, (f - h), minimalRecSize);
  Eigen::MatrixXf P2 = matrixProductStrassen((a + b), h, minimalRecSize);
  Eigen::MatrixXf P3 = matrixProductStrassen((c + d), e, minimalRecSize);
  Eigen::MatrixXf P4 = matrixProductStrassen(d, (g - e), minimalRecSize);
  Eigen::MatrixXf P5 = matrixProductStrassen((a + d), (e + h), minimalRecSize);
  Eigen::MatrixXf P6 = matrixProductStrassen((b - d), (g + h), minimalRecSize);
  Eigen::MatrixXf P7 = matrixProductStrassen((a - c), (e + f), minimalRecSize);

  result.topLeftCorner(rows, cols) = P5 + P4 - P2 + P6;
  result.topRightCorner(rows, cols) = P1 + P2;
  result.bottomLeftCorner(rows, cols) = P3 + P4;
  result.bottomRightCorner(rows, cols) = P1 + P5 - P3 - P7;

  return result;
}



int main()
{

  const unsigned int dimension=1024;	
  Eigen::MatrixXf A = Eigen::MatrixXf::Random(dimension,dimension);	
  Eigen::MatrixXf B = Eigen::MatrixXf::Random(dimension,dimension);

  clock_t begin = clock();	
  std::cout << " A x B Strassen : \n "<< matrixProductStrassen(A,B,3) <<std::endl;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "temps calcul du produit matriciel par strassen: " <<tempsCalc <<"s " << std::endl;


  clock_t begin2 = clock();
  std::cout << "vérification strassen - produit mat normal : \n "<< (matrixProductStrassen(A,B,3)-matrixProduct(A,B)).norm() <<std::endl;
  clock_t end2 = clock();
  double tempsCalc2 = double(end2 - begin2) / CLOCKS_PER_SEC;
  std::cout << "temps calcul du produit eigen: " <<tempsCalc2 <<"s " << std::endl;
  

  return 0;
}

