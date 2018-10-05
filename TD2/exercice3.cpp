#include <iostream>
#include <Eigen/Dense>
#include <ctime>
// Pour compiler avec Eigen 
// g++ -Wall -O2 exercice3.cpp -I /usr/include/eigen3 -o exerice3.exe

float dotproduct(const Eigen::VectorXf &v1, const Eigen::VectorXf &v2)
{
	float dotprod=0.0;
	if(v1.size()==v2.size()){
		for(unsigned int i=0;i<v1.size();i++)
		{
			dotprod+=v1(i)*v2(i);
		}

	return dotprod;
	}
	return 0;
}



int main()
{
	
  const unsigned int dimension=8;
  Eigen::VectorXf v1=Eigen::VectorXf::Random(dimension);
  Eigen::VectorXf v2=Eigen::VectorXf::Random(dimension);

  std::cout << " A scalaire B : \n "<< dotproduct(v1,v2) <<std::endl;
  std::cout << " vérification : \n "<< v1.dot(v2) <<std::endl;

  return 0;
}

