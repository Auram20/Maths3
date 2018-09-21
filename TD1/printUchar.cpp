
#include <iostream>
#include <cstdlib>
#include <math.h> 
#include <bitset>

/* Exercice 01 - Rappels sur les entiers
01011 : (11) en base 10
10110 : (22) en base 10

01010+10011=11101 en base 10 : 10 + 19 = 29
01011+10110=100001 en base 10 11+22=33 

*/ 

/*
void printUchar(const unsigned char x)
{
	std::string binaire="";
	int reste=x;

	for(int i=7;i>=0;i--)
 	{
 		if((reste/(pow(2,i))<1))
 		{
 			binaire += "0";
 		}	
 		else
 		{
 			binaire+="1";
 			reste=x%int(pow(2,i));
 		}
	}


	std::cout << (int)x << " : " << binaire;
	std::cout << std::endl;
}
*/

void printUchar(const unsigned char x)
{

	std::cout << (int)x << ":";
	for (int i=7; i>=0; i--){
		std::cout << (x>>i & 1);
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " nb" << std::endl;
		return 0;
	}
	printUchar(atoi(argv[1]));

	return 1;
}