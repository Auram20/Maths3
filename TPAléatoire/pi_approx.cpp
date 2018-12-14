
#include <iostream>
#include <random>
#include <chrono>
#include <functional> 


void approxpi(float cote)
{
  
	double compteur = 0;
  //int compteur;

  //std::cout << "min : " << mt64Generator.min() << std::endl;
  //std::cout << "max : " << mt64Generator.max() << std::endl;
  
  for(int i=0; i<100000; ++i)
  	{
  	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	
  	std::default_random_engine generator(seed);
  	std::uniform_real_distribution<float> uniformRealDistribution(0,cote);
    
    double x=uniformRealDistribution(generator);
	double y=uniformRealDistribution(generator);

	if(x*x+y*y<=cote*cote)
		compteur++;
	}

	double probacercle = compteur/100000;
	double probacarre = (100000-compteur)/100000;

    std::cout << "Proba dans le cercle : " << probacercle << std::endl;
    std::cout << "Proba dans le carré : " << probacarre << std::endl;
    std::cout << "Pi : " << probacercle*4 << std::endl;

    



	
}




int main()
{
	for(int i=0; i<10; i++){
		approxpi(2);

	}
}

/*std::cout << std::endl << "uniform real distribution (1,6)" << std::endl;
std::uniform_real_distribution<float> uniformRealDistribution(1,6);
for(int i=0; i<10; ++i)
std::cout << uniformRealDistribution(generator) << " ";
std::cout << std::endl;*/