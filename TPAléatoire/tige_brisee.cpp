#include <iostream>
#include <random>
#include <chrono>
#include <functional> 

void tigeBrisee(){
	double compteur=0;
	

	for(int i=0; i<100000; ++i)
  	{
  	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	
  	std::default_random_engine generator(seed);
  	std::uniform_real_distribution<double> uniformRealDistribution(1,500);
    
    double x=uniformRealDistribution(generator);
	double y=500-x;
	double z=500-y+x;


		if(x<y+z && y<x+z && z<x+y)
		{
			compteur++;
		}

	}

	double proba = compteur/100000;
    std::cout << "Proba : " << proba << std::endl;

}

int main()
{
	for(int i=0; i<10; i++)
	{
		tigeBrisee();
	}
}