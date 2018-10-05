#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdlib>



int multi(int a, int b)
{
	int residu=0;
// a toujours plus petit que b 
	if (a<0 && b<0)
	{
		a=-a;
		b=-b;
	}
	if (b>a)
	{
		int c;
		c=b;
		b=a;
		a=c;
	}


while (a>1)
{
	// Si a est impair
	if (a%2==1)
	{
		residu+=b;
	}
		b=b<<1;
		a=a>>1;
}

return b+residu;

}


int main()
{
	int resultat=multi(2,-32);
	std::cout << "Votre résultat: " << resultat << std::endl;
	return 1;
}