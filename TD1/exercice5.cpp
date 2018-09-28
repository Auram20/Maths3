/*

À la place d'écrire : 
float a= ...;
float b= ...;
if (a==b) ... ; 
On écrit plutot : 
if (|a-b|<Epsilon) ...; 


*/

/*
int a = ... ; 
float b=a/3; 

On caste le 3 en float. Le programme considère automatiquement que a/3 est un float. 
On écrit : 
float b=a/3.0f; 

*/

/* 
float a = -5.0/0;
std::cout << " a " << a << std::endl;

Ça compile mais ça affichera -inf 
*/

/*
float a = powf(2.0,40);
std::cout << " a = " << a << std::endl;
int b = a;
std::cout << " b = " << b << std::endl;


*/



/*
for(float a=0.0; a<100000000; a+=0.00000001)
... ;
std::cout << " `a table ! " << std::endl;

Au début ça marche, à un moment, a sera suffisamment grand pour que +0.00000001 ne change rien
*/